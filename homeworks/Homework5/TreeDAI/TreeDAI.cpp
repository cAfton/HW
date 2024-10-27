#include <iostream>

using namespace std;

enum Offenses
{
	speeding,
	illegal_parking,
	running_a_red_light,
	no_seatbelt,
	phone_use_while_driving,
};

class Car {
	int carNumber;
	Offenses* offense;
	int size;

public:
	Car() {
		this->carNumber = 1000;
		this->size = 0;
		this->offense = new Offenses[size];
	}

	Car(int number, int size, Offenses* offense) {
		this->carNumber = number;
		this->size = size;
		this->offense = offense;
	}

	Car(int number) {
		this->carNumber = number;
		this->size = 0;
		this->offense = new Offenses[size];
	}


	int getNumber() {
		return this->size;
	}

	void addOffense(Offenses newOffense) {
		Offenses* temp = new Offenses[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = offense[i];
		}
		temp[size] = newOffense;
		delete[] offense;
		offense = temp;
		size++;
	}

	friend ostream& operator<<(ostream& out, Car car) {
		out << "\nCar number: " << car.carNumber << endl;
		out << "Offenses: \n";
		for (size_t i = 0; i < car.size; i++)
		{
			out << car.offense[i] << endl;
		}
		out << "\nTotal " << car.size << " offenses" << endl;
	}
};


class Tree
{
private:
	struct Node
	{
		Car elem;
		Node* left;
		Node* right;

		Node()
		{
			left = nullptr;
			right = nullptr;
		}

		Node(Car elem, Node* left, Node* right)
		{
			this->elem = elem;
			this->left = left;
			this->right = right;
		}

		friend ostream& operator<<(ostream& A, Node Elem)
		{
			A << Elem.elem;
			return A;
		}

		void Add(Car elem)
		{
			if (elem.getNumber() < this->elem.getNumber())
			{
				if (this->left == nullptr) {
					left = new Node(elem, nullptr, nullptr);
				}
				else
				{
					this->left->Add(elem);
				}
			}
			else
			{
				if (this->right == nullptr) {
					right = new Node(elem, nullptr, nullptr);
				}
				else
				{
					this->right->Add(elem);
				}
			}
		}

		void print(ostream& out) {
			if (this->left != nullptr) {
				left->print(out);
				if (this->right != nullptr) {
					right->print(out);
					out << this->elem << ' ';
				}
				else {
					out << this->elem << ' ';
				}
			}
			else if (this->right != nullptr) {
				right->print(out);
				out << this->elem << ' ';
			}
			else {
				out << this->elem << ' ';
			}
		}

		Car find(int numToFind) {
			if (numToFind > this->elem.getNumber())
			{
				if (this->right != nullptr)
				{
					return right->find(numToFind);
				}
				else {
					throw invalid_argument("error");
				}
			}
			else if (numToFind < this->elem.getNumber())
			{
				if (this->left != nullptr)
				{
					return left->find(numToFind);
				}
				else {
					throw invalid_argument("error");
				}
			}
			else {
				return this->elem;
			}
		}
	};

	Node* Root;


public:

	void Add(Car elem)
	{
		if (Root == nullptr)
		{
			Root = new Node(elem, nullptr, nullptr);
		}
		else
		{
			Root->Add(elem);
		}
	}

	Car find(int numToFind) {
		if (Root == nullptr)
		{
			throw invalid_argument("error");
		}
		else if (Root->elem.getNumber() == numToFind)
		{
			return Root->elem;
		}
		else
		{
			Root->find(numToFind);
		}
	}

	friend ostream& operator<<(ostream& out, Tree copy) {
		copy.Root->print(out);
		return out;
	}

	Tree() {
		Root = nullptr;
	}


};


int main() {
	//Tree DAI;
	int userChoise = -1;

	while (userChoise == 0)
	{
		cout << "0 - exit\n\n1 - add fine receipt\n2 - print all receipts\n3 - print receipt by number\n4 - print by number range\n\n";
		cin >> userChoise;
	}



}