//#include "graphics.h"
//#pragma comment(lib, "graphics.lib")
//#include <math.h>
//#include <queue>
//#include <iostream>
//
//using namespace std;
//
////#define COLOR 15
//#define MAXSIZE 50
//int pixel = 1;
//int erasersize = 10;
//struct Point
//{
//	int x, y;
//};
//Point a[MAXSIZE];
//void Init()
//{
//	for (int i = 0; i < MAXSIZE; i++)
//	{
//		a[i].x = 0;
//		a[i].y = 0;
//	}
//}
////int round(double a);
//void drawLine(int x, int y, int x2, int y2, int color);
//void put8pixel(int x0, int y0, int x, int y, int color);
//void drawCircle(int x0, int y0, int radius, int color);
//void plot(int x0, int y0, int x, int y, int color);
//void drawEllipse(int rx, int ry, int xc, int yc);
//void ToLoang(int x, int y, int mauto);
//void drawRectangle(int x, int y, int x2, int y2, int color);
//void drawTriangle(Point tri[3], int color);
//void drawPolygon(Point poly[], int n, int color);
//// draw buttons
//void button(int x, int y);
//void eraserButton(int x, int y);
//void fillButton(int x, int y);
//void pencilButton(int x, int y);
//void lineButton(int x, int y);
//void triButton(int x, int y);
//void circleButton(int x, int y);
//void recButton(int x, int y);
//void polyButton(int x, int y);
//void elipButton(int x, int y);
//void clrButton(int x, int y);
//// style
//void choseBox(int x, int y, int c);
//void colorBox(int x, int y, int c);
//void LineBox(int x, int y);
//void recBox(int x, int y);
//void styleBox(int x, int y);
//// tool bars color gray 8
//void toolsBox(int y);
//void colorsBox(int y1, int y2);
////
//
//void layout(int yMax, int color);
////
//void mouseclick();
//int main()
//{
//	//int gd = DETECT, gm;
//	int xMax = 1203, yMax = 703;
//	initwindow(xMax, yMax, "Paint", 10, 10);
//	layout(yMax, 1);
//	//drawRectangle(76,3,1200,700,BLACK); //tọa độ phần giấy là 76,3,1200,700
//	//drawRectangle(7,7,37,37,RED);  //gôm 
//	//drawRectangle(39,7,69,37,RED); // thùng sơn
//	//drawRectangle(19,552,57,677,RED); // color box
//	mouseclick();
//	getch();
//	closegraph();
//	return 0;
//}
//void toolButton(int x, int y)
//{
//	drawRectangle(x, y, x + 30, y + 30, 0);
//	setfillstyle(SOLID_FILL, 7);
//	bar(x + 1, y + 1, x + 30, y + 30);
//}
//void eraserButton(int x, int y)
//{
//	toolButton(x, y);
//	drawRectangle(x + 5, y + 20, x + 15, y + 25, 0);
//	drawLine(x + 5, y + 20, x + 15, y + 10, 0);
//	drawLine(x + 15, y + 20, x + 25, y + 10, 0);
//	drawLine(x + 15, y + 10, x + 25, y + 10, 0);
//	drawLine(x + 25, y + 10, x + 25, y + 15, 0);
//	drawLine(x + 25, y + 15, x + 15, y + 25, 0);
//	//
//	ToLoang(x + 6, y + 21, 15);
//	ToLoang(x + 16, y + 16, 15);
//	ToLoang(x + 16, y + 21, 8);
//}
//void fillButton(int x, int y)
//{
//	toolButton(x, y);
//	drawRectangle(x + 5, y + 10, x + 25, y + 30, 0);
//	drawLine(x + 6, y + 25, x + 24, y + 25, 4);
//	drawLine(x + 6, y + 20, x + 24, y + 20, 4);
//	ToLoang(x + 13, y + 12, 12);
//	ToLoang(x + 22, y + 22, 4);
//	ToLoang(x + 22, y + 29, 12);
//	drawLine(x + 6, y + 11, x + 24, y + 11, 4);
//	drawLine(x + 20, y + 12, x + 20, y + 18, 4);
//	drawLine(x + 19, y + 12, x + 19, y + 16, 4);
//	drawLine(x + 21, y + 12, x + 21, y + 14, 4);
//	//drawLine(x + 7, y + 13, x + 15, y + 25, 0);
//	//drawLine(x + 7, y + 13, x + 15, y + 7, 0);
//	//drawLine(x + 15, y + 7, x + 23, y + 19, 0);
//	//drawLine(x + 15, y + 25, x + 23, y + 19, 0);
//}
//void pencilButton(int x, int y)
//{
//	Point p1, p2, p3;
//	p1.x = x + 15; p1.y = y + 5;
//	p2.x = x + 10; p2.y = y + 15;
//	p3.x = x + 20; p3.y = y + 15;
//	Point p[3] = { p1, p2, p3 };
//	// ve
//	toolButton(x, y);
//	drawTriangle(p, 0);
//	drawLine(p2.x, p2.y, p2.x, y + 30, 0);
//	drawLine(p3.x, p3.y, p3.x, y + 30, 0);
//	drawLine(p1.x - (p1.x - p3.x) / 2, p1.y + (p3.y - p1.y) / 2, p1.x + (p2.x - p1.x) / 2, p1.y + (p3.y - p1.y) / 2, 0);
//	drawLine(p2.x + 5, p2.y, p2.x + 5, y + 30, 0);
//	//
//	ToLoang(p1.x, p1.y + 3, 0);
//	ToLoang(p2.x + 2, p2.y - 2, 6);
//	ToLoang(p2.x + 2, y + 25, 3);
//	ToLoang(p3.x - 2, y + 25, 11);
//}
//void lineButton(int x, int y)
//{
//	toolButton(x, y);
//	drawLine(x + 5, y + 5, x + 25, y + 25, 0);
//
//}
//void triButton(int x, int y)
//{
//	toolButton(x, y);
//	//
//	Point p1, p2, p3;
//	p1.x = x + 15; p1.y = y + 5;
//	p2.x = x + 5; p2.y = y + 25;
//	p3.x = x + 25; p3.y = y + 25;
//	Point p[3] = { p1,p2,p3 };
//	drawTriangle(p, 0);
//}
//void circleButton(int x, int y)
//{
//	toolButton(x, y);
//	drawCircle(x + 15, y + 15, 10, 0);
//}
//void recButton(int x, int y)
//{
//	toolButton(x, y);
//	drawRectangle(x + 5, y + 8, x + 25, y + 22, 0);
//}
//void polyButton(int x, int y)
//{
//	toolButton(x, y);
//	drawLine(x + 10, y + 5, x + 25, y + 5, 0);
//	drawLine(x + 10, y + 25, x + 25, y + 25, 0);
//	drawLine(x + 5, y + 15, x + 10, y + 5, 0);
//	drawLine(x + 5, y + 15, x + 10, y + 25, 0);
//	drawLine(x + 20, y + 15, x + 25, y + 25, 0);
//	drawLine(x + 20, y + 15, x + 25, y + 5, 0);
//}
//void elipButton(int x, int y)
//{
//	toolButton(x, y);
//	//ellipMidpoint(x + 15, y + 15, 5, 10, 0);
//}
//void clrButton(int x, int y)
//{
//	toolButton(x, y);
//	drawLine(x + 5, y + 5, x + 25, y + 25, 4);
//	drawLine(x + 25, y + 5, x + 5, y + 25, 4);
//}
//void choseBox(int x, int y, int c)
//{
//	// back box
//	drawRectangle(x + 10, y + 4, x + 25, y + 19, 8);
//	setfillstyle(SOLID_FILL, 15);
//	bar(x + 10, y + 4, x + 25, y + 19);
//	// font box
//	drawRectangle(x, y, x + 15, y + 15, 8);
//	setfillstyle(SOLID_FILL, c);
//	bar(x, y, x + 15, y + 15);
//}
//void colorBox(int x, int y, int c)
//{
//	drawRectangle(x, y, x + 15, y + 15, 0);
//	setfillstyle(SOLID_FILL, c);
//	bar(x, y, x + 15, y + 15);
//}
//void LineBox(int x, int y)
//{
//	drawLine(x + 3, y + 17, x + 60, y + 17, 0);
//
//	drawLine(x + 3, y + 52, x + 60, y + 52, 0);
//	drawLine(x + 3, y + 53, x + 60, y + 53, 0);
//
//	drawLine(x + 3, y + 86, x + 60, y + 86, 0);
//	drawLine(x + 3, y + 87, x + 60, y + 87, 0);
//	drawLine(x + 3, y + 88, x + 60, y + 88, 0);
//}
//void recBox(int x, int y)
//{
//	drawRectangle(x + 3, y + 5, x + 60, y + 30, 0);
//	drawRectangle(x + 3, y + 40, x + 60, y + 65, 0);
//	setfillstyle(SOLID_FILL, 15);
//	bar(x + 4, y + 41, x + 59, y + 64);
//	bar(x + 4, y + 76, x + 59, y + 100);
//}
//void styleBox(int x, int y)
//{
//
//	drawRectangle(x, y, x + 63, y + 105, 8);
//	drawCircle(x + 10, y + 20, 5, 0);//+10, +20,r = 5
//	setbkcolor(7);
//	setcolor(0);
//	outtextxy(x + 25, y + 13, "1px");
//	drawCircle(x + 10, y + 50, 5, 0);//+10, +50, r = 5
//	outtextxy(x + 25, y + 43, "3px");
//	drawCircle(x + 10, y + 80, 5, 0);//+10, +80, r = 5
//	outtextxy(x + 25, y + 73, "5px");
//
//	//LineBox(x,y);
//	//recBox(x,y);
//}
//
//void toolsBox(int y)
//{
//	drawRectangle(7, 7, 70, 133, 0);
//	setfillstyle(SOLID_FILL, 8);
//	bar(2, 2, 76, y - 2);//y-69
//	// tô màu xung quanh các nút để làm nổi
//	setfillstyle(SOLID_FILL, 15);
//	bar(5, 5, 72, 167);
//	setfillstyle(SOLID_FILL, 7);
//	bar(7, 167, 7 + 63, 167 + 105);
//}
//void colorsBox(int y1, int y2)
//{
//	// current color
//	drawRectangle(17, y1 - 34, 57, y1 - 4, 0);
//	setfillstyle(SOLID_FILL, 7);
//	bar(17, y1 - 34, 57, y1 - 4);
//	//
//	drawRectangle(17, y1, 57, y2, 0);
//	setfillstyle(SOLID_FILL, 15);
//	bar(17, y1, 57, y2);
//
//}
////
//void layout(int yMax, int color)
//{
//	int y1, y2;
//	setfillstyle(SOLID_FILL, 15);
//	bar(3, 3, 1200, 700);
//	/*----------------------------------------*/
//	toolsBox(yMax); // tool box ngang
//
//	eraserButton(7, 7); // 1.gôm tẩy
//	fillButton(39, 7); // 2.thùng sơn
//
//	pencilButton(7, 39); // 3.bút chì vẽ pixel
//	lineButton(39, 39); // 4.vẽ đường thẳng
//
//	triButton(7, 71); // 5.vẽ tam giác
//	circleButton(39, 71); // 6.vẽ hình tròn
//
//	recButton(7, 103); // 7.vẽ hình chữ nhật
//	polyButton(39, 103); // 8.vẽ hình polygon
//	//elipButton(25, 135);
//	elipButton(7, 135);
//	clrButton(39, 135);
//
//	styleBox(7, 167);
//	/*----------------------------------------*/
//	colorsBox(550, yMax - 12); // color box dọc
//	y1 = y2 = yMax - 150;
//	choseBox(24, y1 - 32, color);
//	for (int i = 0; i < 8; i++)
//	{
//		colorBox(20, y1, i);
//		y1 += 17;
//	}
//	for (int j = 8; j < 16; j++)
//	{
//		colorBox(40, y2, j);
//		y2 += 17;
//	}
//	/*----------------------------------------*/
//}
////
//
////
//void drawLine(int x1, int y1, int x2, int y2, int color) //Vẽ bằng Bresenham
//{
//	// Iterators, counters required by algorithm
//	int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
//	// Calculate line deltas
//	dx = x2 - x1;
//	dy = y2 - y1;
//	// Create a positive copy of deltas (makes iterating easier)
//	dx1 = abs(dx);
//	dy1 = abs(dy);
//	// Calculate error intervals for both axis
//	px = 2 * dy1 - dx1;
//	py = 2 * dx1 - dy1;
//	// The line is X-axis dominant
//	if (dy1 <= dx1) {
//		// Line is drawn left to right
//		if (dx >= 0) {
//			x = x1; y = y1; xe = x2;
//		}
//		else { // Line is drawn right to left (swap ends)
//			x = x2; y = y2; xe = x1;
//		}
//		putpixel(x, y, color); // Draw first pixel
//		// Rasterize the line
//		for (i = 0; x < xe; i++) {
//			x = x + 1;
//			// Deal with octants...
//			if (px < 0) {
//				px = px + 2 * dy1;
//			}
//			else {
//				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
//					y = y + 1;
//				}
//				else {
//					y = y - 1;
//				}
//				px = px + 2 * (dy1 - dx1);
//			}
//			// Draw pixel from line span at
//			// currently rasterized position
//			putpixel(x, y, color);
//		}
//	}
//	else { // The line is Y-axis dominant
//	 // Line is drawn bottom to top
//		if (dy >= 0) {
//			x = x1; y = y1; ye = y2;
//		}
//		else { // Line is drawn top to bottom
//			x = x2; y = y2; ye = y1;
//		}
//		putpixel(x, y, color); // Draw first pixel
//		// Rasterize the line
//		for (i = 0; y < ye; i++) {
//			y = y + 1;
//			// Deal with octants...
//			if (py <= 0) {
//				py = py + 2 * dx1;
//			}
//			else {
//				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
//					x = x + 1;
//				}
//				else {
//					x = x - 1;
//				}
//				py = py + 2 * (dx1 - dy1);
//			}
//			// Draw pixel from line span at
//			// currently rasterized position
//			putpixel(x, y, color);
//		}
//	}
//}
//void drawLineInCanvas(int x1, int y1, int x2, int y2, int color) //Vẽ Line có giới hạn trong Canvas
//{
//	// Iterators, counters required by algorithm
//	int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
//	// Calculate line deltas
//	dx = x2 - x1;
//	dy = y2 - y1;
//	// Create a positive copy of deltas (makes iterating easier)
//	dx1 = abs(dx);
//	dy1 = abs(dy);
//	// Calculate error intervals for both axis
//	px = 2 * dy1 - dx1;
//	py = 2 * dx1 - dy1;
//	// The line is X-axis dominant
//	if (dy1 <= dx1) {
//		// Line is drawn left to right
//		if (dx >= 0) {
//			x = x1; y = y1; xe = x2;
//		}
//		else { // Line is drawn right to left (swap ends)
//			x = x2; y = y2; xe = x1;
//		}
//		if (x < 1200 && x >= 76 && y < 700 && y >= 3)
//			putpixel(x, y, color); // Draw first pixel
//		// Rasterize the line
//		for (i = 0; x < xe; i++) {
//			x = x + 1;
//			// Deal with octants...
//			if (px < 0) {
//				px = px + 2 * dy1;
//			}
//			else {
//				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
//					y = y + 1;
//				}
//				else {
//					y = y - 1;
//				}
//				px = px + 2 * (dy1 - dx1);
//			}
//			// Draw pixel from line span at
//			// currently rasterized position
//			if (x < 1200 && x >= 76 && y < 700 && y >= 3)
//				putpixel(x, y, color);
//		}
//	}
//	else { // The line is Y-axis dominant
//	 // Line is drawn bottom to top
//		if (dy >= 0) {
//			x = x1; y = y1; ye = y2;
//		}
//		else { // Line is drawn top to bottom
//			x = x2; y = y2; ye = y1;
//		}
//		if (x < 1200 && x >= 76 && y < 700 && y >= 3)
//			putpixel(x, y, color); // Draw first pixel
//		// Rasterize the line
//		for (i = 0; y < ye; i++) {
//			y = y + 1;
//			// Deal with octants...
//			if (py <= 0) {
//				py = py + 2 * dx1;
//			}
//			else {
//				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
//					x = x + 1;
//				}
//				else {
//					x = x - 1;
//				}
//				py = py + 2 * (dx1 - dy1);
//			}
//			// Draw pixel from line span at
//			// currently rasterized position
//			if (x < 1200 && x >= 76 && y < 700 && y >= 3)
//				putpixel(x, y, color);
//		}
//	}
//
//}
//void drawPolygon(Point poly[], int n, int color)  // Vẽ polygon
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (i == n - 1)
//			drawLine(a[i].x, a[i].y, a[0].x, a[0].y, color);
//		else
//			drawLine(a[i].x, a[i].y, a[i + 1].x, a[i + 1].y, color);
//	}
//}
//void drawRectangle(int x, int y, int x2, int y2, int color)	//Vẽ hình chữ nhật
//{
//	drawLine(x, y, x2, y, color);
//	drawLine(x2, y, x2, y2, color);
//	drawLine(x2, y2, x, y2, color);
//	drawLine(x, y2, x, y, color);
//}
//void drawTriangle(Point tri[3], int color)	// Vẽ Tam giác
//{
//	drawLine(tri[0].x, tri[0].y, tri[1].x, tri[1].y, color);
//	drawLine(tri[0].x, tri[0].y, tri[2].x, tri[2].y, color);
//	drawLine(tri[1].x, tri[1].y, tri[2].x, tri[2].y, color);
//}
//void put8pixel(int x0, int y0, int x, int y, int color) //Đặt 8 pixel cho vẽ hình tròn
//{
//	putpixel(x0 + x, y0 + y, color);
//	putpixel(x0 + y, y0 + x, color);
//	putpixel(x0 - y, y0 + x, color);
//	putpixel(x0 - x, y0 + y, color);
//	putpixel(x0 - x, y0 - y, color);
//	putpixel(x0 - y, y0 - x, color);
//	putpixel(x0 + y, y0 - x, color);
//	putpixel(x0 + x, y0 - y, color);
//}
//void drawCircle(int x0, int y0, int radius, int color)  //Vẽ bằng MidPoint x0,y0 tâm O
//{
//
//	int x = 0;
//	int y = radius;
//	float p = (5 / 4) - radius;
//	put8pixel(x0, y0, x, y, color);
//	while (x <= y)
//	{
//		if (p < 0)
//			p += (2 * x) + 3;
//		else
//		{
//			p += (2 * (x - y)) + 5;
//			y--;
//		}
//		x++;
//		put8pixel(x0, y0, x, y, color);
//	}
//}
//
//void ToLoang(int x, int y, int color)
//{
//	//  Khai bao queue chua pixel chua duoc to mau
//	queue<Point> Q;
//	Point m, Tg;
//	int MauNen = getpixel(x, y);
//	if (MauNen == color)
//		return;
//	if (getpixel(x, y) == MauNen && x < getmaxx() && y < getmaxy())
//	{
//		m.x = x;
//		m.y = y;
//		putpixel(m.x, m.y, color);
//		Q.push(m);  //  Them 1 diem vao queue, queue size tang 1
//		while (Q.empty() == false)   //Xet 4 diem xung quanh voi moi diem luu trong queue (neu queue con phan tu)
//		{
//			Q.pop();//  Xoa 1 diem phia dau queue, queue size giam 1
//			//Xet cac diem lan can cua 1 diem
//			if (getpixel(m.x + 1, m.y) == MauNen)
//			{
//				putpixel(m.x + 1, m.y, color);
//				Tg.x = m.x + 1;
//				Tg.y = m.y;
//				Q.push(Tg);// Them 1 diem vao cuoi queue
//			}
//			if (getpixel(m.x - 1, m.y) == MauNen)
//			{
//				putpixel(m.x - 1, m.y, color);
//				Tg.x = m.x - 1;
//				Tg.y = m.y;
//				Q.push(Tg);
//			}
//			if (getpixel(m.x, m.y + 1) == MauNen)
//			{
//				putpixel(m.x, m.y + 1, color);
//				Tg.x = m.x;
//				Tg.y = m.y + 1;
//				Q.push(Tg);
//			}
//			if (getpixel(m.x, m.y - 1) == MauNen)
//			{
//				putpixel(m.x, m.y - 1, color);
//				Tg.x = m.x;
//				Tg.y = m.y - 1;
//				Q.push(Tg);
//			}
//			m = Q.front();// Dua ve gia tri dau tien cho hang doi
//			if (Q.size() == 1) break;
//		}
//	}
//}
////
//
//void drawLineWP(int x, int y, int x2, int y2, int pixel, int color)
//{
//	for (int i = 0; i < pixel; i++)
//	{
//		drawLineInCanvas(x, y + i, x2, y2 + i, color);
//	}
//}
//void drawRectangleWP(int x, int y, int x2, int y2, int pixel, int color)
//{
//	for (int i = 0; i < pixel; i++)
//		drawRectangle(x - i, y - i, x2 + i, y2 + i, color);
//}
//void drawTriangleWP(Point tri[3], int pixel, int color)	// Vẽ Tam giác
//{
//	drawLineWP(tri[0].x, tri[0].y, tri[1].x, tri[1].y, pixel, color);
//	drawLineWP(tri[0].x, tri[0].y, tri[2].x, tri[2].y, pixel, color);
//	drawLineWP(tri[1].x, tri[1].y, tri[2].x, tri[2].y, pixel, color);
//}
//void drawStar(int xcoord, int ycoord, int r, int pixel, int color)
//{
//	Point s[5];
//	float alpha = 72 * 3.1415 / 180;
//	//center : xcoord, ycoord ; radius: r ;
//	s[0].x = xcoord;
//	s[0].y = ycoord - r;
//	for (int k = 1; k < 5; k++)
//	{
//		s[k].x = xcoord + (s[k - 1].x - xcoord)*cos(alpha) - (s[k - 1].y - ycoord)*sin(alpha);
//		s[k].y = ycoord + (s[k - 1].x - xcoord)*sin(alpha) + (s[k - 1].y - ycoord)*cos(alpha);
//	}
//	drawLineWP(s[0].x, s[0].y, s[2].x, s[2].y, pixel, color);
//	drawLineWP(s[2].x, s[2].y, s[4].x, s[4].y, pixel, color);
//	drawLineWP(s[4].x, s[4].y, s[1].x, s[1].y, pixel, color);
//	drawLineWP(s[2].x, s[2].y, s[4].x, s[4].y, pixel, color);
//	drawLineWP(s[1].x, s[1].y, s[3].x, s[3].y, pixel, color);
//	drawLineWP(s[3].x, s[3].y, s[0].x, s[0].y, pixel, color);
//}
//
//
//
//int start_acting(int xcoord, int ycoord, char command, int color) /// execute commands
//{
//	setcolor(color);
//	if (command == 'e') /// eraser command
//	{
//		clearmouseclick(WM_LBUTTONUP);
//		while (!ismouseclick(WM_LBUTTONUP))
//		{
//			if (xcoord < 1200 && xcoord > 76 && ycoord < 700 && ycoord >3)
//			{
//				drawRectangleWP(xcoord, ycoord, xcoord, ycoord, erasersize, WHITE);
//
//				xcoord = mousex();
//				ycoord = mousey();
//			}
//			else
//				break;
//		}
//	}
//	else if (command == 'p') /// pencil command
//	{
//		clearmouseclick(WM_LBUTTONUP);
//		while (!ismouseclick(WM_LBUTTONUP))
//		{
//			if (xcoord < 1200 && xcoord > 76 && ycoord < 700 && ycoord >3)
//			{
//				for (int y = -pixel; y <= pixel; y++)
//				{
//					for (int x = -pixel; x <= pixel; x++)
//					{
//						if (x*x + y * y <= pixel * pixel)
//							putpixel(xcoord + x, ycoord + y, color);
//					}
//				}
//				xcoord = mousex();
//				ycoord = mousey();
//			}
//			else
//				break;
//		}
//	}
//	else if (command == 'l') ///line command
//	{
//		int lx = 0, ly = 0;
//		system("cls");
//		cout << "Click end point of line " << endl;
//		while (1) {
//			if (ismouseclick(WM_LBUTTONDOWN))
//			{
//				lx = mousex();
//				ly = mousey();
//				clearmouseclick(WM_LBUTTONDOWN);
//			}
//			if (lx <= 1200 && lx >= 76 && ly <= 700 && ly >= 3)
//			{
//				break;
//			}
//			else
//			{
//				system("cls");
//				cout << "Please, Click end point of line " << endl;
//			}
//		}
//
//		drawLineWP(xcoord, ycoord, lx, ly, pixel, color);
//		system("cls");
//		cout << "Line Selected, click start point" << endl;
//	}
//	else if (command == 'c') // circle command  
//	{
//		int r = 0, cx = 0, cy = 0;
//		system("cls");
//		cout << "Click the end of the circle's radius" << endl;
//		while (1)
//		{
//
//			if (ismouseclick(WM_LBUTTONDOWN))
//			{
//				cx = mousex();
//				cy = mousey();
//				clearmouseclick(WM_LBUTTONDOWN);
//			}
//			if (cx <= 1200 && cx >= 76 && cy <= 700 && cy >= 3)
//			{
//				r = sqrt(pow((cx - xcoord)*1.0, 2) + pow((cy - ycoord)*1.0, 2)); //tính bán kính
//				break;
//			}
//		}
//
//		//center : xcoord, ycoord ; radius: r ;
//		for (int i = 76; i <= 1200; i++)
//		{
//			for (int j = 3; j <= 700; j++)
//			{
//				if (abs(r - sqrt(pow((xcoord - i)*1.0, 2) + pow((ycoord - j)*1.0, 2))) <= 1)
//				{
//					putpixel(i, j, color);
//				}
//			}
//		}
//
//		system("cls");
//		cout << "Circle Selected, click the center" << endl;
//
//	}
//	else if (command == 's') // star command  
//	{
//		int r = 0, sx = 0, sy = 0;
//		system("cls");
//		cout << "Click the end of the circle's radius" << endl;
//		while (1)
//		{
//
//			if (ismouseclick(WM_LBUTTONDOWN))
//			{
//				sx = mousex();
//				sy = mousey();
//				clearmouseclick(WM_LBUTTONDOWN);
//			}
//			if (sx <= 1200 && sx >= 76 && sy <= 700 && sy >= 3)
//			{
//				r = sqrt(pow((sx - xcoord)*1.0, 2) + pow((sy - ycoord)*1.0, 2)); //tính bán kính
//				break;
//			}
//		}
//
//		drawStar(xcoord, ycoord, r, pixel, color);
//		system("cls");
//		cout << "Circle Selected, click the center" << endl;
//
//	}
//
//
//	else if (command == 'r') ///rectangle command
//	{
//		int rx = 0, ry = 0;
//		system("cls");
//		cout << "Click end point of rectangle" << endl;
//		while (1)
//		{
//			if (ismouseclick(WM_LBUTTONDOWN))
//			{
//				rx = mousex();
//				ry = mousey();
//				clearmouseclick(WM_LBUTTONDOWN);
//			}
//
//			if (rx <= 1200 && rx >= 76 && ry <= 700 && ry >= 3)
//			{
//				break;
//			}
//			else
//			{
//				system("cls");
//				cout << "Please, Click end point of rectangle" << endl;
//
//			}
//
//		}
//		drawRectangleWP(xcoord, ycoord, rx, ry, pixel, color);
//
//		system("cls");
//		cout << "Rectangle selected, click start point" << endl;
//
//	}
//	else if (command == 't') ///triangle command
//	{
//		Point tri[3];
//		tri[0].x = xcoord;
//		tri[0].y = ycoord;
//		tri[1].x = 0;
//		tri[1].y = 0;
//		tri[2].x = 0;
//		tri[2].y = 0;
//		system("cls");
//		cout << "Please, Click 2 other points of triangle" << endl;
//		while (1)
//		{
//			if (ismouseclick(WM_LBUTTONDOWN))
//			{
//				tri[1].x = mousex();
//				tri[1].y = mousey();
//				clearmouseclick(WM_LBUTTONDOWN);
//			}
//
//			if (tri[1].x <= 1200 && tri[1].x >= 76 && tri[1].y <= 700 && tri[1].y >= 3)
//			{
//				break;
//			}
//			else
//			{
//				system("cls");
//				cout << "Please, Click 2 other points of triangle" << endl;
//			}
//		}
//
//		while (1)
//		{
//			if (ismouseclick(WM_LBUTTONDOWN))
//			{
//				tri[2].x = mousex();
//				tri[2].y = mousey();
//				clearmouseclick(WM_LBUTTONDOWN);
//			}
//
//			if (tri[2].x <= 1200 && tri[2].x >= 76 && tri[2].y <= 700 && tri[2].y >= 3)
//			{
//				break;
//			}
//			else
//			{
//				system("cls");
//				cout << "Please, Click 1 other points of triangle " << endl;
//			}
//
//		}
//
//		drawTriangleWP(tri, pixel, color);
//		system("cls");
//		cout << "Triangle Selected, click start point" << endl;
//	}
//	else if (command == 'd') ///polygon command
//	{
//		Point poly[7];
//		poly[0].x = xcoord;
//		poly[0].y = ycoord;
//
//		for (int i = 1; i < 6; i++)
//		{
//			poly[i].x = 0;
//			poly[i].y = 0;
//		}
//		cout << "Please, Click 6 points of polygon" << endl;
//		while (1)
//		{
//			if (ismouseclick(WM_LBUTTONDOWN))
//			{
//				poly[1].x = mousex();
//				poly[1].y = mousey();
//				clearmouseclick(WM_LBUTTONDOWN);
//			}
//			if (poly[1].x <= 1200 && poly[1].x >= 76 && poly[1].y <= 700 && poly[1].y >= 3)
//			{
//				break;
//			}
//			else
//			{
//				system("cls");
//				cout << "Please, Click 5 points of polygon" << endl;
//			}
//		}
//		while (1)
//		{
//			if (ismouseclick(WM_LBUTTONDOWN))
//			{
//				poly[2].x = mousex();
//				poly[2].y = mousey();
//				clearmouseclick(WM_LBUTTONDOWN);
//			}
//			if (poly[2].x <= 1200 && poly[2].x >= 76 && poly[2].y <= 700 && poly[2].y >= 3)
//			{
//				break;
//			}
//			else
//			{
//				system("cls");
//				cout << "Please, Click 4 points of polygon" << endl;
//			}
//		}
//		while (1)
//		{
//			if (ismouseclick(WM_LBUTTONDOWN))
//			{
//				poly[3].x = mousex();
//				poly[3].y = mousey();
//				clearmouseclick(WM_LBUTTONDOWN);
//			}
//			if (poly[3].x <= 1200 && poly[3].x >= 76 && poly[3].y <= 700 && poly[3].y >= 3)
//			{
//				break;
//			}
//			else
//			{
//				system("cls");
//				cout << "Please, Click 3 points of polygon" << endl;
//			}
//		}
//		while (1)
//		{
//			if (ismouseclick(WM_LBUTTONDOWN))
//			{
//				poly[4].x = mousex();
//				poly[4].y = mousey();
//				clearmouseclick(WM_LBUTTONDOWN);
//			}
//			if (poly[4].x <= 1200 && poly[4].x >= 76 && poly[4].y <= 700 && poly[4].y >= 3)
//			{
//				break;
//			}
//			else
//			{
//				system("cls");
//				cout << "Please, Click 2 points of polygon" << endl;
//			}
//		}
//		while (1)
//		{
//			if (ismouseclick(WM_LBUTTONDOWN))
//			{
//				poly[5].x = mousex();
//				poly[5].y = mousey();
//				clearmouseclick(WM_LBUTTONDOWN);
//			}
//			if (poly[5].x <= 1200 && poly[5].x >= 76 && poly[5].y <= 700 && poly[5].y >= 3)
//			{
//				break;
//			}
//			else
//			{
//				system("cls");
//				cout << "Please, Click 1 points of polygon" << endl;
//			}
//		}
//		poly[6] = poly[0];
//		for (int i = 0; i < 6; i++)
//			drawLineWP(poly[i].x, poly[i].y, poly[i + 1].x, poly[i + 1].y, pixel, color);
//
//		/*drawPolygon(poly,6,color);*/
//		system("cls");
//		cout << "Polygon Selected, click start point" << endl;
//	}
//	else if (command == 'f') ///fill command
//	{
//		int fx = xcoord, fy = ycoord;
//		system("cls");
//		cout << "Fill Color Selected, click point to fill" << endl;
//
//		if (fx <= 1200 && fx >= 76 && fy <= 700 && fy >= 3)
//		{
//			ToLoang(fx, fy, color);
//		}
//
//		system("cls");
//		cout << "Fill Color Selected, click point to fill" << endl;
//	}
//
//	else
//	{
//		system("cls");
//		cout << "Please, select a tool " << endl;
//		return(1);
//	}
//}
//
//
//void mouseclick() /// clicking buttons (coordinates)
//{
//	int xcoord, ycoord, color = 1;
//	char command = 'p';
//
//	while (1) //Loop to detect mouse clicking and to paint
//	{
//		clearmouseclick(WM_LBUTTONDOWN);
//		delay(10);
//
//		if (ismouseclick(WM_LBUTTONDOWN)) ///Detects Mouse Left-Click
//		{
//			xcoord = mousex(); ycoord = mousey();//gets x and y of mouse position
//			clearmouseclick(WM_LBUTTONDOWN);
//
//			if (xcoord < 70 && xcoord>6 && ycoord > 6 && ycoord < 166)
//			{
//				if (xcoord < 39 && xcoord>6)
//				{
//					if (ycoord < 38 && ycoord>6)
//					{
//
//						for (int i = 10; i < 70; i += 31)
//							for (int j = 10; j < 166; j += 32)
//								ToLoang(i, j, 7);
//						ToLoang(10, 10, 8);			// Màu seclect của tool
//						command = 'e'; //eraser
//						system("cls");
//						cout << "Eraser Selected, star erasing" << endl;
//					}
//					else if (ycoord < 70 && ycoord>38)
//					{
//						for (int i = 10; i < 70; i += 31)
//							for (int j = 10; j < 166; j += 32)
//								ToLoang(i, j, 7);
//						ToLoang(10, 41, CYAN);			// Màu seclect của tool
//						command = 'p'; //pencil
//						system("cls");
//						cout << "Pencil Selected, start drawing" << endl;
//					}
//					else if (ycoord > 70 && ycoord < 102)
//					{
//						for (int i = 10; i < 70; i += 31)
//							for (int j = 10; j < 166; j += 32)
//								ToLoang(i, j, 7);
//						ToLoang(10, 72, CYAN);
//						command = 't'; //triangle
//						system("cls");
//						cout << "Triangle Selected, click start point" << endl;
//					}
//					else if (ycoord < 134 && ycoord>102)
//					{
//						for (int i = 10; i < 70; i += 31)
//							for (int j = 10; j < 166; j += 32)
//								ToLoang(i, j, 7);
//						ToLoang(10, 104, CYAN);
//						command = 'r'; //rectangle
//						system("cls");
//						cout << "Rectangle Selected, click start point" << endl;
//					}
//					else if (ycoord < 166 && ycoord>134)
//					{
//						for (int i = 10; i < 70; i += 31)
//							for (int j = 10; j < 166; j += 32)
//								ToLoang(i, j, 7);
//						ToLoang(10, 136, CYAN);
//						command = 's'; //star
//						system("cls");
//						cout << "Star Selected, click start point" << endl;
//					}
//				}
//				else if (xcoord >= 39 && xcoord < 70)
//				{
//					if (ycoord < 38 && xcoord>6)
//					{
//						for (int i = 10; i < 70; i += 31)
//							for (int j = 10; j < 166; j += 32)
//								ToLoang(i, j, 7);
//						ToLoang(41, 10, CYAN);
//						command = 'f'; //fill
//						system("cls");
//						cout << "Fill Selected, click the point to fill" << endl;
//					}
//					else if (ycoord < 70 && xcoord>38)
//					{
//						for (int i = 10; i < 70; i += 31)
//							for (int j = 10; j < 166; j += 32)
//								ToLoang(i, j, 7);
//						ToLoang(41, 42, CYAN);
//						command = 'l'; //line
//						system("cls");
//						cout << "Line Selected, click start point" << endl;
//					}
//					else if (ycoord > 70 && ycoord < 102)
//					{
//						for (int i = 10; i < 70; i += 31)
//							for (int j = 10; j < 166; j += 32)
//								ToLoang(i, j, 7);
//						ToLoang(41, 72, CYAN);
//						command = 'c'; //circle
//						system("cls");
//						cout << "Circle Selected, click the center" << endl;
//					}
//					else if (ycoord < 134 && ycoord>102)
//					{
//						for (int i = 10; i < 70; i += 31)
//							for (int j = 10; j < 166; j += 32)
//								ToLoang(i, j, 7);
//						ToLoang(41, 104, CYAN);
//						command = 'd'; //polygon
//						system("cls");
//						cout << "Polygon Selected, click start point" << endl;
//					}
//					else if (ycoord < 166 && ycoord>134)
//					{
//						cleardevice();
//						layout(703, color);
//						pixel = 1;
//						system("cls");
//						cout << "Cleared ! Please seclect a tool " << endl;
//					}
//				}
//				else command = 'n'; //neutral
//			}
//			else if (xcoord > 11 && xcoord < 23 && ycoord > 181 && ycoord < 193)//đổi kích thước pixel
//			{
//				for (int i = 187; i <= 187 + 60; i += 30)
//					ToLoang(17, i, 7);
//				ToLoang(17, 187, BLUE);
//				pixel = 1;
//			}
//			else if (xcoord > 11 && xcoord < 23 && ycoord > 181 + 30 && ycoord < 193 + 30)//đổi kích thước pixel
//			{
//				for (int i = 187; i <= 187 + 60; i += 30)
//					ToLoang(17, i, 7);
//				ToLoang(17, 187 + 30, BLUE);
//				pixel = 3;
//			}
//			else if (xcoord > 11 && xcoord < 23 && ycoord > 181 + 60 && ycoord < 193 + 60)//đổi kích thước pixel
//			{
//				for (int i = 187; i <= 187 + 60; i += 30)
//					ToLoang(17, i, 7);
//				ToLoang(17, 187 + 60, BLUE);
//				pixel = 5;
//			}
//			else if (xcoord < 1200 && xcoord>76 && ycoord < 800 && ycoord>3) // click vào phần giấy để vẽ
//			{
//				start_acting(xcoord, ycoord, command, color);
//			}
//			else if (xcoord >= 20 && xcoord <= 35 && (ycoord >= 550 && ycoord <= 691)) //chọn màu
//			{
//
//				if (ycoord >= 553 && ycoord <= 568)
//				{
//					color = 0;
//					choseBox(24, 521, color);
//				}
//				if (ycoord >= 570 && ycoord <= 585)
//				{
//					color = 1;
//					choseBox(24, 521, color);
//				}
//				if (ycoord >= 587 && ycoord <= 602)
//				{
//					color = 2;
//					choseBox(24, 521, color);
//				}
//				if (ycoord >= 604 && ycoord <= 619)
//				{
//					color = 3;
//					choseBox(24, 521, color);
//				}
//				if (ycoord >= 621 && ycoord <= 636)
//				{
//					color = 4;
//					choseBox(24, 521, color);
//				}
//				if (ycoord >= 638 && ycoord <= 653)
//				{
//					color = 5;
//					choseBox(24, 521, color);
//				}
//				if (ycoord >= 655 && ycoord <= 670)
//				{
//					color = 6;
//					choseBox(24, 521, color);
//				}
//				if (ycoord >= 672 && ycoord <= 687)
//				{
//					color = 7;
//					choseBox(24, 521, color);
//				}
//			}
//			else if (xcoord >= 40 && xcoord <= 55 && (ycoord >= 550 && ycoord <= 691))
//			{
//				if (ycoord >= 553 && ycoord <= 568)
//				{
//					color = 8;
//					choseBox(24, 521, color);
//				}
//				if (ycoord >= 570 && ycoord <= 585)
//				{
//					color = 9;
//					choseBox(24, 521, color);
//				}
//				if (ycoord >= 587 && ycoord <= 602)
//				{
//					color = 10;
//					choseBox(24, 521, color);
//				}
//				if (ycoord >= 604 && ycoord <= 619)
//				{
//					color = 11;
//					choseBox(24, 521, color);
//				}
//				if (ycoord >= 621 && ycoord <= 636)
//				{
//					color = 12;
//					choseBox(24, 521, color);
//				}
//				if (ycoord >= 638 && ycoord <= 653)
//				{
//					color = 13;
//					choseBox(24, 521, color);
//				}
//				if (ycoord >= 655 && ycoord <= 670)
//				{
//					color = 14;
//					choseBox(24, 521, color);
//				}
//				if (ycoord >= 672 && ycoord <= 687)
//				{
//					color = 15;
//					choseBox(24, 521, color);
//				}
//			}
//			else command = 'n';
//		}
//	}
//}