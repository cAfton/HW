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

    void Add(T elem, int index) {
        if (isAvalible(index))
        {
            if (first != nullptr)
            {
                Node* temp = first; 
                
                for (size_t i = 0; i < index; i++)
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

    void showList() {
        Node* cur = first;
        while (cur != nullptr) {
            cout << cur->item << " -> ";
            cur = cur->next;
        }
        delete cur;
    }
    
};

int main()
{
    LinkedList <int> list1;

    list1.Add(1, 0);
    list1.Add(2, 1);
    list1.Add(12, 0);
    list1.Add(6, 2);
    list1.Add(3, 3);
    list1.Add(16, 3);
    list1.Add(13, 4);
    list1.showList();

}
