#include "stdafx.h"
#include <iostream>
#include <gl\glut.h>
#include "car.h"
#include <Windows.h>
#include <process.h>
#include "2dGame.h"

void leftThread(void* pParams)
{
	while(1)
	car1.move5x(true,false);
	glFinish();
}

void rightThread(void* pParams)
{
	while(1)
	car1.move5x(false,true);
	glFinish();
}