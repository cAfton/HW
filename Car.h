#pragma once

enum FulerType
{
	gasoline,
	diedel,
	alternative
};

class Car {
private:
	double engineVolume;//об'єм двигуна
	int weight;//маса
	int pistonCount;//поршні
	FulerType fulerType; //вид палива
	int sitCount;//кі-сть мість
	int tankVolume;//об'єм бака
public:
	Car(double engineVolume1, int weight1, int pistonCount1, FulerType fulerType1, int sitCount1, int tankVolume1) :engineVolume(engineVolume1),
		weight(weight1),
		fulerType(fulerType1),
		sitCount(sitCount1),
		pistonCount(pistonCount1),
		tankVolume(tankVolume1){}//конструктор 
	Car() {
		this->engineVolume = 0;
		this->weight = 0;
		this->pistonCount = 0;
		this->fulerType = alternative;
		this->sitCount = 0;
		this->tankVolume = 0;
	}// Конструктор за замовчуванням
	int Calc() const;
	bool operator>(const Car& car2) const;

	bool operator<(const Car& car2) const;
};