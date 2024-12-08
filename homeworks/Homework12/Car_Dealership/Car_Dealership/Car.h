#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Car {
    string name;
    int year;
    int volume;
    int price;
public:
    Car();

    Car(string name, int year, int volume, int price);

    string getName();

    int getYear();

    int getVolume();

    int getPrice();

    friend ostream& operator<<(ostream& out, const Car& car);

    friend istream& operator>>(istream& in, Car& car);

    bool operator==(Car car);

};