#include "Date.h"

int main()
{
    Date date1(7, 9, 2009);
    Date date2(29, 10, 2008);

    cout << date1 << endl;

    date1++;

    cout << date1 << endl;

    ++date1;

    cout << date1 << endl;

    date1--;

    cout << date1 << endl;

    --date1;

    cout << date1 << endl;

    cout << date1 + date2 << endl;

    cout << date1 - date2 << endl;
}
