#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Figures {
public:
	virtual string toString() = 0;
	//virtual friend ostream& operator << (ostream& wiwod, Figures& figure)  = 0;

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

	string toString() { return "Rect"; }

	friend ostream& operator << (ostream& wiwod, Paralelogram& paralel) {
		//wiwod << static_cast<Figures&>(paralel);
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
		//wiwod << static_cast<Figures&>(rectangle);
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
		//wiwod << static_cast<Figures&>(romb);
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
		//wiwod << static_cast<Figures&>(square);
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

	string toString() {
		string ret = " im triangle\nside A " + to_string(this->sideA) + "\nSide B: " + to_string(this->sideB) + "\nAngle: " + to_string(angle);
		return ret;

	}

	friend ostream& operator<<(ostream& out, Triangle& triangle) {
		//out << static_cast<Figures&>(triangle);
		out << triangle.toString();

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

class D3Figure {
public:
	friend ostream& operator<<(ostream& out, D3Figure& figure) {
		out << "Welcome to the club Buddy, I'm: ";
		return out;
	}

	virtual double Volume() = 0;

	virtual double fullArea() = 0;
};

class Paralelepiped : public D3Figure
{
private:
	int height;
	Paralelogram figura;

public:
	Paralelepiped() {
		this->height = 1;
		this->figura = Paralelogram(1, 1, 90);
	}
	Paralelepiped(Paralelogram Figura, int Height) {
		this->height = Height;
		this->figura = Figura;
	}

	double fullArea() {
		double ret = (this->figura.Perimetr() * this->height) + (this->figura.Area() * 2);
		return ret;
	}

	double Volume() {
		double ret = this->figura.Area() * this->height;
		return ret;
	}

	friend ostream& operator<<(ostream& out, Paralelepiped& para) {
		out << static_cast<D3Figure&>(para) << " Paralelepiped\n" << endl;
		out << para.figura << endl;
		out << para.height << endl;

		return out;
	}

};

class Cube : public Paralelepiped {
public:
	Cube() : Paralelepiped(Paralelogram(1, 1, 90), 1) {};
	Cube(int side) : Paralelepiped(Paralelogram(side, side, 90), side) {};

};

class Piramida : public D3Figure {
private:
	int height;
	Figures* figura;
public:
	Piramida(int H, Figures* F) {
		this->height = H;
		this->figura = F;
	}

	double fullArea() {
		return 0;
	}

	double Volume() {
		double ret = (1. / 3.) * this->height * this->figura->Area();

		return ret;
	}

	friend ostream& operator<<(ostream& out, Piramida& pir) {
		out << static_cast<D3Figure&>(pir) << endl;
		out << pir.figura->toString() << endl;
		out << pir.height << endl;

		return out;
	}

};

class TrianglePiramida : public Piramida {
public:
	TrianglePiramida(int sideA, int sideB, int angle, int H) : Piramida(H, new Triangle(sideA, sideA, angle)) {}


};

class Piramida4 : public Piramida {
public:
	Piramida4(int sideA, int sideB, int angle, int H) : Piramida(H, new Paralelogram(sideA, sideA, angle)) {}


};

int main() {

	Piramida4 pir(2, 2, 45, 2);
	cout << pir << endl;
	cout << pir.Volume() << endl;


	Paralelepiped tryPara(Paralelogram(2, 3, 45), 3);
	cout << tryPara << endl;
}