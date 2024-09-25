#pragma once
#include <iostream>
#include <string>

using namespace std;


class Human {
private:
    string name;
    string surname;
    string fatherly;
    int age;
public:

    Human();
    Human(string name, string surname, string fatherly, int age);

    friend istream& operator>>(istream& in, Human& human);
    friend ostream& operator<<(ostream& out, const Human& human);
};
