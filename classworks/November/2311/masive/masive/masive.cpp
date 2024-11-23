#include "MasiveHeader.h"

int main()
{
	int* arr = new int[5] { 1, 5, 3, 4, 5 };
	Array<int> numbers(arr, 5, 10);

	IteratorArray<int> it = numbers.begin();

	for (; it != numbers.end(); it++)
	{
		cout << *it << endl;
	}

}