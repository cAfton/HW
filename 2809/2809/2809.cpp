#include "Array.h"

int main()
{
	int* numbers = new int[5] {1, 2, 3, 4, 5};
	Array arr(numbers, 5 , 7);

	cout << arr << endl;

	try {
		arr.deleteByPosition(2);
	}
	catch (invalid_argument exept) {
		cout << exept.what() << endl;
	}

	cout << arr << endl;
	
	arr.addByPosition(100, 2);
	arr.addByPosition(110, 2);
	arr.addByPosition(120, 2);

	cout << arr << endl;

	arr.Sort(true);
	arr.Sort(false);

	cout << arr << endl;

	arr.Fit();

	cout << arr;
}
