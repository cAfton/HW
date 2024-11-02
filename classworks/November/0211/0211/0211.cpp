#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Figures {
public:
	friend ostream& operator << (ostream& wiwod, Figures& figure) {
		wiwod << "Welcome to the club Buddy, I'm: ";
		return wiwod;
	}
	virtual float Area() = 0;

	virtual float Perimetr() = 0;

};

class Paralelogram : public Figures {
protected:
	int SideA;
	int SideB;
	int Angle;
public:
	Paralelogram() {
		SideA = 1;
		SideB = 2;
		Angle = 45;
	}
	Paralelogram(int sideA, int sideB, int angle) {
		this->SideA = sideA;
		this->SideB = sideB;
		this->Angle = angle;
	}

	friend ostream& operator << (ostream& wiwod, Paralelogram& paralel) {
		wiwod << static_cast<Figures&>(paralel);
		wiwod << "Paralelogram";
		wiwod << paralel.SideA;
		wiwod << ";";
		wiwod << paralel.SideB;
		wiwod << ";";
		wiwod << paralel.Angle;
		return wiwod;
	}

	float Area() {
		float S = (SideA * SideB) * sin(Angle);
		return S;
	}
	float Perimetr() {
		float P = 2 * SideA + 2 * SideB;
		return P;
	}
};

class Rectangle : public Paralelogram {
public:
	Rectangle() : Paralelogram(1, 2, 90) {}
	Rectangle(int sideA, int sideB) : Paralelogram(sideA, sideB, 90) {}

	friend ostream& operator <<(ostream& wiwod, Rectangle& rectangle) {
		wiwod << static_cast<Figures&>(rectangle);
		wiwod << "Rectangle";
		wiwod << rectangle.SideA;
		wiwod << ";";
		wiwod << rectangle.SideB;
		wiwod << ";";
		return wiwod;
	}
};

class Romb : public Paralelogram {
public:
	Romb() : Paralelogram(1, 1, 45) {}
	Romb(int sideA, int angle) : Paralelogram(sideA, sideA, angle) {}

	friend ostream& operator <<(ostream& wiwod, Romb& romb) {
		wiwod << static_cast<Figures&>(romb);
		wiwod << "Romb";
		wiwod << romb.SideA;
		wiwod << ";";
		wiwod << romb.Angle;
		wiwod << ";";
		return wiwod;
	}
};

class Square : public Rectangle {
public:

	Square() : Rectangle(1, 1) {}
	Square(int sideA) : Rectangle(sideA, sideA) {}

	friend ostream& operator <<(ostream& wiwod, Square& square) {
		wiwod << static_cast<Figures&>(square);
		wiwod << "Square";
		wiwod << square.SideA;
		wiwod << ";";
		return wiwod;
	}
};

class Triangle : public Figures {
private:
	int sideA;
	int sideB;
	double angle;
public:
	Triangle() {
		this->sideA = 1;
		this->sideB = 5;
		this->angle = 45;
	}
	Triangle(int SideA, int SideB, int Angle) {
		this->sideA = SideA;
		this->sideB = SideB;
		this->angle = Angle;
	}

	string toString(const string& name) {
		string ret = " im triangle " + name + "\nside A " + to_string(this->sideA) + "\nSide B: " + to_string(this->sideB) + "\nAngle: " + to_string(angle);
		return ret;

	}

	friend ostream& operator<<(ostream& out, Triangle& triangle) {
		out << static_cast<Figures&>(triangle);
		out << triangle.toString("ABC");

		return out;
	}

	float Perimetr() {
		float sideC = (this->sideA * this->sideA) + (this->sideB * this->sideB) - (2 * this->sideA * this->sideB * sin(this->angle));
		return this->sideA + this->sideB + sideC;
	}

	float Area() {
		float ret = 0.5 * this->sideA * this->sideB * sin(this->angle);
		return ret;
	}

};

class RectangularTriangle : public Triangle {
public:
	RectangularTriangle() : Triangle(2, 3, 90) {};
	RectangularTriangle(int sideA, int sideB) : Triangle(sideA, sideB, 90) {};
};

int main() {
	Paralelogram newParalel(2, 8, 60);
	cout << newParalel.Area();
	cout << endl;
	cout << newParalel.Perimetr();
	cout << endl;
	cout << newParalel;
	cout << endl;
	Rectangle newRectangle(4, 10);
	cout << newRectangle.Area();
	cout << endl;
	cout << newRectangle.Perimetr();
	cout << endl;
	cout << newRectangle;
	cout << endl;

	Romb newRomb(4, 60);
	cout << newRomb.Area();
	cout << endl;
	cout << newRomb.Perimetr();
	cout << endl;
	cout << newRomb;
	cout << endl;

	Square newSquare(4);
	cout << newSquare.Area();
	cout << endl;
	cout << newSquare.Perimetr();
	cout << endl;
	cout << newSquare;
	cout << endl;

	cout << endl;
	Triangle newTriangle(2, 2, 45);
	cout << newTriangle << endl;
	cout << newTriangle.Area() << endl;
	cout << newTriangle.Perimetr() << endl;

	cout << endl;
	RectangularTriangle recTri(3, 4);
	cout << recTri << endl;
	cout << recTri.Area() << endl;
	cout << recTri.Perimetr() << endl;
}