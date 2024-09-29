#include "Human.h"
#include "Flat.h"
#include "Home.h"


int main()
{
	Home home1;
	Flat flat1;
	Human human1;
	int amount;
	cout << "number of living in flat: ";
	cin >> amount;

	Human* people = new Human[amount];
	for (size_t i = 0; i < amount; i++)
	{
		cout << "\n" << i + 1 << "\n" << endl;
		cin >> people[i];
	}

	cout << endl;
	flat1.setPeople(people);

	cin >> flat1;



	cout << endl;
	for (size_t i = 0; i < amount; i++)
	{
		cout << people[i] << endl;
	}


	cout << flat1 << endl;
	///////////////////////////////////////////////////////
	int amount2;
	cout << "Number of flat in home: ";
	cin >> amount2;

	Flat* flat = new Flat[amount2];
	for (size_t i = 0; i < amount2; i++)
	{
		cout << "\n" << i + 1 << "\n" << endl;
		cin >> flat[i];
	}

	cout << endl;
	home1.setFlat(flat);

	cin >> home1;



	cout << endl;
	for (size_t i = 0; i < amount2; i++)
	{
		cout << flat[i] << endl;
	}
	cout << endl;

	cout << home1 << endl;

	cout << "Number of apartments per floor:" << home1.NumberOfApartmentsPerFloor(amount2) << "\nNumber of parking spaces" << home1.NumberOfParkingSpaces(amount2) << endl;

	system("pause");
	system("cls");
	int choice;
	cout << "Do you want to build another such house?(1. Yes 2. No):";
	cin >> choice;
	if (choice == 1) {
		system("cls");
		Home home2(home1);
		cout << endl;
		cout << home2 << endl;
	}
	else if (choice != 2)
		cout << "There is no such option";

	

}