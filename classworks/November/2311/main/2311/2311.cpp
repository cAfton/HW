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


    class Iterator {
        Node* elem;

    public:
        Iterator(Node* list) : elem(list) {}

        Iterator& operator++() {
            if (this->elem != nullptr)
            {
                this->elem = this->elem->next;
                return *this;
            }
        }

        Iterator& operator++(int) {
            if (this->elem != nullptr)
            {
                this->elem = this->elem->next;
                return *this;
            }
        }

        T& operator*() const {
            return this->elem->item;
        }

       

        bool operator!=(const Iterator& ite) const {
            if (ite.elem != this->elem)
            {
                return true;
            }
            else {
                return false;
            }
        }



    };
    Iterator begin() {
        Iterator newIt(first);
        return newIt;
    }

    Iterator end() {
        Iterator newIt(nullptr);
        return newIt;
    }
    
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

    int Count() {
        Node* cur = this->first;
        int Count = 0;
        while (cur != nullptr) {
            cur = cur->next;
            Count++;
        }

        return Count;
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
    LinkedList<int> list;
    list.Add(1, 0);
    list.Add(2, 1);
    list.Add(3, 2);
    list.Add(4, 3);
    list.Add(5, 4);

    LinkedList<int>::Iterator it = list.begin();

    for (; it != list.end(); it++)
    {
        cout << *it << endl;
    }

}