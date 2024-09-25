#include "Human.h"

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

