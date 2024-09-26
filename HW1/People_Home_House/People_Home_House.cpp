#include "Human.h"
#include "Flat.h"


int main()
{
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

}