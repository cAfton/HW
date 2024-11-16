#pragma once

#include <iostream>

using namespace std;

class ArraysOfString {
private:
	string* arr;
	int size;
	int length;

	bool checkPosition(int position, bool isAdding) const;
public:
	ArraysOfString();
	ArraysOfString(int size);
	ArraysOfString(string* arr, int length, int size);
	ArraysOfString(const ArraysOfString&);
	ArraysOfString(ArraysOfString&&);

	int getSize();
	int getLength();

	void deleteByPosition(int position);
	void addByPosition(int element, int position);

	void Fit();

	void Sort(bool byDecreasing);//?? ?????????

	string& operator[](int index) const;

	friend ostream& operator<<(ostream& out, const ArraysOfString& Arr);
	friend istream& operator>>(istream& in, ArraysOfString& arr);

	~ArraysOfString();
};