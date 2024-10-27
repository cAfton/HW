#include <iostream>

using namespace std;

template<typename T>

class queue {

	T* array;
	int* p;

	int length;
	int size;

public:

	queue() {

		array = new T[10];
		p = new int[10];
		length = 0;
		size = 10;

	}
	bool isEmpty() {
		if (length == 0)
			return true;
		else
			return false;
	}

	void push(T elem, int r) {

		if (length == size) {
			T* newArr = new T[size * 2];
			int* newP = new int[size * 2];
			size *= 2;
			for (int i = 0; i < length; ++i) {
				newArr[i] = array[i];
				newP[i] = p[i];
			}

			newArr[length] = elem;
			newP[length] = r;
			length++;
			delete[] array;
			delete[] p;
			array = newArr;
			p = newP;

		}

		else {
			array[length] = elem;
			p[length] = r;
			length++;
		}

	}

	T pop() {

		if (length <= 0) {
			cout << "Error";
			throw std::invalid_argument("Invalid syntax.");
		}
		int P = 1;
		int i = 0;
		while (p[i] != P) {
			if (i < length) {
				i++;
			}
			else if (i == length) {
				P++;
				i = 0;
			}
		}
		T temp = array[i];
		for (int j = i; j < (length - 1); j++)
		{
			array[j] = array[j + 1];
			p[j] = p[j + 1];
		}

		length--;
		return temp;

	}

	T peek() {

		if (length != 0) {

			return array[length];

		}

	}

};

//int main() {
//
//	queue<int> st;
//
//	st.push(1, 2);
//	st.push(2, 1);
//	st.push(1, 3);
//	st.push(4, 4);
//	st.push(3, 2);
//	st.push(1, 1);
//	st.push(2, 4);
//	st.push(2, 3);
//	st.push(1, 1);
//	st.push(3, 2);
//
//	try {
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//		std::cout << st.pop() << '\n';
//
//	}
//
//	catch (std::invalid_argument)
//
//	{
//
//		std::cout << "Error";
//
//	}
//
//}