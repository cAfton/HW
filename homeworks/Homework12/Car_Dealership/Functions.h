#pragma once
#include "Car.h"


void addNewCar(vector<Car>& cars) {
    Car newCar;
    cin >> newCar;

    cars.push_back(newCar);
}

void viewCars(const vector<Car>& cars) {
    for_each(cars.begin(), cars.end(), [](Car car) {cout << car << endl << endl; });
}

void deleteCar(vector<Car>& cars) {
    Car carToFind;
    cout << "Enter information about car to delete: \n" << endl;
    cin >> carToFind;
    auto it = find(cars.begin(), cars.end(), carToFind);
    cars.erase(it);
}

void sortBy(vector<Car>& cars, int userChoise) {
    if (userChoise == 1)
    {
        sort(cars.begin(), cars.end(), [](Car car1, Car car2) {return car1.getName() > car2.getName(); });
    }
    else if (userChoise == 2) {
        sort(cars.begin(), cars.end(), [](Car car1, Car car2) {return car1.getYear() > car2.getYear(); });
    }
    else if (userChoise == 3) {
        sort(cars.begin(), cars.end(), [](Car car1, Car car2) {return car1.getVolume() > car2.getVolume(); });
    }
    else if (userChoise == 4) {
        sort(cars.begin(), cars.end(), [](Car car1, Car car2) {return car1.getPrice() > car2.getPrice(); });
    }

    viewCars(cars);
}