#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class City {
	string name;
	string mayor;
public:
	City(string name, string mayor) {
		this->name = name;
		this->mayor = mayor;
	}

	City(){}

	string GetName() {
		return this->name;
	}
	void setName(string newName) {
		this->name = newName;
	}

	friend ostream& operator<<(ostream& out, City copy) {
		out << "City`s name:" << copy.name << "\nMayor:" << copy.mayor << endl;
		return out;
	}

	friend ofstream& operator<<(ofstream& out, City& copy) {
		out << copy.name << ';' << copy.mayor << ':';
		return out;
	}

	friend istream& operator>>(istream& in, City& copy) {
		cout << "Cities name: ";
		in >> copy.name;
		cout << "Cities Mayor: ";
		in >> copy.mayor;

		return in;
	}

	bool operator==(City& cit) {
		return this->name == cit.GetName();
	}
};

class Country {
	string name;
	string president;
	vector<City> cities;
public:
	Country(string name, string president) {
		this->name = name;
		this->president = president;
	}

	Country() {}

	string GetName() {
		return this->name;
	}

	vector<City>& GetCities() {
		return this->cities;
	}

	friend ostream& operator<<(ostream& out, Country& copy) {
		out << "Country`s name:" << copy.name << "\nPresident:" << copy.president << endl;
		out << "Cities:\n";
		for_each(copy.cities.begin(), copy.cities.end(), [&out](City city) {out << city << endl; });
		return out;
	}

	friend ofstream& operator<<(ofstream& out, Country& copy) {
		out << copy.name << ';' << copy.president << ';';
		for_each(copy.cities.begin(), copy.cities.end(), [&out](City& city) {out << city; });
		return out;
	}

	friend istream& operator>>(istream& in, Country& copy) {
		cout << "Countries name: ";
		in >> copy.name;
		cout << "Countries President: ";
		in >> copy.president;

		return in;
	}
	bool operator==(Country& c) {
		return this->name == c.GetName();
	}
};


void FindCities(vector<Country>& Countries) {
	string countryName;
	cout << "Enter the country name to find: ";
	cin >> countryName;
	auto tmp = find_if(Countries.begin(), Countries.end(), [&countryName](Country& elem) {return countryName == elem.GetName(); });
	
	for_each(tmp->GetCities().begin(), tmp->GetCities().end(), [](City city) {cout << city; });
	
}

void ChangeName(vector<Country>& Countries) {
	string county;
	cout << "In which country is city you`d like to change?";
	cin >> county;

	auto it = find_if(Countries.begin(), Countries.end(), [county](Country elem) {return county == elem.GetName(); });

	string city;
	cout << "\nEnter city's name to change: ";
	cin >> city;

	auto it2 = find_if(it->GetCities().begin(), it->GetCities().end(), [city](City elem) {return city == elem.GetName(); });

	cout << "\nEnter new name: ";
	cin >> city;

	it2->setName(city);
	
}

void AddCityOrCountry(vector<Country>& Countries) {
	int a;
	cout << "what 1.country or 2.city you want?" << endl;
	cin >> a;
	string c;
	if (a == 1) {
		Country newCountry;

		cin >> newCountry;

		Countries.push_back(newCountry);
	}
	else {
		string country;
		cout << "Enter country: ";
		cin >> country;

		auto it = find_if(Countries.begin(), Countries.end(), [country](Country count) {return country == count.GetName(); });

		if (it != Countries.end())
		{
			City newCity;
			cin >> newCity;

			it->GetCities().push_back(newCity);
		}
		else {
			cout << "Country does not exist" << endl;
		}
		
	}
}

void DisplayCounties() {


}

void DisplayCities() {
	string county;
	cout << "Which counry you`d like to see?";
	cin >> county;

}

void NumberOfCities(vector<Country>& Countries) {
	string county;
	cout << "Which country`s number of cities you`d like to see?";

	cin >> county;

	auto it = find_if(Countries.begin(), Countries.end(), [county](Country country) {return county == country.GetName(); });
	
	cout << it->GetCities().size();
}	

void Delete(vector<Country>& Countries) {
	string name;
	int countyOrCity;
	cout << "Which 1.counry or 2.city you`d like to delete?";
	cin >> countyOrCity;
	if (countyOrCity == 1)
	{
		cout << "Enter county name:";
		cin >> name;
		auto it = find_if(Countries.begin(), Countries.end(), [name](Country count) {return name == count.GetName(); });

		if (it != Countries.end())
		{
			Country country();
			remove(Countries.begin(), Countries.end(), *it);
		}
		else {
			cout << "Country does not exist" << endl;
		} 
	}
	else if (countyOrCity == 2)
	{
		string country;
		cout << "Enter country: ";
		cin >> country;

		auto it = find_if(Countries.begin(), Countries.end(), [country](Country elem) {return country == elem.GetName(); });
		

		if (it != Countries.end())
		{
			string city;
			cout << "\nEnter city: ";
			cin >> city;
			City cityToDel(city, "");
			auto it1 = find(it->GetCities().begin(), it->GetCities().end(), [city](City t) {return city == t.GetName(); });

			it->GetCities().erase(*it1);
			remove(it->GetCities().begin(), it->GetCities().end(), *it1);
		}
		else {
			cout << "Country does not exist" << endl;
		}
	}
	else
	{
		return;
	}
}

void readFromFile(string filepath, vector<Country>& Countries) {
	string line;
	fstream file(filepath);

	while (getline(file,line))
	{
		int pos = line.find(';');
		string name = line.substr(0, pos);
		line.erase(0, pos + 1);

		pos = line.find(';');
		string president = line.substr(0, pos);
		line.erase(0, pos + 1);

		Country tmpCo(name, president);


		while (line.find(':')!= string::npos)
		{

			pos = line.find(';');
			string city = line.substr(0, pos);
			line.erase(0, pos + 1);

			pos = line.find(':');
			string mayor = line.substr(0, pos);
			line.erase(0, pos + 1);

			City tmpCi(city, mayor);

			tmpCo.GetCities().push_back(tmpCi);
		}

		Countries.push_back(tmpCo);

	}
	file.close();
}

void writeToFile(string filepath, vector<Country>& Countries) {
	ofstream file(filepath, 'w');

	for_each(Countries.begin(), Countries.end(), [&file](Country counrty) {file << counrty << endl; });

	file.close();
}

int main()
{
	string filepath = "text.txt";
	vector<Country> Countries;

	readFromFile(filepath, Countries);

	
	while (true)
	{
		cout << "STL\nList of cities" << endl;
		int choice;
		cout << "|1. Find city             |" << endl;//+
		cout << "|2. Change cities name    |" << endl;//+
		cout << "|3. Add city or country   |" << endl;//-
		cout << "|4. Delete city or country|" << endl;//-
		cout << "|5. Number of cities      |" << endl;//-
		cout << "|6. Display countries     |" << endl;//-
		cout << "|0. Exit                  |" << endl;//+
		cin >> choice;
		switch (choice) {
		case 1:
			FindCities(Countries);
			break;

		case 2:
			ChangeName(Countries);
			break;

		case 3:
			AddCityOrCountry(Countries);
			break;

		case 4:
			Delete(Countries);

			break;

		case 5:
			NumberOfCities(Countries);
			break;

		case 6:
			DisplayCounties();
			break;


		case 7:
			DisplayCities();
			break;

		case 0:
			writeToFile(filepath, Countries);
			return 0;
			break;

		default:
			break;
		}
	}

}