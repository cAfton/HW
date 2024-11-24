#pragma once
#include "MasiveHeader.h"

template<typename T>
class IteratorArray {
	T* index;

public:
	IteratorArray(T* elem) : index(elem){}

	IteratorArray& operator++(int) {
		index++;
		return *this;
	}

	IteratorArray& operator--(int) {
		index--;
		return *this;
	}

	T& operator*() {
		return *index;
	}

	bool operator!=(const IteratorArray& it) const {
		if (this->index != it.index)
		{
			return true;
		}
		else {
			return false;
		}
	}
	bool operator==(const IteratorArray& it) const {
		if (this->index == it.index)
		{
			return true;
		}
		else {
			return false;
		}
	}
};