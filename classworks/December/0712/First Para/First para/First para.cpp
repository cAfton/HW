#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class City {
	string name;
	string Mayor;

};

class Country {
	string name;
	string president;
	vector<City> cities;

};


void FindCity() {}

void ChangeName(vector<string>) {
	string county;
	cout << "Which city you`d like to change?";
	cin >> county;

}

void AddCityOrCounry() {
	int a;
	bool b;
	cout << "what 1.countre or 2.city you want?" << endl;
	cin >> a;
	string c;
	if (a == 1) {
		b = true;
		cout << "enter countre name" << endl;
		cin >> c;
	}
	else {
		b = false;
		cout << "enter city name" << endl;
		cin >> c;
	}
}

void DisplayCounties() {


}

void DisplayCities() {
	string county;
	cout << "Which counry you`d like to see?";
	cin >> county;

}

void NumberOfCities(vector<string>) {
	string county;
	cout << "Which counry`s number of cities you`d like to see?";
	cin >> county;
}

void Delete(vector<string>) {
	string name;
	int countyOrCity;
	bool choice;
	cout << "Which 1.counry or 2.city you`d like to delete?";
	cin >> countyOrCity;
	if (countyOrCity == 1)
	{
		choice = true;
		cout << "Enter county name:";
		cin >> name;


	}
	else if (countyOrCity == 2)
	{
		choice = false;
		cout << "Enter city name:";
		cin >> name;

	}
	else
	{
		return;
	}
}

void readFromFile(fstream file, vector<Country> Countries) {

}

int main()
{
	string filepath = "text.txt";
	fstream file(filepath);
	vector<Country> Countries;



	cout << "STL\nList of cities" << endl;
	int choice;
	cout << "|1. Find city            |" << endl;//-
	cout << "|2. Change cities name   |" << endl;//+
	cout << "|3. Add city or counry   |" << endl;//+
	cout << "|4. Delete city or counry|" << endl;//+
	cout << "|5. Number of cities     |" << endl;//+
	cout << "|6. Display counries     |" << endl;//-
	cout << "|7. Display cities       |\n|   of one counry        |" << endl;//+
	cout << "|0. Exit                 |" << endl;
	cin >> choice;
	while (true)
	{
		switch (choice) {
		case 1:
			FindCity();
			break;

		case 2:
			//ChangeName(vector<string>);
			break;

		case 3:
			AddCityOrCounry();
			break;

		case 4:
			//Delete();

			break;

		case 5:
			//NumberOfCities(vector<string>);
			break;

		case 6:
			DisplayCounties();
			break;


		case 7:
			DisplayCities();
			break;

		case 0:
			return 0;
			break;

		default:
			break;
		}
	}
}