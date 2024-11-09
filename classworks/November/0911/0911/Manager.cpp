#include "Manager.h"

string Manager::Print()
{
    string res = "Silver: " + to_string(this->silver);
    return res;
}

void Manager::Work(int works)
{

    cout << "I'm working for " << works << endl;
    this->silver += (works / 100);
}

ostream& operator<<(ostream& out, Manager& man)
{
    out << static_cast<Employer&>(man) << "\nManager" << endl;
    out << man.Print() << endl;

    return out;
}
