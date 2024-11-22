#include "Circle.h"

Circle::Circle()
{
	this->R = 1;
}

Circle::Circle(int r)
{
	this->R = r;
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
}

float Circle::Area()
{
	return 3.14 * this->R * this->R;
}

float Circle::Perimetr()
{
	return 2 * 3.14 * this->R;
}


