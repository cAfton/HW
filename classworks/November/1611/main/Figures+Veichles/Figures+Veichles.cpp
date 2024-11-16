#include "IFileLoader.h"
#include "Car.h"
#include "Horse.h"
#include "Circle.h"
#include "RC.h"
#include "Elem.h"
#include <vector>
#include <string>

void readFromFile(string fileName, vector<Elem*>& vect) {
	ifstream file(fileName);
	if (!file.is_open())
	{
		return;
	}
	string line;
	while (!file.eof())
	{
		getline(file, line);
		if (line == "Car: ")
		{
			Car car;
			Car* toAdd =car.read(file);
			vect.push_back(toAdd);
		}
		else if (line == "Horse: ")
		{
			Horse horse;
			Horse* toAdd = horse.read(file);
			vect.push_back(toAdd);
		}
		else if (line == "RC: ")
		{
			RC rc;
			RC* toAdd = rc.read(file);
			vect.push_back(toAdd);
		}
		else if (line == "Circle: ")
		{
			Circle circle;
			Circle* toAdd = circle.read(file);
			vect.push_back(toAdd);
		}
	}

	file.close();
}

int main()
{

	int userChoise;

	cin >> userChoise;
	vector<Elem*> v;

	if (userChoise == 1)
	{
		Car car(1, 2, 3, 4, "blue");
		Horse horse(4, 5, 6, "brown");
		Circle circle(5, 0, 0);
		RC rc(6, 7, true);


		v.push_back(&car);
		v.push_back(&horse);
		v.push_back(&circle);
		v.push_back(&rc);

		ofstream file("File.txt", ios::trunc);

		file.close();

		for (size_t i = 0; i < v.size(); i++)
		{
			v[i]->printInFile("File.txt");
		}

		cout << endl;
	}
	else if (userChoise == 2) {
		readFromFile("File.txt", v);
	}
	
}