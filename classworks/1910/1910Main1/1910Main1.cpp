#include <iostream>
#include <math.h>

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
            T* newArr = new T[size + 1];
            size += 1;
            for (int i = 0; i < lengh; ++i)
            {
                newArr[i] = arr[i];
            }
            newArr[lengh] = elem;
            lengh++;
            delete[] arr;
            arr = newArr;
           // cout << "lenght: " << lengh << endl;
            //cout << "element: " << elem << endl;

    }

    T pop() {
        if (lengh != 0)
        {
            T temp = arr[lengh - 1];
            lengh--;
            return temp;
        }

    }

    T peek() {
        return arr[lengh - 1];
    }

    bool isEmpty() {
        if (lengh == 0)
        {
            return true;
        }
        return false;
    }

    int Size() {
        return this->lengh;
    }

    int Lengh() {
        return this->lengh;
    }
};


void reverce(Stack<int>& stack) {
    Stack<int> temp;
    while (!stack.isEmpty())
    {
        temp.push(stack.pop());
    }

    stack = temp;
}


Stack<int> MultiplyStackByNum(int num, Stack<int>& stack) {
    Stack<int> stackFinal;
    int temp = 0;
    while (!stack.isEmpty())
    {

        cout << "counted without temp: " << stack.peek() * num << endl;
        cout << "counted with temp: " << (stack.peek() * num) + temp << endl;
        int val = (stack.pop() * num) + temp;
        cout << "val: " << val << endl;
        temp = val / 10;
        cout << "temp: " << temp << endl;
        int add = val % 10;
        cout << "add: " << add << endl;
        stackFinal.push(add);
        cout << "--------" << endl;

    }
    stackFinal.push(temp);

    return stackFinal;
}

int recurciveFact(int num) {
	if (num == 1)
	{
		return num;
	}

	return num * recurciveFact(num - 1);
}

int stepin(int num, int numDo) {
	if (numDo == 1)
	{
		return num;
	}
	return num * stepin(num, numDo - 1);
}

int subFactorial(int numSub) {
	if (numSub == 1)
	{
		return 0;
	}
	else if (numSub == 0) {
		return 1;
	}
	return (numSub - 1) * (subFactorial(numSub - 1) + subFactorial(numSub - 2));
}
// (n - 1) * (!(n -1) + !(n -2))
//
//Stack<int> factorialStack(int num, Stack<int> stackStart, Stack<int> stackFinal, bool once) {
//    cout << "size: " << stackStart.Size() << endl;
//    cout << "num: " << num << endl;
//    int val = 0;
//    int temp = 0;
//
//    if (once)
//    {
//        int first = (num * (num - 1)) % 10;
//        int second = (num * (num - 1)) / 10;
//        cout << "first: " << first << " || second:" << second << endl;
//        stackStart.push(first);
//        stackStart.push(second);
//        reverce(stackFinal);
//
//        cout << "peek: " << stackStart.peek() << endl;
//    }
//    if (num == 1)
//    {
//        stackFinal.push(temp);
//        return stackFinal;
//    }
//    cout << "\n\n\nwhile: " << endl; 
//    if (!once)
//    {
//        stackFinal = MultiplyStackByNum(num, stackStart);
//    }
//   
//    if (once)
//    {
//        stackFinal = stackStart;
//    }
//    once = false;
//
//    Stack<int> stackNew;
//
//    cout << endl;
//    cout << endl;
//
//    cout << "size: " << stackFinal.Size() << endl;
//    Stack<int> tempStack = stackFinal;
//    cout << "result: " << endl;
//    while (!tempStack.isEmpty()) {
//        cout << tempStack.pop();
//    }
//    cout << endl;
//
//    return factorialStack(num - 1, stackFinal, stackNew, once);
//}
//
//Stack<int> factorial(int num) {
//
//    return num * factorial(num - 1);
//}

Stack<int> factorial(int n)
{
    Stack<int> result;
    result.push(1);
    for (int i = 2; i <= n; i++)
    {
        Stack<int> tempStack;
        int temp = 0;//перенесення для множення
        while (!result.isEmpty())
        {
            int value = result.pop();
            int p = value * i + temp;
            tempStack.push(p % 10); //збероігаємо останню цифру
            temp = p / 10;//переносимо залишок           
        }

        //якщо залишився перенос, додаємо його
        while (temp > 0)
        {
            tempStack.push(temp % 10);
            temp /= 10;
        }
        //перезаписуємо результат з tempStack в result
        while (!tempStack.isEmpty())
        {
            result.push(tempStack.pop());
        }
    }
    return result;
}

int main()
{
    Stack<int> stackStart;
    Stack<int> stackFinal;
	cout << recurciveFact(5) << endl;
	cout << subFactorial(5) << endl;
	cout << stepin(5, 3) << endl;
    //Stack<int> stackFinalRes = factorial(5, stackStart, stackFinal, true);

    cout << "////////////////////////////////////////////////" << endl;

    Stack<int> FinalRes;
    FinalRes.push(1);
    FinalRes.push(5);
    FinalRes.push(4);
    for (; !FinalRes.isEmpty();)
    {
        cout << FinalRes.pop();
    }cout << endl;
    FinalRes.push(1);
    FinalRes.push(5);
    FinalRes.push(4);
    reverce(FinalRes);

    for (; !FinalRes.isEmpty();)
    {
        cout << FinalRes.pop();
    }cout << endl;
}
