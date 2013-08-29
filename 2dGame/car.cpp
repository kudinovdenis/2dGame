#include "stdafx.h"
#include "car.h"
#include <gl/glut.h>
#include <math.h>
#include <iostream>

#define BASEWIDTH 50 //Ширина машины
#define BASEHEIGHT 30 // Высота
car::car(void)
{
}


car::~car(void)
{
}

void car::setX0(int x0)
{
	this->x0=x0;
}

void car::setY0(int y0)
{
	this->y0=y0;
}

//Отрисовка всей машины в целом
void car::draw(int x0,int y0) //X0,Y0 -- Center of the First(back) Wheel
{
	
	static float pi=3.14;
	this->setX0(x0);
	this->setY0(y0);
	std::cout<<"car1.x0:"<<this->x0<<"\tcar1.y0:"<<this->y0<<std::endl;
	//Wheels
	int r=10;
	glColor3f(0,0,1);
	glBegin(GL_POINTS);
	glColor3f(0,1,0);
	for(float i=0; i<2*pi; i=i+0.01)
	{
		//First Wheel
		x=this->x0+r*cos(i);
		y=this->y0-r*sin(i);
		glVertex2d(x,y);

		//Second Wheel
		x=this->x0+BASEWIDTH+r*cos(i);
		y=this->y0-r*sin(i);
		glVertex2d(x,y);
	}
	glEnd(); //Wheels

	//BASE
	glBegin(GL_LINES);
	glVertex2d(x0,y0);
	glVertex2d(x0+BASEWIDTH,y0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2d(x0,y0-BASEHEIGHT); //По часовой стрелке
	glVertex2d(x0+BASEWIDTH,y0-BASEHEIGHT);
	glVertex2d(x0+BASEWIDTH,y0-r);
	glVertex2d(x0,y0-r);
	glEnd();

	glFinish(); //BASE
}

//Car movement 5px (left, right)
void car::move5x(bool left, bool right)
{
	this->speed=5;
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glClear (GL_COLOR_BUFFER_BIT); 
	if(left==true)
		this->draw(this->x0-this->speed, this->y0);
	if(right==true)
		this->draw(this->x0+this->speed, this->y0);
	glFinish();
}