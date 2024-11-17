#include "quadratic equations.h"
#include <iostream>

quadratic::quadratic() :roots() {}

quadratic::quadratic(int a, int b, int c) :roots(a, b, c) {}

void quadratic::calculation()
{
	if (isLogocal()) {
		double D;
		D = pow(B(), 2) - 4 * A() * C();
		if (D < 0)
			std::cout << "No answers" << std::endl;
		else if (D == 0) {
			double x;
			x = (-1 * B()) / (2 * A());
			std::cout << "\nX = " << x << std::endl;
		}
		else {
			double x1;
			double x2;
			
			x1 = (-1 * B() + sqrt(D)) / (2 * A());
			x2 = (-1 * B() - sqrt(D)) / (2 * A());

			std::cout << "\nX1 = " << x1 << "\nX2 = " << x2 << std::endl;
		}
	} 
}

