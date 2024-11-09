#include "Manager.h"

string Manager::Print()
{
    string res = "Silver: " + to_string(this->silver);
    return res;
}

void Manager::Work(int works)
{

    cout << "Manager is working for " << works << endl;
    this->silver += (works / 200.);
}

ostream& operator<<(ostream& out, Manager& man)
{
    out << static_cast<Employer&>(man) << "\nManager" << endl;
    out << man.Print() << endl;

    return out;
}
