#include <iostream>
#include <math.h>

using namespace std;

int recurciveFact(int num) {
	if (num == 1)
	{
		return num;
	}

	return num * recurciveFact(num - 1);
}

int stepin(int num, int numDo) {
	if (numDo == 1)
	{
		return num;
	}
	return num * stepin(num, numDo - 1);
}

int subFactorial(int numSub) {
	if (numSub == 1)
	{
		return 0;
	}
	else if (numSub == 0) {
		return 1;
	}
	return (numSub - 1) * (subFactorial(numSub - 1) + subFactorial(numSub - 2));
}
// (n - 1) * (!(n -1) + !(n -2))

int main()
{
	cout << recurciveFact(5) << endl;
	cout << subFactorial(5) << endl;
	cout << stepin(5, 3);
}
