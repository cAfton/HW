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

//
//void reverce(Stack<int> stack) {
//    if (stack.Lengh() > 0)
//    {
//        int* temp = new int[stack.Lengh()];
//        int templengh = stack.Lengh();
//        for (size_t i = 0; i < stack.Lengh() + 1; i++)
//        {
//            cout << "reverce peek pop: " << stack.peek() << endl;
//            temp[i] = stack.pop();
//        }
//
//        for (size_t i = 0; i < templengh; i++)
//        {
//            cout << "reverce peek push: " << stack.peek() << endl;
//
//            stack.push(temp[i]);
//        }
//    }
//
//}


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

Stack<int> factorialStack(int num, Stack<int> stackStart, Stack<int> stackFinal, bool once) {
    cout << "size: " << stackStart.Size() << endl;
    cout << "num: " << num << endl;
    int val = 0;
    int temp = 0;

    if (once)
    {
        int first = (num * (num - 1)) % 10;
        int second = (num * (num - 1)) / 10;
        cout << "first: " << first << " || second:" << second << endl;
        stackStart.push(first);
        stackStart.push(second);
        cout << "peek: " << stackStart.peek() << endl;
    }
    if (num == 1)
    {
        stackFinal.push(1);
        return stackFinal;
    }
    cout << "\n\n\nwhile: " << endl; 
    //reverce(stackStart);
    //cout << "peek after reverce: " << stackStart.peek() << endl;

    if (!once)
    {
        stackFinal = MultiplyStackByNum(num, stackStart);
    }
   
    if (once)
    {
        stackFinal = stackStart;
    }
    once = false;

    Stack<int> stackNew;

    cout << endl;
    cout << endl;

    cout << "size: " << stackFinal.Size() << endl;
    Stack<int> tempStack = stackFinal;
    cout << "result: " << endl;
    while (!tempStack.isEmpty()) {
        cout << tempStack.pop();
    }
    cout << endl;

    return factorialStack(num - 1, stackFinal, stackNew, once);
}



int main()
{
    Stack<int> stackStart;
    Stack<int> stackFinal;
	cout << recurciveFact(5) << endl;
	cout << subFactorial(5) << endl;
	cout << stepin(5, 3) << endl;
    Stack<int> stackFinalRes = factorialStack(5, stackStart, stackFinal, true);


    cout << "////////////////////////////////////////////////" << endl;
    while (!stackFinalRes.isEmpty()) {
        cout << stackFinalRes.pop();
    }
    cout << endl;
    cout << "////////////////////////////////////////////////" << endl;
    Stack<int> tryStack;
    
    tryStack.push(3);
    cout << "first: " << tryStack.peek() << endl;
    tryStack.push(7);
    cout << "second: " << tryStack.peek() << endl;
    cout << "multiple by 5" << endl;
    
    //reverce(tryStack);
    //cout << "after reversed: " << tryStack.peek() << endl;

    Stack<int> printRes = MultiplyStackByNum(5, tryStack);

    for (size_t i = 0;  !printRes.isEmpty(); i++)
    {
        cout << printRes.pop();
    }cout << endl;

}
