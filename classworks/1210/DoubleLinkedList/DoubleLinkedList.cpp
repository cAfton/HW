#include <iostream>
using namespace std;
template <typename T>
class DoubleLinkedList {
	struct Node {
		T element;
		Node* next;
		Node* prew;
		Node() {
			element = 0;
			next = nullptr;
			prew = nullptr;
		}
		Node(T element, Node* next, Node* prew) {
			this->element = element;
			this->next = next;
			this->prew = prew;
		}
	};
	Node* first;
	bool CheckIndex(int index) {
		if (index == 0)
			return true;
		Node* temp = first;
		for (int i = 0; i < index; i++) {
			if (temp == nullptr) {
				return false;
			}
			else {
				temp = temp->next;
			}
		}
		return true;
	};
public:
	DoubleLinkedList() {
		first = nullptr;
	}

	void addElem(T elem, int index) {
		if (CheckIndex(index)) {
			if (first == nullptr) {
				first = new Node(elem, nullptr, nullptr);
			}
			else if (index == 0) {
				Node* temp = new Node(elem, first, nullptr);
				first->prew = temp;
				first = temp;
			}
			else
			{
				Node* temp = first;
				for (size_t i = 0; i < index - 1; i++)
				{
					temp = temp->next;
				}
				if (temp->next != nullptr) {
					temp->next = new Node(elem, temp->next, temp);
					temp = temp->next;
					temp->next->prew = temp;
				}
				else {
					temp->next = new Node(elem, nullptr, temp);
				}
			}
		}
	}

	void deleteElem(int index) {
		if (CheckIndex(index)) {
			if (index == 0) {
				first = first->next;
				delete first->prew;
			}
			else
			{
				Node* temp = first;
				for (size_t i = 0; i < index - 1; i++)
				{
					temp = temp->next;
				}
				if (temp->next != nullptr) {
					temp = temp->next->next;
					temp->prew = temp->prew->prew;
					delete temp->prew->next;
					temp->prew->next = temp;
				}
				else {
					delete temp->next;
					temp->next = nullptr;
				}
			}
		}
	}

	int Count() {
		Node* temp = first;
		int i = 0;
		while (temp != nullptr) {
			temp = temp->next;
			i++;
		}
		return i;
	}

	void addList(DoubleLinkedList list) {
		Node* temp1 = first;
		int index = 1;
		for (; temp1->next != nullptr; temp1 = temp1->next) {
			index++;
		}

		for (; list.first != nullptr; list.first = list.first->next)
		{
			addElem(list.first->element, index);
			index++;
		}
	}

	friend ostream& operator<<(ostream& out, DoubleLinkedList<T>& list) {
		Node* temp = list.first;
		while (temp != nullptr) {
			out << temp->element << '\t';
			temp = temp->next;
		}
		return out;
	}

	void Swap(int index1, int index2) {
		if (index1 < index2)
		{
			int save = index1;
			index1 = index2;
			index2 = save;
		}
		Node* temp = first;
		Node* save1;
		Node* save2;
		for (; index1 != 0; index1--)
		{
			temp = temp->next;
		}
		save1 = temp;
		temp = first;

		for (; index2 != 0; index2--)
		{
			temp = temp->next;
		}
		save2 = temp;

		temp->prew = save1->prew;
		temp->element = save1->element;
		temp->next = save1->next;

		temp = save1;

		temp->prew = save2->prew;
		temp->element = save2->element;
		temp->next = save2->next;
		
	}

	T& operator[](int index) {
		Node* temp = first;
		for (; index != 0; index--)
		{
			temp = temp->next;
		}

		return temp->element;
	}

	~DoubleLinkedList() {
		if (first == nullptr)
		{
			return;
		}
		while ( first->next != nullptr )
		{
			deleteElem(0);
		}
		delete first;
	}

};
int main()
{
	DoubleLinkedList <int> list1;
	DoubleLinkedList <int> list2;
	list1.addElem(1, 0);
	list1.addElem(2, 1);
	list1.addElem(3, 2);
	list1.addElem(4, 3);
	cout << list1 << endl;

	list2.addElem(10, 0);
	list2.addElem(20, 1);
	list2.addElem(30, 2);
	list2.addElem(40, 3);

	cout << list2 << endl;

	cout << "\n\n\n";

	list1.addList(list2);

	cout << list1 << endl;

	cout << "\n\n\n";
	cout << list1 << endl;
	cout << "\n\n\n";


	list1.Swap(2, 4);

	cout << list1 << endl;

}