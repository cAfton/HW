#include <iostream>

using namespace std;


class Tree

{

private:

	struct Node

	{
		int elem;
		Node* left;
		Node* right;
		Node()
		{
			elem = 0;
			left = nullptr;
			right = nullptr;
		}
		Node(int elem, Node* left, Node* right)
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
		void Add(int elem)
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

	void Add(int elem)
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

	Tree() {
		Root = nullptr;
	}


};


int main() {
	Tree newTree1;
	newTree1.Add(8);
	newTree1.Add(2);
	newTree1.Add(10);
	newTree1.Add(6);
	newTree1.Add(1);
	newTree1.Add(-4);
	newTree1.Add(5);
	newTree1.Add(-8);
	newTree1.Add(4);
	newTree1.Add(7);
	newTree1.Add(12);
	newTree1.Add(16);
	newTree1.Add(11);


	cout << newTree1 << endl;

	try {
		cout << newTree1.find(-8) << endl;
	}
	catch (invalid_argument) {
		cout << "error" << endl;
	}
}