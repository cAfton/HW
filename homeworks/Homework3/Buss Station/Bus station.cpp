#include <iostream>
#include "Station.h"
#include <cstring>

using namespace std;

void addPassengers(int passengers[4]) {
	cout << "Enter the average time between the arrival of passengers at the stop at different times of the day:\n";
	int number;

	cout << "morning: ";
	cin >> number;
	passengers[0] = number;

	cout << "midday: ";
	cin >> number;
	passengers[1] = number;

	cout << "Evening: ";
	cin >> number;
	passengers[2] = number;

	cout << "Night: ";
	cin >> number;
	passengers[3] = number;
}

void addBuses(int buses[4]) {
	cout << "Enter the average time between the arrivals of minibuses at a stop at different times of the day:\n";
	int number;

	cout << "morning: ";
	cin >> number;
	buses[0] = number;

	cout << "midday: ";
	cin >> number;
	buses[1] = number;

	cout << "Evening: ";
	cin >> number;
	buses[2] = number;

	cout << "Night: ";
	cin >> number;
	buses[3] = number;
}

int main()
{
	int passengers[4] = { 0 };
	int buses[4] = { 0 };
	bool no;

	addPassengers(passengers);
	system("cls");
	addBuses(buses);
	system("cls");

	while (true)
	{
		cout << "Enter whether this stop is final(1-Yes, 2-No): ";
		int isYes;
		cin >> isYes;

		if (isYes == 1) {
			no = true;
			break;
		}

		else if (isYes == 2) {
			no = false;
			break;
		}

		system("cls");
	}
	

	Station shuwar(no, passengers, buses);
	
	cout << shuwar.sufficientTimeIntervalBetweenTheArrivalOfMinibuses(7, 0) << endl;

	cout << shuwar.sufficientTimeIntervalBetweenTheArrivalOfMinibuses(7, 1) << endl;

	cout << shuwar.sufficientTimeIntervalBetweenTheArrivalOfMinibuses(7, 2) << endl;

	cout << shuwar.sufficientTimeIntervalBetweenTheArrivalOfMinibuses(7, 3) << endl;

	cout << shuwar.sufficientTimeIntervalBetweenTheArrivalOfMinibuses(7, 4) << endl;

	cout << endl;

	cout << shuwar.theAverageTimeAPersonStaysAtAStop(0) << endl;

	cout << shuwar.theAverageTimeAPersonStaysAtAStop(1) << endl;

	cout << shuwar.theAverageTimeAPersonStaysAtAStop(2) << endl;

	cout << shuwar.theAverageTimeAPersonStaysAtAStop(3) << endl;

	cout << shuwar.theAverageTimeAPersonStaysAtAStop(4) << endl;
}
