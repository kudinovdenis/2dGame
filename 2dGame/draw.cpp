#include "stdafx.h"
#include <iostream>
#include <gl\glut.h>
#include "car.h"
#include <Windows.h>
#include <process.h>

//Отрисовка линии по двум кликам мыши.
void drawLinesToCursor(int x, int y, int old_x, int old_y)
{ 
	glColor3f(0,0,1);
	glBegin(GL_LINES);
	glColor3f(0,0,1);
	glVertex2d(x,y);
	glVertex2d(old_x,old_y);
	glEnd();
	glFinish(); 
}