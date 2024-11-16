#include <iostream>

using namespace std;

template<typename T>
class Stack {
    T* arr;
    int lengh;
    int size;
public:
    Stack() {
        arr = new T[10];
        lengh = 0;
        size = 10;
    }

    void push(T elem) {
        if (lengh == size)
        {
            T* newArr = new T[size * 2];
            size *= 2;
            for (int i = 0; i < lengh; ++i)
            {
                newArr[i] = arr[i];
            }
            newArr[lengh] = elem;
            lengh++;
            delete[] arr;
            arr = newArr;
        }
    }

    T pop() {
        if (lengh != 0)
        {
            T temp = arr[lengh];
            lengh--;
            return temp;
        }
        
    }

    T peek() {
        return arr[lengh];
    }
};

int main()
{
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    st.push(10);
    st.push(11);

    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    
}
