#include "stdafx.h"
#include < gl/glut.h > 
#include <iostream>
#include <math.h>
#include <Windows.h>
#include <process.h>

#include "draw.h"
#include "car.h"
#include "movementThread.h"

bool isSecondPush=0;// Для координат мыши . Если второе нажатие -- рисуем линию.
int old_x, old_y;
car car1;


void display(void) 
{ 
	glClear (GL_COLOR_BUFFER_BIT);
	glFinish(); 
} 


// ClrScr, Ortho, Draw a car
void init (void) 
{  
glClearColor (0.0, 0.0, 0.0, 0.0); 

//Draw car
car1.draw(40,250);
/* инициализация viewing values */
glMatrixMode(GL_PROJECTION); 
glLoadIdentity(); 
glOrtho(0,600,350,0,-1,1);
} 


void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27:
		{
			exit(true);
			break;
		}
		case 'c':
		{
			glClearColor (0.0, 0.0, 0.0, 0.0);
			glClear (GL_COLOR_BUFFER_BIT);
			glFinish(); 
			break;
		}
		case 'd':
			{
				//_beginthread(rightThread,0,NULL);
				glFinish();
				car1.move5x(false,true);
			break;
			}
		case 'a':
			{
				//_beginthread(leftThread,0,NULL);
				glFinish();
				car1.move5x(true,false);
			break;
			}
	}
}

void handleMousepress(int button, int state, int x, int y)
{
	if((button==GLUT_LEFT_BUTTON) && (state==GLUT_DOWN) )
	{
		std::cout<< "LeftMouseButton is Pushed"<<std::endl;
		std::cout<<"X:"<<x<<"\tY:"<<y<<std::endl;
		std::cout<<"old_X:"<<old_x<<"\told_Y:"<<old_y<<std::endl;
		if(isSecondPush==1)
		{
			drawLinesToCursor(x,y,old_x, old_y);
			isSecondPush=0;
			std::cout<<"isSecondPush"<<isSecondPush<<std::endl<<std::endl;
		}
		else
		{
			old_x=x;
			old_y=y;
			isSecondPush=1;
			std::cout<<"isSecondPush"<<isSecondPush<<std::endl<<std::endl;
		}
	}
}

/* 
Определим параметры окна , display mode 
* (single buffer and RGBA).
*/ 
int main(int argc, char** argv) 
{ 
glutInit(&argc, argv); 
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize (600, 350); 
glutInitWindowPosition (800, 400); 
glutCreateWindow ("2dGame"); 
init ();
glutDisplayFunc(display);
glutMouseFunc(handleMousepress);
glutKeyboardFunc(handleKeypress);
glutMainLoop(); 

return EXIT_SUCCESS;  
} 