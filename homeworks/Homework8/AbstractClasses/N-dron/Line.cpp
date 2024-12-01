#include "Line.h"
#include <iostream>

Line::Line():roots(){}

Line::Line(int a, int b) :roots(a, b){}

void Line::calculation()
{
	if (isLogocal()) {
		double x;
		x = (-1 * B()) / A();
		std::cout << "\nX = " << x << std::endl;
	}
}

