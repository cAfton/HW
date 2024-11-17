#include <iostream>
#include "quadratic equations.h"
#include "Line.h"

int main()
{
    int choice;
    while (true)
    {
        system("cls");
        std::cout << "Enter the equation you want to solve. Linear or square? [ 1) Linear, 2) square, 0) exit ]\n:";
        std::cin >> choice;
        if (choice == 1) {
            int a;
            std::cout << "\nEnter your numbers like ax + b = 0\na:";
            std::cin >> a;
            std::cout << "\nb:";
            int b;
            std::cin >> b;
            
            Line tmp(a, b);
            tmp.calculation();
        }
        else if (choice == 2) {
            int a;
            std::cout << "\nEnter your numbers like ax^2 + bx + c = 0\na:";
            std::cin >> a;
            std::cout << "\nb:";
            int b;
            std::cin >> b;
            std::cout << "\nc:";
            int c;
            std::cin >> c;

            quadratic tmp(a, b, c);
            tmp.calculation();
        }
        else {
            return 0;
        }

        system("pause");
    }
}