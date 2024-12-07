#include "Circle.h"

Circle::Circle()
{
	this->R = 1;
}

Circle::Circle(int r, int x, int y)
{
	this->R = r;
	this->X = x;
	this->Y = y;
}

string Circle::Print()
{
	string ret = "Circle: " + to_string(this->R);
	return ret;

}

void Circle::Save(string path)
{
	ofstream file(path, ios::trunc);
	if (!file.is_open())
	{
		throw runtime_error("coudn't open file");
	}

	file << this->R << endl;
	file << this->X << endl;
	file << this->Y << endl;

	file.close();

}

void Circle::Load(string path)
{
	ifstream file(path);
	if (!file.is_open())
	{
		throw runtime_error("coudn't open file");
	}
	string save;
	getline(file, save);
	this->R = stoi(save);

	getline(file, save);
	this->X = stoi(save);

	getline(file, save);
	this->Y = stoi(save);
}

float Circle::Area()
{
	return 3.14 * this->R * this->R;
}

float Circle::Perimetr()
{
	return 2 * 3.14 * this->R;
}


