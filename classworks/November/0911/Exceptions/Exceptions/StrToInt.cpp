#include "StrToInt.h"

unsigned short int StrToInt::charToInt(char A)
{
	switch (A)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	default:
		break;
	}
}

unsigned short int StrToInt::doWork(string S)
{
	unsigned short int num = 0;
	for (size_t i = 0; i < S.length(); i++)
	{
		if (num + charToInt(S[S.length() - 1 - i]) * pow(10, i) < 65536)
		{
			num += charToInt(S[S.length() - 1 - i]) * pow(10, i);
		}
		else {
			throw out_of_range("Too big");
		}
	}
	return num;
}
