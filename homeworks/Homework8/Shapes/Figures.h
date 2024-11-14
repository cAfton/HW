#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>


using namespace std;

class Figures {
public:
	virtual string Print() = 0;

	virtual void Save(string path) = 0;

	virtual void Load(string path) = 0;

	virtual float Area() = 0;

	virtual float Perimetr() = 0;

};