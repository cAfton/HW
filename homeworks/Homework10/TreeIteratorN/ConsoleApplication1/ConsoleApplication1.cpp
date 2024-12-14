#include <iostream>
#include <vector>
using namespace std;

class Tree

{

private:


	struct Node

	{
		int elem;
		Node* left;
		Node* right;
		Node* previous;

		Node()
		{
			elem = 0;
			left = nullptr;
			right = nullptr;
			previous = nullptr;
		}
		Node(int elem, Node* left, Node* right, Node* parent)
		{
			this->elem = elem;
			this->left = left;
			this->right = right;
			this->previous = parent;
		}
		friend ostream& operator<<(ostream& A, Node Elem)
		{
			A << Elem.elem;
			return A;
		}
		void Add(int elem)
		{
			if (elem < this->elem)
			{
				if (this->left == nullptr) {
					left = new Node(elem, nullptr, nullptr, this);
				}
				else
				{
					this->left->Add(elem);
				}
			}
			else
			{
				if (this->right == nullptr) {
					right = new Node(elem, nullptr, nullptr, this);
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

		int find(int numToFind) {
			if (numToFind > this->elem)
			{
				if (this->right != nullptr)
				{
					right->find(numToFind);
				}
				else {
					throw invalid_argument("error");
				}
			}
			else if (numToFind < this->elem)
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



	class Iterator {

		Node* item;

	public:
		Iterator(Node* first) : item(first) {}

		void GoDown() {
			while (this->item->left != nullptr || this->item->right != nullptr) {
				if (this->item->left != nullptr) {
					this->item = this->item->left;
				}
				else {
					this->item = this->item->right;
				}
			}
		}

		void GoWidth(){}

		Iterator& operator++(int) {
			if (this->item->previous != nullptr)
			{
				if (this->item->previous->right == this->item)
				{	
					this->item = this->item->previous;
					return *this;
				}
				else {
					if (this->item->previous->right == nullptr)
					{
						this->item = this->item->previous;
						return *this;
					}
					else {
						this->item = this->item->previous->right;
						this->GoDown();
						return *this;
					}
				}
			}
			else {
				this->item = this->item->previous;
				return *this;
			}

		}

		int& operator*() const {
			return this->item->elem;
		}



		bool operator!=(const Iterator& ite) const {
			if (ite.item != this->item)
			{
				return true;
			}
			else {
				return false;
			}
		}



	};
	Iterator begin() {
		Iterator newIt(Root);
		newIt.GoDown();
		return newIt;
	}

	Iterator end() {
		Iterator newIt(nullptr);
		return newIt;
	}

	void Add(int elem)
	{
		if (Root == nullptr)
		{
			Root = new Node(elem, nullptr, nullptr, nullptr);
		}
		else
		{
			Root->Add(elem);
		}
	}

	int find(int numToFind) {
		if (Root == nullptr)
		{
			throw invalid_argument("error");
		}
		else if (Root->elem == numToFind)
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

	void printBreadth() {
		if (Root == nullptr) {
			cout << "Tree is empty." << endl;
			return;
		}

		vector<Node*> queue; 
		queue.push_back(Root); 

		while (!queue.empty()) {
			Node* current = queue.front(); 
			queue.erase(queue.begin()); 

			cout << current->elem << " "; 

			if (current->left != nullptr) {
				queue.push_back(current->left);
			}
			if (current->right != nullptr) {
				queue.push_back(current->right);
			}
		}

		cout << endl;
	}





	Tree() {
		Root = nullptr;
	}


};

int main()
{
	Tree newTree1;
	newTree1.Add(8);
	newTree1.Add(3);
	newTree1.Add(10);
	newTree1.Add(6);
	newTree1.Add(1);
	newTree1.Add(-4);
	newTree1.Add(5);
	newTree1.Add(-9);
	newTree1.Add(4);
	newTree1.Add(7);
	newTree1.Add(12);
	newTree1.Add(16);
	newTree1.Add(11);

	Tree::Iterator it(newTree1.begin());

	for (; it != newTree1.end(); it++)
	{
		cout << *it << " ";
	}


	cout << endl;
	cout << endl;
	cout << newTree1 << endl;

	try {
		cout << newTree1.find(-9) << endl;
	}
	catch (invalid_argument) {
		cout << "error" << endl;
	}	


	newTree1.printBreadth();
}