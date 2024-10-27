#include <iostream>
using namespace std;

class Buss {
private:
	int BusNumber;
	int RouteNumber;
	int sits;
	string Driver;
public:
	Buss() {
		BusNumber = 1939;
		Driver = "Michail";
		RouteNumber = 9;
		sits = 30;
	}
	Buss(int BussNum, string name, int route, int Sits) {
		BussNum = BusNumber;
		name = Driver;
		route = RouteNumber;
		Sits = sits;
	}
	friend ostream& operator<<(ostream& wiwod, Buss Bus) {
		wiwod << Bus.BusNumber << " ";
		wiwod << Bus.Driver << " ";
		wiwod << Bus.RouteNumber << " ";
		wiwod << Bus.sits << " ";
		wiwod << endl;
		return wiwod;
	}

	friend istream& operator>>(istream& in, Buss& Bus) {
		int newBN, newRN, newS;
		string D;
		cout << "Bus number: ";
		in >> Bus.BusNumber;
		cout << "\n\nRoute number: ";
		in >> Bus.RouteNumber;
		cout << "\n\nDriver: ";
		in >> Bus.Driver;
		cout << "\n\nNumber of sits: ";
		in >> Bus.sits;

		return in;



	}

	bool operator > (Buss& bilshe) {
		if (this->BusNumber > bilshe.BusNumber) {
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator > (int bilshe) {
		if (this->BusNumber > bilshe) {
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator < (Buss& menshe) {
		if (this->BusNumber < menshe.BusNumber) {
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator < (int menshe) {
		if (this->BusNumber < menshe) {
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator == (Buss& rivne) {
		if (this->BusNumber == rivne.BusNumber) {
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator == (int Num) {
		if (Num == this->BusNumber) {
			return true;
		}
		else
		{
			return false;
		}
	}
	~Buss() {

	}
};


class Tree
{
private:
	struct Node
	{
		Buss elem;
		Node* left;
		Node* right;
		Node() : elem(Buss())
		{
			left = nullptr;
			right = nullptr;
		}
		Node(Buss elem, Node* left, Node* right)
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
		void Add(Buss elem)
		{
			if (elem < this->elem)
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
			if (this->left != nullptr)
			{
				left->print(out);
			}
			else if (this->right != nullptr)
			{
				right->print(out);
			}
			else {
				out << this->elem;
			}
		}

		Buss find(int BussNumber) {
			if (this->elem == BussNumber) {
				return this->elem;
			}
			else if (this->elem < BussNumber) {
				if (this->right != nullptr) {
					return this->right->find(BussNumber);
				}
				else
				{
					throw exception();
				}
			}
			else {
				if (this->left != nullptr) {
					return this->left->find(BussNumber);
				}
				else
				{
					throw exception();
				}
			}

		}
	};
	Node* Root;


public:

	void Add(Buss elem)
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
	Buss find(int BussNumber) {
		if (Root == nullptr) {
			cout << "error, not found";
		}
		else
		{
			return Root->find(BussNumber);
		}


	}

	Tree() {
		Root = nullptr;
	}
	~Tree()
	{

	}
};


int main() {
	setlocale(LC_ALL, "ukr");
	int Menu = -1;
	Tree newTree;
	while (Menu != 0) {
		cout << "choose: \n";
		cout << "1. Find by key\n";
		cout << "2. add" << endl;
		cin >> Menu;
		switch (Menu)
		{
		case 1:
		{
			int BussNum;
			cout << "Bus Num - ";
			cin >> BussNum;
			try {
				cout << newTree.find(BussNum);
			}
			catch (exception) {
				cout << "no elem" << endl;
			}
			break;
		}
		case 2:
		{
			Buss newBuss;
			cin >> newBuss;
			newTree.Add(newBuss);

			break;
		}
		default:
			break;
		}
	}
}