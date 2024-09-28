#include "String.h"

bool ArraysOfString::checkPosition(int position, bool isAdding) const
{
	if (isAdding)
	{
		if (position > this->length + 1 || position < 0) {
			return false;
		}
		else if (&arr[position] == nullptr)
		{
			return false;
		}
		else {
			return true;
		}
	}
	else {
		if (position > this->length || position < 0) {
			return false;
		}
		else if (&arr[position] == nullptr)
		{
			return false;
		}
		else {
			return true;
		}
	}

}

ArraysOfString::ArraysOfString()
{
	this->size = 1;
	this->length = 0;
	this->arr = new string[this->size];
}

ArraysOfString::ArraysOfString(int size)
{
	this->length = 0;
	this->size = size;
	this->arr = new string[size];
}

ArraysOfString::ArraysOfString(string* arr, int length, int size)
{
	if (size < length)
	{
		throw invalid_argument("length must be less than size");
	}
	this->size = size;
	this->length = length;
	this->arr = new string[this->size];
	for (size_t i = 0; i < this->length; i++)
	{
		this->arr[i] = arr[i];
	}
}

ArraysOfString::ArraysOfString(const ArraysOfString& copy)
{
	this->size = copy.size;
	this->length = copy.length;
	this->arr = new string[this->size];
	for (size_t i = 0; i < this->length; i++)
	{
		this->arr[i] = copy.arr[i];
	}

}

ArraysOfString::ArraysOfString(ArraysOfString&& copy)
{
	this->size = copy.size;
	this->length = copy.length;
	this->arr = copy.arr;
	copy.arr = nullptr;
	copy.length = 0;
	copy.size = 0;
}

int ArraysOfString::getSize()
{
	return this->size;
}

int ArraysOfString::getLength()
{
	return this->length;
}

void ArraysOfString::deleteByPosition(int position)
{
	if (checkPosition(position, false))
	{
		for (size_t i = 0; i < this->length - 1; i++)
		{
			if (i >= position)
			{
				this->arr[i] = this->arr[i + 1];
				continue;
			}

			this->arr[i] = this->arr[i];
		}
		this->length--;

	}
	else {
		throw invalid_argument("index can't be more than size");
	}
}

void ArraysOfString::addByPosition(int element, int position)
{
	if (checkPosition(position, true))
	{
		if (this->length + 1 < this->size)
		{
			this->length++;
			string remember = this->arr[position];
			for (size_t i = position; i < this->length - 1; i++)
			{
				string temp = this->arr[i + 1];
				arr[i + 1] = remember;
				remember = temp;
			}
			this->arr[position] = element;

		}
		else {
			this->size += 10;
			string* temporary = new string[this->length];

			for (size_t i = 0; i < this->length; i++)
			{
				temporary[i] = this->arr[i];
			}

			delete[] this->arr;
			this->arr = new string[this->size];
			for (size_t i = 0; i < position; i++)
			{
				this->arr[i] = temporary[i];
			}
			this->arr[position] = element;
			this->length++;
			for (size_t i = position + 1; i < this->length; i++)
			{
				this->arr[i] = temporary[i - 1];
			}
		}
	}
	else {
		throw invalid_argument("index can't be more than size + 1");
	}
}

void ArraysOfString::Fit()
{
	this->size = this->length;
	string* temporary = new string[this->size];
	for (size_t i = 0; i < this->length; i++)
	{
		temporary[i] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = temporary;
}

void ArraysOfString::Sort(bool byDecreasing)
{
	if (byDecreasing)
	{
		for (size_t i = 0; i < this->length; i++)
		{
			for (size_t k = 1; k < this->length; k++)
			{
				if (this->arr[k] > this->arr[k - 1])
				{
					string change = arr[k];
					arr[k] = arr[k - 1];
					arr[k - 1] = change;
				}
			}
		}
	}
	else {
		for (size_t i = 0; i < this->length; i++)
		{
			for (size_t k = 1; k < this->length; k++)
			{
				if (this->arr[k] < this->arr[k - 1])
				{
					string change = arr[k];
					arr[k] = arr[k - 1];
					arr[k - 1] = change;
				}
			}
		}
	}

}

string& ArraysOfString::operator[](int index) const
{
	if (checkPosition(index, false))
	{
		return this->arr[index];
	}
	else {
		throw invalid_argument("index can't be more than size");
	}
}

ArraysOfString::~ArraysOfString()
{
	delete[] this->arr;
}

ostream& operator<<(ostream& out, const ArraysOfString& Arr)
{
	out << "ArraysOfString: [";
	for (size_t i = 0; i < Arr.length; i++)
	{
		if (i == Arr.length - 1)
		{
			out << Arr[i];
			continue;
		}
		out << Arr[i] << ", ";
	}
	out << "]";

	return out;
}

istream& operator>>(istream& in, ArraysOfString& arr)
{
	return in;
}
