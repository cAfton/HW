#pragma once
#include <iostream>
#include <string>

using namespace std;

class Bit_exception: public exception {
	const char* message;
public:
	Bit_exception(const char* error);

	const char* what() const override;
};


class StrToInt {
	unsigned short int static charToInt(char A);
public:
	unsigned short int static doWork(string S);


	unsigned short int static doWorkBinary(string S);


	unsigned short int static doWorkHex(string S);
};


