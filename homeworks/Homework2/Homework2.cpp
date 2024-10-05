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

    bool D1 = date1 != date2;
    bool D2 = date1 == date2;
    cout << (D1 == true ? "true" : "false") << endl;
    cout << (D2 == true ? "true" : "false") << endl;

    D1 = date1 > date2;
    D2 = date1 < date2;
    cout << (D1 == true ? "true" : "false") << endl;
    cout << (D2 == true ? "true" : "false") << endl;

    D1 = date1 >= date2;
    D2 = date1 <= date2;
    cout << (D1 == true ? "true" : "false") << endl;
    cout << (D2 == true ? "true" : "false") << endl;

    date1 = date2;
    cout << date1 << '\t' << date2 << endl;

    date1 += date2;
    cout << date1 << '\t' << date2 << endl;

    date1 -= date2;
    cout << date1 << '\t' << date2 << endl;

    date1(2070, 8, 15);
    cout << date1 << '\t' << date2 << endl;
}
