#include "Car.h"

Car::Car()
{
    this->name = "newCar";
    this->year = 1;
    this->price = 1;
    this->volume = 1;
}

Car::Car(string name, int year, int volume, int price) : name(name), year(year), volume(volume), price(price){}

string Car::getName()
{
    return this->name;
}

int Car::getYear()
{
    return this->year;
}

int Car::getVolume()
{
    return this->volume;
}

int Car::getPrice()
{
    return this->price;
}

bool Car::operator==(Car car)
{
    return this->name == car.name && this->price == car.price && this->volume == car.volume && this->year == car.year;
}

ostream& operator<<(ostream& out, const Car& car)
{
    out << "Name: " << car.name << "\nYear: " << car.year << "\nVolume: " << car.volume << "\nPrice: " << car.price;
    return out;
}

istream& operator>>(istream& in, Car& car)
{
    cout << "Name: ";
    in >> car.name;
    cout << "Year: ";
    in >> car.year;
    cout << "Volume: ";
    in >> car.volume;
    cout << "Price: ";
    in >> car.price;

    return in;
}
