#include "BaseClass.h"
#include <iostream>

int roots::A()
{
    return this->a;
}
int roots::B()
{
    return this->b;
}
int roots::C()
{
    return this->c;
}

bool roots::isLogocal()
{
    if (this->a == 0) {
        if (this->b == 0)
        {
            std::cout << "X = 0" << std::endl;
            return false;
        }
        else
        {
            std::cout << "Go to school!" << std::endl;
            return false;
        }
    }
    return true;
}

void roots::A(int a)
{
    this->a = a;
}
void roots::B(int b)
{
    this->b = b;
}
void roots::C(int c)
{
    this->c = c;
}

roots::roots()
{
    this->a = 0;
    this->b = 0;
    this->c = 0;
}

roots::roots(int a, int b, int c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

roots::roots(int a, int b)
{
    this->a = a;
    this->b = b;
}