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

    friend ostream& operator<<(ostream& out, Stack<int> stack2) {
        out << "[";
        for (; !stack2.isEmpty(); )
        {
            cout << stack2.pop() << ", ";
        } out << "]";
        return out;
    }
    
};
Stack<int> reverce(Stack<int> stack) {
    Stack<int> temp;
    while (!stack.isEmpty())
    {
        temp.push(stack.pop());
    }
    return temp;
}
Stack<int> operator*(int Multiplier1, Stack<int> number) {
    Stack<int> result;
    int temp = 0;
    int val = 0;
    while (!number.isEmpty()) {
        number = reverce(number);
       // cout << "result: " << number << endl;
        val = ((number.pop() * Multiplier1) + temp);
        result.push(val % 10);
        temp = val / 10;
    }
    if (val / 10 != 0) {
        result.push(val / 10);
    }
    return result;

}


void intToStack(int num, Stack<int>& stack) {
    int copy = num;
    int save = copy % 10;
    while (num / 10 != 0)
    {

        int pushh = num / 10;
        stack.push(pushh);
        num = num / 10;
    }

    stack.push(save);
    //cout << "result1: " << stack << endl;

}
//[[[[[[8*7]*6]*5]*4]*3]*2], num = 8

Stack<int> factorial(int num, Stack<int> res, bool once)
{
    cout << "res: " << res << endl;
    if (num == 0)
    {
        return res;
    }
    if (once)
    {
        int save = num * (num - 1);
        //cout << "save: " << save << endl;
        intToStack(save, res);
        num -= 2;
    }
    else {
        res = num * res;
    }

    return (factorial(num - 1, res, false));
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


int main()
{
	cout << recurciveFact(5) << endl;
	cout << subFactorial(5) << endl;
	cout << stepin(5, 3) << endl;

    cout << "//////////////////////////////////////////////// recursive stack factorial: " << endl;

    Stack<int> FinalRes;
    Stack<int> stack1;
    cout << "8! = 40320" << endl;
    //[[[[[[8*7]*6]*5]*4]*3]*2]

    Stack<int> res = factorial(8, FinalRes, true);

    for (;!res.isEmpty();)
    {
        cout << res.pop();
    }cout << endl;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    reverce(stack1);
    for (; !stack1.isEmpty();)
    {
        cout << stack1.pop();
    }cout << endl;
}
