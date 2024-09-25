#include "Human.h"

Human::Human()
{
    this->name = "no_name";
    this->surname = "no_surname";
    this->fatherly = "no_fatherly";
    this->age = 0;
}

Human::Human(string name, string surname, string fatherly, int age)
{
    this->name = name;
    this->surname = surname;
    this->fatherly = fatherly;
    this->age = age;
}

string Human::Name()
{
    return this->name;
}

string Human::Surname()
{
    return this->surname;
}

string Human::Fatherly()
{
    return this->fatherly;
}

int Human::Age()
{
    return this->age;
}

void Human::Name(string setName)
{
    this->name = setName;
}

void Human::Surname(string setSurname)
{
    this->surname = setSurname;
}

void Human::Fatherly(string setFatherly)
{
    this->fatherly = setFatherly;
}

void Human::Age(int setAge)
{
    this->age = setAge;
}

