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


istream& operator>>(istream& in, Human& human)
{
    cout << "Name: ";
    in >> human.name;
    cout << "\nSurname: ";
    in >> human.surname;
    cout << "\nFatherly: ";
    in >> human.fatherly;
    cout << "\nAge: ";
    in >> human.age;

    return in;
}

ostream& operator<<(ostream& out, const Human& human)
{
    out << "Name: " << human.name << "\nSurname: " << human.surname << "\nFatherly: " << human.fatherly << "\nAge: " << human.age;
    return out;
}
