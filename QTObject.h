#pragma once
#include "GlobalHeader.h"
#include <ctime>
#include <iostream>


struct coor
{
	coor(int xx,int yy) {x = xx; y= yy;};
	int x,y; // basicly a pair of integers
};

class QTObject
{
public:
	QTObject(int r=255,int g=255, int b = 255, bool con = false, bool fill = false, QString textStr = "", int SX = 0, int SY = 0);
	void nextCoor(int x, int y) {shapes.push_back(coor(x,y));};
	int red, green, blue;
	// this will make the initial shape
	std::vector< coor > shapes;
	//solid is if the shape is filled in with a colour
	// connect is if the shapes last and first coordinate are connected...
	bool solid, connect, text;

	QString textString;
};