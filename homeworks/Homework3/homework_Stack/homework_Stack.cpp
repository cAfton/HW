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
        if (this->lengh != 0)
        {
            this->lengh--;
            T temp = arr[lengh];
            return temp;
        }

    }

    T peek() {
        if (this->lengh != 0)
        {
            return arr[lengh - 1];
        }
    }
    bool isEmptyStack() {
        if (lengh == 0)
        {
            return true;
        }
        return false;
    }

    ~Stack() {
        delete[] arr;
    }
};

bool check(char first, char second){
    if ((first == '(' && second == ')') || (first == '[' && second == ']') || (first == '{' && second == '}') || (first == '<' && second == '>'))
    {
        return true;
    }
    return false;
}

int main()
{
    Stack<char> stack;
    string text;
    
    getline(cin, text);
    int i = 0;

    for (size_t i = 0; text[i] != ';'; i++)
    {
        cout << text[i];
        if (text[i] == '(' || text[i] == '[' || text[i] == '{' || text[i] == '<')
        {
            stack.push(text[i]);
        }

        if (text[i] == ')' || text[i] == ']' || text[i] == '}' || text[i] == '>')
        {
            if (check(stack.peek(), text[i]))
            {
                stack.pop();
                
            }
            else {
                cout << "<-- here is error" << endl;
                return 1;
            }
        }
    }
    cout << endl;
    if (stack.isEmptyStack())
    {
        cout << "everything is correct" << endl;
    }
    else {
        cout << "you forgot to close brackets" << endl;
    }

}
