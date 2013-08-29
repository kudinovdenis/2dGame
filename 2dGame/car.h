#pragma once
class car
{
public:
	//Variables
	int x0,y0;
	car(void);
	~car(void);

	//Coords to draw Circle
	int x,y;
	int speed;

	//Draw car
	void draw(int x0, int y0);
	// ReDraw Car if button pressed(5px)
	void move5x(bool left, bool right);

	void handleKey(unsigned char key, int x, int y);

	//Left wheel center coords
	void setX0(int x0);
	void setY0(int y0);


};

