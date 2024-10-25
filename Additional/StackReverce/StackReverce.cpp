#include <iostream>

using namespace std;

class Stack {
    int* arr;
    int lengh;
    int size;
public:
    Stack() {
        arr = new int[10];
        lengh = 0;
        size = 10;
    }

    void push(int elem) {
        int* newArr = new int[size + 1];
        size += 1;
        for (int i = 0; i < lengh; ++i)
        {
            newArr[i] = arr[i];
        }
        newArr[lengh] = elem;
        lengh++;
        delete[] arr;
        arr = newArr;

    }

    int pop() {
        if (lengh != 0)
        {
            int temp = arr[lengh - 1];
            lengh--;
            return temp;
        }

    }

    bool isEmpty() {
        if (lengh > 0)
        {
            return false;
        }
        return true;
    }

    int getLengh() {
        return lengh;
    }

    int peek() {
        if (lengh != 0) {
            return arr[lengh - 1];
        }
    }

    friend ostream& operator<<(ostream& out, Stack stack) {
        out << "[";
        for (int i = 0; i < stack.getLengh(); i++) {
            out << stack.arr[i] << ", ";
        }
        out << "]";

        return out;
    }

   
};
void reverseStack(Stack& stack) {
    Stack tempStack;

    while (!stack.isEmpty()) {
        tempStack.push(stack.pop());
    }

    stack = tempStack;
}

Stack operator*(int a, Stack& stack) {
    Stack result;
    int temp = 0;
    int val = 0;
    reverseStack(stack);

    while (!stack.isEmpty()) {
        val = ((stack.pop() * a) + temp);
        result.push(val % 10);
        temp = val / 10;
    }
    while (temp > 0) {
        result.push(temp % 10);
        temp /= 10;
    }

    return result;
}

Stack numToStack(int num) {
    Stack ret;
    while (num > 9) {
        int push = num % 10;
        ret.push(push);
        num = num / 10;
    }
    ret.push(num);
    return ret;
}

Stack factorial(int num, Stack& stack) {
    if (num <= 0)
    {
        reverseStack(stack);
        return stack;
    }

    stack = num * stack;

    return factorial(num - 1, stack);
}

int main()
{
    int a = 0;

    while (true) {
        cin >> a;

        if (a > 1)
        {
            Stack stack1 = numToStack(a * (a - 1));
            a = a - 2;
            cout << factorial(a, stack1) << endl;
        }
        else {
            cout << "[1, ]" << endl;
        }

    }
}
