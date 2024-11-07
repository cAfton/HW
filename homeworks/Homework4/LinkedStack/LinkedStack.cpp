#include <iostream>

using namespace std;

template<typename T>
class LinkedList {
private:
    struct Node
    {
        T item;
        Node* next;

        Node(T item, Node* next) {
            this->item = item;
            this->next = next;
        }

        Node() {
            this->item = 0;
            this->next = nullptr;
        }
    };
    Node* first;

    bool isAvalible(int index) {
        if (index >= 0)
        {
            return true;
        }
        cout << "index over macive" << endl;
        return false;
    }
public:
    LinkedList() {
        first = nullptr;
    }

    Node* getFirst() {
        return this->first;
    }

    void push(T elem) {

        if (first != nullptr)
        {
            Node* temp = first;
            for (; temp->next != nullptr;)
            {
                temp = temp->next;
            }
        temp->next = new Node(elem, nullptr);
        }
        else {
            first = new Node(elem, nullptr);
        }
    }

    T pop() {
        Node* temp = first;

        if (first == nullptr)
        {
            throw invalid_argument("error");
        }
        else if (first->next == nullptr)
        {
            T ret = first->item;
            delete first;
            first = nullptr;
            return ret;
        }
        else {
            for (; temp->next->next != nullptr;)
            {
                temp = temp->next;
            }
            T ret = temp->next->item;
            temp->next = nullptr;
            return ret;
        }
    }

    T peek() {
        if (first != nullptr)
        {
            Node* temp = first;
            for (; temp->next != nullptr;)
            {
                temp = temp->next;
            }
            return temp->item;

        }
        else {
            throw invalid_argument("error");
        }
    }


    friend ostream& operator<<(ostream& out, LinkedList& list) {
        Node* cur = list.getFirst();
        while (cur != nullptr) {
            out << cur->item;
            if (cur->next != nullptr)
            {
                out << " -> ";
            }
            cur = cur->next;
        }
        delete cur;
        out << endl;

        return out;
    }

};

int main()
{
    LinkedList <int> list1;


    list1.push(1);
    list1.push(2);
    list1.push(3);
    list1.push(4);
    list1.push(5);
    list1.push(6);
    list1.push(7);
    cout << list1 << endl;
    cout << "///////////" << endl;

    cout << list1.peek() << endl;

    cout << "///////////" << endl;

    try {
        cout << list1.pop() << endl;
        cout << list1.pop() << endl;
        cout << list1.pop() << endl;
        cout << list1.pop() << endl;
        cout << list1.pop() << endl;
        cout << list1.pop() << endl;
        cout << list1.pop() << endl;
        cout << list1.pop() << endl;
        cout << list1.pop() << endl;
        cout << list1.pop() << endl;
        cout << list1.pop() << endl;
        cout << list1.pop() << endl;
    }
    catch (invalid_argument) {
        cout << "error" << endl;
    }
}
