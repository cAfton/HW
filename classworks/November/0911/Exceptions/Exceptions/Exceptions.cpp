#include "StrToInt.h"

int main()
{
	string number;
	while(true)
	{

		cin >> number;

		try {
			cout << StrToInt::doWork(number) << endl;
		}
		catch (out_of_range er) {
			cout << er.what() << endl;
		}
	}
}
