#include <iostream>

using namespace std;

template<typename T>
class LinkedList {
private:
    struct Node
    {
        T item;
        Node* next;
    };
    Node* first;

    bool isAvalible(int index) {
        if (index >= 0)
        {
            return true;
        }
        return false;
    }
public:
    LinkedList() {
        first = nullptr;
    }

    void Add(T elem, int index) {
        
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
