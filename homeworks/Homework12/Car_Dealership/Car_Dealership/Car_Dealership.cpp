#include "Functions.h"

int main()
{
    vector<Car> cars;
    //readFromFile();
    int userChoice = -1;
    do
    {
        system("cls");
        cout << "1 - add new car\n2 - delete car\n3 - view cars\n4 - sort by...\n5 - find by...\n0 - exit\n" << endl;
        cin >> userChoice;
        system("cls");

        switch (userChoice)
        {
        case 1:
            addNewCar(cars);
            break;
        case 2:
            deleteCar(cars);
            break;
        case 3:
            viewCars(cars);
            system("pause");
            break;
        case 4:
            cout << "Sort by\n\n1 - name\n2 - year\n3 - volume\n4 - price\n" << endl;
            cin >> userChoice;
            sortBy(cars, userChoice);
            system("pause");
            break;
        case 5:
            system("cls");
            cout << "Find by\n\n1 - name\n2 - year\n3 - volume\n4 - price\n" << endl;
            cin >> userChoice;
            //findBy();
            system("pause");
            break;
        case 0:
            //writeToFile();
            break;
        default:
            break;
        }
    } while (userChoice != 0);
}
