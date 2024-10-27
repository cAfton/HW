#pragma once

class Station
{
	bool isTheStationFinal;
	int* passengers; //Morning, midday, evening 
	int* buses; //Morning, midday, evening
	bool isPossible(int n) {
		if (n > 3 || n < 0) {
			return false;
		}
		else {
			return true;
		}
	}

public:
	Station();
	Station(bool isTheStationFinal, int* passengers, int* buses);

	int theAverageTimeAPersonStaysAtAStop(int n);
	int sufficientTimeIntervalBetweenTheArrivalOfMinibuses(int N, int n);

	~Station();


};