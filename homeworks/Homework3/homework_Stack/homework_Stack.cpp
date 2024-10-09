#include <iostream>
#include <string>

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
        else {
            arr[lengh] = elem;
            lengh++;

        }
    }

    T pop() {
        if (lengh != 0)
        {
            lengh--;
            T temp = arr[lengh];
            return temp;
        }

    }

    T peek() {
        return arr[lengh - 1];
    }
};

int main()
{
    Stack<char> stack;
    string text;
    
    getline(cin, text);

    for (size_t i = 0; i < text.size(); i++)
    {
        cout << text[i];
        if (text[i] == '(' || text[i] == '[' || text[i] == '{' || text[i] == '<')
        {
            stack.push(text[i]);
        }

        if (text[i] == ')' || text[i] == ']' || text[i] == '}' || text[i] == '>')
        {
            cout << "  !!! " << stack.peek() << " !!!   ";
            if (stack.peek() != text[i])
            {
                cout << "<-- here is error" << endl;
                break;
            }
            else {
                stack.pop();
            }
        }
    }

}
