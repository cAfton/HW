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
	int calc();

};