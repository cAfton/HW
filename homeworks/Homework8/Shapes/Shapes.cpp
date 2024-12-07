#include "Figures.h"
#include "Paralelogram.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"

int main() {
	Figures** arr = new Figures* [4];

	Paralelogram paralelogram;
	Rectangle rectangle;
	Square square;
	Circle circle;

	try {
		paralelogram.Load("Paralelogram.txt");
		rectangle.Load("Rectangle.txt");
		square.Load("Square.txt");
		circle.Load("Circle.txt");
	}
	catch (runtime_error) {
		cout << "could not open file" << endl;
	}

	arr[0] = &paralelogram;
	arr[1] = &rectangle;
	arr[2] = &square;
	arr[3] = &circle;

	for (size_t i = 0; i < 4; i++)
	{
		cout << arr[i]->Print() << endl;

	}

}