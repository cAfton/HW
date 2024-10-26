#include "Station.h"
#include "FILO.cpp"

using namespace std;

Station::Station()
{
	this->isTheStationFinal = true;
	this->passengers = 0;
	this->buses = 0;
}

Station::Station(bool isTheStationFinal, int* passengers, int* buses)
{
	this->isTheStationFinal = isTheStationFinal;
	this->passengers = new int[4];
	this->buses = new int[4];
	for (int i = 0; i < 4; i++)
	{
		this->passengers[i] = passengers[i];
		this->buses[i] = buses[i];
	}
}

int Station::theAverageTimeAPersonStaysAtAStop(int n)
{
	if (isPossible(n)) {
		int N = this->buses[n] / this->passengers[n];
		int time = 0;
		queue<int> st;

		for (int i = 0; i < N; i++)
		{
			st.push(i + 1, rand() % 2);
		}

		while (!st.isEmpty()) {
			time += buses[n];
			for (int i = 0; i < rand() % 30; i++)
			{
				if (!st.isEmpty()) {
					st.pop();
				}
				else
				{
					break;
				}
			}
		}

		return time;
	}
	else
	{
		return -1;
	}
	

}

int Station::sufficientTimeIntervalBetweenTheArrivalOfMinibuses(int N, int n)
{
	if (isPossible(n)) {
		return this->passengers[n] * N;
	}
	else
		return -1;
}

Station::~Station()
{
	delete passengers;
	delete buses;
}
