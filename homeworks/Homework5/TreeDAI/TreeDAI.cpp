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
	int length;
public:
	Car() {
		this->carNumber = 1000;
		this->size = 0;
		this->length = 0;
		this->offense = nullptr;
	}

	Car(int number, int size, int length, Offenses* offense) {
		this->carNumber = number;
		this->size = size;
		this->offense = offense;
		this->length = length;
	}

	Car(int number) {
		this->carNumber = number;
		this->size = 0;
		this->length = 0;
		this->offense = nullptr;
	}


	int getNumber() {
		return this->carNumber;
	}

	int getSize() {
		return this->size;
	}

	void addOffense(Offenses newOffense) {
		if (this->offense != nullptr)
		{
			if (this->length < this->size)
			{
				this->offense[this->length] = newOffense;
				this->length++;
			}
			else {
				Offenses* temp = new Offenses[size * 2];
				for (size_t i = 0; i < size; i++)
				{
					temp[i] = offense[i];
				}
				temp[this->length] = newOffense;
				this->length++;
				delete[] offense;
				offense = temp;
				size *= 2;
			}
			
		}
		else {
			this->size = 10; 
			this->offense = new Offenses[this->size];
			this->offense[this->length] = newOffense;
			this->length++;
		}
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
		out << "\nTotal " << car.length << " offenses" << endl;

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
//
//Car addNewOffense(Car*& add, int carNum, bool& toAdd) {
//	int choise;
//	
//	return newCar;
//}

void addAOffense(Car& car, bool& toAdd, int choise) {
	switch (choise)
	{
	case 1:
		car.addOffense(speeding);
		break;
	case 2:
		car.addOffense(illegal_parking);
		break;
	case 3:
		car.addOffense(running_a_red_light);
		break;
	case 4:
		car.addOffense(no_seatbelt);
		break;
	case 5:
		car.addOffense(phone_use_while_driving);
		break;
	default:
		toAdd = false;
		cout << "wrong choose" << endl;
		break;
	}
}


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
			bool add = true;
			int carNum;
			int choise;
			cout << "Enter car number: ";
			cin >> carNum;
			cout << endl;
			try {
				Car& temp = DAI.find(carNum);
				cout << "1 - speeding\n2 - illegal_parking\n3 - running_a_red_light\n4 - no_seatbelt\n5 - phone_use_while_driving\n" << endl;
				cin >> choise;
				addAOffense(temp, add, choise);
				
			}
			catch (exception) {
				Car newCar(carNum);
				cout << "1 - speeding\n2 - illegal_parking\n3 - running_a_red_light\n4 - no_seatbelt\n5 - phone_use_while_driving\n" << endl;
				cin >> choise;
				addAOffense(newCar, add, choise);
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
			cout << endl;
			try {
				cout << DAI.find(numFind) << endl;
			}
			catch (exception) {
				cout << "nothing found" << endl;
			}
			system("pause");
			system("cls");

		}
	}



}