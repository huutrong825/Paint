#include "graphics.h"
#pragma comment(lib, "graphics.lib")
#include <math.h>
#include <fstream>
#include <iostream>

#define color WHITE

#define Round(a) (int) (a+0.5)
#include <queue>

float x =150, y=150;

float x2 = x + 100, y2 = y;

using namespace std;

float goc = 360;
const int sodiem = 360/goc;
 

struct ToaDo
{
	int x, y;
};
struct Point {
	int x, y;
};
Point v[36];
void put8pixel(int xc, int yc, int x, int y)
{
	putpixel(x + xc, y + yc, color);
	putpixel(-x + xc, y + yc, color);
	putpixel(x + xc, -y + yc, color);
	putpixel(-x + xc, -y + yc, color);
	putpixel(y + xc, x + yc, color);
	putpixel(-y + xc, x + yc, color);
	putpixel(y + xc, -x + yc, color);
	putpixel(-y + xc, -x + yc, color);
}
void MidPoint(int xc, int yc, int r)
{
		int x = 0;
		int y = r;
		float p = (5 / 4) - r;
		put8pixel(xc, yc, x, y);
		while (x <= y)
		{
			if (p < 0)
				p += (2 * x) + 3;
			else
			{
				p += (2 * (x - y)) + 5;
				y--;
			}
			x++;
			put8pixel(xc, yc, x, y);
			cout << x <<" "<< y<<"\n";
		}
		
}
void Bresenham(int xc, int yc, int r)
{
	int x = 0, y = r;
	int p = 3 - 2 * r;
	while (x <= y)
	{
		put8pixel(xc, yc, x, y);
		if (p < 0)
			p += 4 * x + 6;
		else
		{
			p += 4 * (x - y) + 10;
			y--;
		}
		x++;
		put8pixel(xc, yc, x, y);
	}
}

void lineDDA(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1, dy = y2 - y1;
	float x_inc, y_inc;
	float step = max(abs(dx), abs(dy));
	x_inc = dx / step;
	y_inc = dy / step;
	float x = x1, y = y1;
	putpixel(x, y, color);
	int k = 1;
	while (k <= step) {
		k++;
		x += x_inc;
		y += y_inc;
		putpixel(Round(x), Round(y), color);
	}
}

void bsline(int x1,int y1, int x2, int y2)
{
	int dx,dy,p;
	dx=x2-x1;
	dy=y2-y1;
	p=2*dy-dx;
	while (x1<=x2)
	{
		if (p<0)
		{
			y1=y1;
			p=p+2*dy;
		}
		else
		{
			y1=y1+1;
			p=p+2*(dy-dx);
		}
		x1++;
		putpixel(x1,x2,WHITE);

	}
}

void lineBresenham(int x1, int y1, int x2, int y2) //Vẽ bằng Bresenham
{
	// Bộ lặp, bộ đếm theo yêu cầu của thuật toán
	int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
	// Tính toán delta 
	dx = x2 - x1;
	dy = y2 - y1;
	// Tạo một bản sao của các delta (làm cho việc lặp lại dễ dàng hơn)
	dx1 = abs(dx);
	dy1 = abs(dy);
	// Tính toán khoảng lỗi cho cả hai trục
	px = 2 * dy1 - dx1;
	py = 2 * dx1 - dy1;
	// Đường có trục X chiếm ưu thế
	if (dy1 <= dx1) {
		// Đường được vẽ từ trái sang phải
		if (dx >= 0) {
			x = x1; y = y1; xe = x2;
		}
		else { // Đường thẳng được vẽ từ phải sang trái (hoán đổi kết thúc)
			x = x2; y = y2; xe = x1;
		}
		putpixel(x, y, color); // Vẽ pixel đầu tiên
		// Rasterize dòng
		for (i = 0; x < xe; i++) {
			x = x + 1;
			// Đối phó với các bát phân ...
			if (px < 0) {
				px = px + 2 * dy1;
			}
			else {
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
					y = y + 1;
				}
				else {
					y = y - 1;
				}
				px = px + 2 * (dy1 - dx1);
			}
			// Vẽ pixel từ khoảng dòng tại
			// vị trí hiện tại
			putpixel(x, y, color);
		}
	}
	else { // Đường có trục Y chiếm ưu thế
	 // Dòng được vẽ từ dưới lên trên
		if (dy >= 0) {
			x = x1; y = y1; ye = y2;
		}
		else { // Đường kẻ được vẽ từ trên xuống dưới
			x = x2; y = y2; ye = y1;
		}
		putpixel(x, y, color); // Vẽ pixel đầu tiên
		// Rasterize dòng
		for (i = 0; y < ye; i++) {
			y = y + 1;
			// Đối phó với các bát phân ...
			if (py <= 0) {
				py = py + 2 * dx1;
			}
			else {
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
					x = x + 1;
				}
				else {
					x = x - 1;
				}
				py = py + 2 * (dx1 - dy1);
			}
			// Vẽ pixel từ khoảng dòng tại
			// vị trí hiện tại
			putpixel(x, y, color);
		}
	}
}
void inputFile(Point v[], string name)
{
	ifstream inFile;
	inFile.open(name, ios::in);
	string li;
	if (inFile.is_open())
	{
		int i = 0;
		while (getline(inFile, li))
		{
			istringstream point(li);
			point >> v[i].x >> v[i].y;
			i++;
		}
		v[i].x = v[0].x;
		v[i].y = v[0].y;
		inFile.close();
	}
	else
		cout << "Khong mo duoc file!!";
}  

void setRotation()
{
	float rad = goc * 3.14 / 180;
	float x_dis = x2 - x;
	float y_dis = y2 - y;
	x2 = ceil(x_dis*cos(rad) - y_dis * sin(rad)+x);
	y2 = ceil(x_dis*sin(rad) + y_dis * cos(rad) + y);
}

void drawCirFromFile ()
{
	v[13];
	inputFile(v, "Text.txt");
	for (int i = 0; i < 13; i++)
		if (i == 12)
			lineDDA(v[i].x, v[i].y, v[0].x, v[0].y);
		else
			lineDDA(v[i].x, v[i].y, v[i + 1].x, v[i + 1].y);
}

void drawBresenham()
{
	int i = 0;
	while (i < sodiem)  //xác định các điểm bằng phép quay
	{
		setRotation();
		v[i].x = x2; v[i].y = y2;
		i++;
	}
	for (i = 0; i < sodiem; i++) //nối các điểm lại
		if (i == sodiem-1)
			lineDDA(v[i].x, v[i].y, v[0].x, v[0].y);
		else
			lineDDA(v[i].x, v[i].y, v[i + 1].x, v[i + 1].y);
}

int main()
{
	int gd = DETECT, gm;
	initwindow(500,500, "Circle by DDA", 10, 10);
	drawBresenham();
	
	getch();
	closegraph();

	return 0;
}

/*initgraph(&gd, &gm, "c:\\tc\\bgi");*/
//initwindow(500, 500, "Paint", 10, 10);
//int x = getmaxx() / 2;
//int y = getmaxy() / 2;
//int r = 150;
//Bresenham(x, y, r);
////MidPoint(150, 270, 150);
//circle(190, 300, 35);
//drawCirFromFile();

//draw()

//#include <iostream>
//using namespace std;
//#include "glut.h"
//
//float x =100, y=50;
//float x2 = x + 50, y2 = y;
//
//void khoitao()
//{
//	x = 100, y = 50;
//	x2 = x + 50, y2 = y;
//}
//
//void init()
//{
//	glClearColor(0.0, 0.0, 0.0,0.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0, 500, 500, 0);
//}
//
//
//void drawLine()
//{
//	glBegin(GL_LINES);
//		glVertex2f(x, y);
//		glVertex2f(x2, y2);
//	glEnd();
//}
//void display(void) {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//	drawLine();
//	glFlush();
//}
//void setRotation()
//{
//	float rad = 45 * 3.14 / 180;
//	float x_dis = x2 - x;
//	float y_dis = y2 - y;
//	x2 = ceil(x_dis*cos(rad) - y_dis * sin(rad)+x);
//	y2 = ceil(x_dis*sin(rad) + y_dis * cos(rad) + y);
//
//	cout << x2 <<" "<< y2 << "\n";
//}
//
//void drawAgain()
//{
//	drawLine();
//	glutPostRedisplay();
// }
//
//void keyboar(unsigned char key, int x, int y) {
//	switch (key) {
//	case 'e':
//		exit(-1);
//	case 'x':
//		setRotation();
//		glutIdleFunc(drawAgain);
//		break;
//	case 'r':
//		khoitao();
//		glutIdleFunc(drawAgain);
//		break;
//	default:
//		break;
//	}
//}
//
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Bai Tap 1");
//	init();
//	glutDisplayFunc(display);
//	glutKeyboardFunc(keyboar);
//	glutMainLoop();
//	return 0;
//}


