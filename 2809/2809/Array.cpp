#include "Array.h"

bool Array::checkPosition(int position, bool isAdding)
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

Array::Array()
{
	this->size = 1;
	this->length = 0;
	this->arr = new int[this->size];
}

Array::Array(int size)
{
	this->length = 0;
	this->size = size;
	this->arr = new int[size];
}

Array::Array(int* arr, int length, int size)
{
	if (size < length)
	{
		throw invalid_argument("length must be less than size");
	}
	this->size = size;
	this->length = length;
	this->arr = new int[this->size];
	for (size_t i = 0; i < this->length; i++)
	{
		this->arr[i] = arr[i];
	}
}

Array::Array(const Array&)
{

}

Array::Array(const Array&&)
{
}

int Array::getSize()
{
	return 0;
}

int Array::getLength()
{
	return 0;
}

void Array::deleteByPosition(int position)
{
}

void Array::addByPosition(int element, int position)
{
}

void Array::Fit()
{
}

void Array::Sort(bool byDecreasing)
{
}

Array::~Array()
{
}

ostream& operator<<(ostream& out, const Array& Arr)
{
	// TODO: insert return statement here
}

istream& operator>>(istream& in, Array& arr)
{
	// TODO: insert return statement here
}
