//#include "Array.h"
//#include "String.h"
//#include "UniversalArray.h"
#include <iostream>

using namespace std;


template <typename T>
T findA(T arr[], int size) {
	T S = 0;//bad
	for (int i = 0; i < size; i++)
	{
		S += arr[i];
	}
	return S / size;

}

template <typename T>
T calc(T a, T b) {
	return (- 1 * b) / a;
}

template <typename T>
T calc(T a, T b, T c, bool first) {
	T D = pow(b, 2) - 4 * a * c;
	if (D < 0)
		return -1;
	else if (D = 0)
		return (-1 * b) / (2 * a);
	else {
		if (first)//genius!
			return ((-1 * b) + sqrt(D)) / 2 * a;
		else
			return ((-1 * b) - sqrt(D)) / 2 * a;
	}
	
}

template <typename T>
T Max(T a, T b) {
	if (a > b)
		return a;
	else if (a < b)
		return b;
	else
		return a;
}

template <typename T>
T Min(T a, T b) {
	if (a < b)
		return a;
	else if (a > b)
		return b;
	else
		return a;
}

int main()
{


	int arr1[5]{ 1,2,3,4,5 };
	float arr2[5]{ 1.2,4.2,1.2,4.6,7.4 };
	cout << findA(arr1, 5) << '\n' << findA(arr2, 5) << endl;

	cout << calc(2, 4) << '\n' << calc(1, 2, 4, true) << '\t' << calc(1, 2, 4, false) << endl;

	cout << "Max:" << Max(2, 5) << "\nMin:" << Min(3, 5);
}

	/*
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
	*/

	

