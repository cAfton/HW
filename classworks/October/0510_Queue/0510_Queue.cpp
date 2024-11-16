#include <iostream>

using namespace std;

template<typename T>
class Queue {
    T* arr;
    int lengh;
    int size;
    int start;
public:

    Queue() {
        arr = new T[5];
        lengh = 0;
        size = 5;
        start = 0;
    }

    void push(T elem) {
        if (lengh <= size)
        {
            T* newArr = new T[size * 2];
            size *= 2;
            for (int i = start, k = 0; i < lengh; i++, k++)
            {
                newArr[k] = arr[i];
                //cout << "////////////////////\n" << newArr[k] << " " << arr[i] << endl;
            }
            start = 0;

            newArr[lengh] = elem;
            lengh++;
            delete[] arr;
            arr = newArr;
        }
    }


    T pop() {
        if (lengh - start != 0)
        {
            T temp = arr[start];
            start++;
            return temp;
        }
        else {
            throw invalid_argument("error while poping");
        }
    }

    T peek() {
        return arr[start];

    }

    ~Queue(){
        delete[] arr;
    }
};

int main()
{
    Queue <int> queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    queue.push(6);


    cout << queue.peek() << endl;
    cout << queue.peek() << endl;
    cout << queue.peek() << endl;
    cout << "/////////////////////////////////////////////////////////////" << endl;

    try {
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << "/////////////////////////////////////////////////////////////" << endl;


        cout << queue.pop() << endl;
        cout << queue.pop() << endl;
        cout << queue.pop() << endl;
        cout << queue.pop() << endl;
        cout << queue.pop() << endl;
        cout << queue.pop() << endl;
    }
    catch (invalid_argument) {
        cout << "error " << endl;
    }
}