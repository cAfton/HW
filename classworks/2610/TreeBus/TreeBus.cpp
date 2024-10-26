#include <iostream>
using namespace std;

class Bus
{
public:
	Bus() {
		BusId = 1488;
		Driver = "Michail";
		RouteNumber = 99;
		Sits = 22;
	}
	Bus(int id, string name, int route, int sit) {
		BusId = id;
		Driver = name;
		RouteNumber = route;
		Sits = sit;
	}

	int getBusId() {
		return this->BusId;
	}

	int getRouteNum() {
		return this->RouteNumber;
	}

	friend ostream& operator<< (ostream& wiwod, Bus& Elektron) {
		wiwod << Elektron.BusId << " ";
		wiwod << Elektron.Driver << " ";
		wiwod << Elektron.RouteNumber << " ";
		wiwod << Elektron.Sits << " ";

		return wiwod;
	}

	bool operator> (Bus& bilshe) {
		if (this->BusId > bilshe.BusId) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator< (Bus& menshe) {
		if (this->BusId < menshe.BusId) {
			return false;
		}
		else {
			return true;
		}
	}
	bool operator== (Bus& rivne) {
		if (this->BusId == rivne.BusId) {
			return true;
		}
		else {
			return false;
		}
	}
private:
	int BusId;
	string Driver;
	int RouteNumber;
	int Sits;
};


class Tree
{
private:
	struct Node
	{
		Bus elem;
		Node* left;
		Node* right;
		Node()
		{
			left = nullptr;
			right = nullptr;
		}
		Node(Bus elem, Node* left, Node* right)
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
		void Add(Bus elem)
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

		Bus find(int numToFind) {
			if (numToFind > this->elem.getBusId())
			{
				if (this->right != nullptr)
				{
					right->find(numToFind);
				}
				else {
					throw invalid_argument("error");
				}
			}
			else if (numToFind < this->elem.getBusId())
			{
				if (this->left != nullptr)
				{
					left->find(numToFind);
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

	void Add(Bus elem)
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

	Bus find(int numToFind) {
		if (Root == nullptr)
		{
			throw invalid_argument("error");
		}
		else if (Root->elem.getBusId() == numToFind)
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
	Tree tree;
	int userChoice = 0;
	while (true) {
		cout << "\n1 - add new\n2 - find by" << endl;
		cin >> userChoice;
		if (userChoice == 1)
		{
			int newBusId, newRouteNumber, newSits;
			string newDriver;

			cout << "Bus ID: ";
			cin >> newBusId;
			cout << "\n\nRoute Number: ";
			cin >> newRouteNumber;
			cout << "\n\nDriver's name: ";
			cin >> newDriver;
			cout << "\n\nNumber of sits: ";
			cin >> newSits;

			Bus bus(newBusId, newDriver, newRouteNumber, newSits);
			cout << "new bus:     " << bus << endl;
			tree.Add(bus);
		}
		else if (userChoice == 2) {
			int numToFind;
			cout << "Num to find: ";
			cin >> numToFind;

			Bus res = tree.find(numToFind);
			cout << "found:   " << res;
		}
		else if (userChoice == 3) {
			cout << tree << endl;
		}
	}

}