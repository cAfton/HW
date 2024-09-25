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

    string Name();
    string Surname();
    string Fatherly();
    int Age();

    void Name(string setName);
    void Surname(string setSurame);
    void Fatherly(string setFatherly);
    void Age(int setAge);
};
