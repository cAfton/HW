#include "Array.h"
#include "String.h"
#include "UniversalArray.h"

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

	system("pause");
	system("cls");

	string* s = new string[5]{ "1","2","3","4","5" };

	ArraysOfString S(s, 5, 10);

	cout << S << endl;

	try {
		S.deleteByPosition(2);
	}
	catch (invalid_argument exept) {
		cout << exept.what() << endl;
	}

	cout << S << endl;

	S.addByPosition(100, 2);
	S.addByPosition(110, 2);
	S.addByPosition(120, 2);

	cout << S << endl;

	S.Sort(true);
	S.Sort(false);

	cout << S << endl;

	S.Fit();

	cout << S;


	system("pause");
	system("cls");

	UnuversalArray<char> CharUwwwU(5);

	//CharUwwwU.addByPosition('@', 5);
	CharUwwwU.getLength();
	CharUwwwU.addByPosition('a', 0);
	CharUwwwU.addByPosition('s', 1);
	CharUwwwU.addByPosition('d', 2);
	CharUwwwU.addByPosition('f', 3);
	CharUwwwU.Sort(true);

	cout << CharUwwwU << endl;

}
