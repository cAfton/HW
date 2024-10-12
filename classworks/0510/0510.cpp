#include <iostream>

using namespace std;

template<typename T>
class LinkedList {
private:
    struct Node
    {
        T item;
        Node* next;

        Node(T it, Node* ne) {
            this->item = it;
            this->next = ne;
        }

        Node() {
            this->item = 0;
            this->next = nullptr;
        }
    };

    bool isAvalible(int index) {
        if (index >= 0)
        {
            return true;
        }
        cout << "index over macive" << endl;
        return false;
    }
public:
    Node* first;

    LinkedList() {
        first = nullptr;
    }

    void Add(T elem, int index) {
        if (isAvalible(index))
        {
            if (first != nullptr)
            {
                Node* temp = first; 
                if (index == 0)
                {
                    temp->item = elem;
                    return;
                }
                for (size_t i = 0; i < index - 1; i++)
                {
                    if (temp->next != nullptr)
                    {
                        temp = temp->next;
                    }
                    else {
                        
                        temp->next = new Node(elem, nullptr);
                        return;
                    }
                }
                Node* insert = new Node(elem, temp->next);
                temp->next = insert;
            }
            else {
                first = new Node(elem, nullptr);
            }
        }
    }

    void Delete(int index) {
        if (isAvalible(index))
        {
            if (first != nullptr)
            {
                Node* temp = first;

                if (index == 0)
                {
                    Node* save = first->next;
                    delete first;
                    first = save;
                    return;
                }

                for (size_t i = 0; i < index - 1; i++)
                {
                    if (temp->next != nullptr)
                    {
                        temp = temp->next;
                    }
                    else {
                        temp = nullptr;
                        return;
                    }
                }
                    Node* save1 = temp;
                    Node* save2 = temp->next->next;

                    temp = temp->next;
                    delete temp;
                    temp = save1;
                    temp->next = save2;
            }
            else {
                cout << "your masive is already empty" << endl;
            }
        }
    }



    friend ostream& operator<<(ostream& out, const LinkedList& list) {
        Node* cur = list.first;
        while (cur != nullptr) {
            out << cur->item << endl;
            cur = cur->next;
        }
        delete cur;

        return out;
    }

    ~LinkedList() {
        Node* cur = first;
        while (cur != nullptr) {
            Node* save = cur->next;
            delete cur;
            cur = save;
        }


    }


    
};

int main()
{
    LinkedList <int> list1;

    list1.Add(1, 0);
    list1.Add(2, 1);
    list1.Add(6, 2);
    list1.Add(3, 3);
    list1.Add(9, 4);
    list1.Add(5, 2);
    list1.Add(6, 6);
    list1.Add(7, 7);
    list1.Add(10, 3);
    list1.Add(10, 4);
    list1.Add(10, 0);

    cout << list1 << endl;
    cout << "/////////////////\n" << endl;
    list1.Delete(9);
    cout << "/////////////////\n" << list1 << endl;

}
