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
	case 'A':
		return 10;
	case 'B':
		return 11;
	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
	case 'F':
		return 15;
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

unsigned short int StrToInt::doWorkBinary(string S)
{
	short len = S.length();
	if (len <= 16)
	{
		unsigned short int num = 0;
		for (int i = len - 1; i >= 0; i--)
		{
			if (!(S[i] == '1' || S[i] == '0'))
			{
				throw Bit_exception("error");
			}

			if (S[i] == '1')
			{
				num += pow(2, len - 1 - i);
			}
		}
		return num;
	}
	else {
		throw out_of_range("inputed number is too big");
	}
}

unsigned short int StrToInt::doWorkHex(string S)
{
	short len = S.length();
	unsigned short int num = 0;
	for (int i = 0; i <= len - 1; i++)
	{
		if (((S[i] >= '0' && S[i] <= '9') || (S[i] >= 'A' && S[i] <= 'F')))
		{
			if (num > (USHRT_MAX - charToInt(S[i])) / 16 )
			{
				throw out_of_range("");
			}

			num = num * 16 + charToInt(S[i]);
		}
	}

	return num;
}


Bit_exception::Bit_exception(const char* error) : message(error) {}

const char* Bit_exception::what() const
{
	return this->message;
}

