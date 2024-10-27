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
		return this->carNumber;
	}

	int getSize() {
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
			switch (car.offense[i])
			{
			case 0:
				out << "Speeding" << endl;
				break;
			case 1:
				out << "Illegal parking" << endl;
				break;
			case 2:
				out << "Running a red light" << endl;
				break;
			case 3:
				out << "No seatbelt" << endl;
				break;
			case 4:
				out << "Phone use while driving" << endl;
				break;
			default:
				break;
			}
		}
		out << "\nTotal " << car.size << " offenses" << endl;

		return out;
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

		Car& find(int numToFind) {
			if (numToFind > this->elem.getNumber())
			{
				if (this->right != nullptr)
				{
					return right->find(numToFind);
				}
				else {
					throw exception("error");
				}
			}
			else if (numToFind < this->elem.getNumber())
			{
				if (this->left != nullptr)
				{
					return left->find(numToFind);
				}
				else {
					throw exception("error");
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

	Car& find(int numToFind) {
		if (Root == nullptr)
		{
			throw exception("error");
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
		if (copy.Root != nullptr)
		{
			copy.Root->print(out);
		}
		else {
			out << "empty";
		}
		return out;
	}

	Tree() {
		Root = nullptr;
	}


};


int main() {
	Tree DAI;
	int userChoise = -1;

	while (userChoise != 0)
	{
		system("cls");
		cout << "0 - exit\n\n1 - add fine receipt\n2 - print all receipts\n3 - print receipt by number\n\n";
		cin >> userChoise;
		system("cls");
		if (userChoise == 1)
		{
			int carNum;
			cout << "Enter car number: ";
			cin >> carNum;
			cout << endl;
			try {
				Car& temp = DAI.find(carNum);
				cout << "1 - speeding\n2 - illegal_parking\n3 - running_a_red_light\n4 - no_seatbelt\n5 - phone_use_while_driving\n" << endl;
				cin >> userChoise;
				switch (userChoise)
				{
				case 1:
					temp.addOffense(speeding);
					break;
				case 2:
					temp.addOffense(illegal_parking);
					break;
				case 3:
					temp.addOffense(running_a_red_light);
					break;
				case 4:
					temp.addOffense(no_seatbelt);
					break;
				case 5:
					temp.addOffense(phone_use_while_driving);
					break;
				default:
					cout << "wrong choose" << endl;
					break;
				}
			}
			catch (exception) {
				Car newCar(carNum);
				bool add = true;
				cout << "1 - speeding\n2 - illegal_parking\n3 - running_a_red_light\n4 - no_seatbelt\n5 - phone_use_while_driving\n" << endl;
				cin >> userChoise;
				switch (userChoise)
				{
				case 1:
					newCar.addOffense(speeding);
					break;
				case 2:
					newCar.addOffense(illegal_parking);
					break;
				case 3:
					newCar.addOffense(running_a_red_light);	
					break;
				case 4:
					newCar.addOffense(no_seatbelt);
					break;
				case 5:
					newCar.addOffense(phone_use_while_driving);
					break;
				default:
					add = false;
					cout << "wrong choose" << endl;
					break;
				}
				if (add)
				{
					DAI.Add(newCar);
				}
			}

		}
		else if (userChoise == 2) {
			cout << DAI << endl;
			system("pause");
		}
		else if (userChoise == 3) {
			int numFind;
			cout << "enter number to find: ";
			cin >> numFind;
			system("cls");
			try {
				cout << DAI.find(numFind) << endl;
			}
			catch (exception) {
				cout << "nothing found" << endl;
			}
			system("pause");

		}
	}



}