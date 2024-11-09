#include "StrToInt.h"

int main()
{
	string number;
	/*while(true)
	{

		cin >> number;

		try {
			cout << StrToInt::doWork(number) << endl;
			throw exception();
		}
		catch (exception er) {
			cout << er.what() << endl;
		}
	}*/

	while (true) {
		cin >> number;

		/*try {
			cout << StrToInt::doWorkBinary(number) << endl;
		}
		catch (Bit_exception er) {
			cout << er.what() << endl;
		}
		catch (out_of_range) {
			cout << "number is too big. Try smaller" << endl;
		}
		catch (exception) {
			cout << "unexpected error" << endl;
		}*/


		try {
			cout << StrToInt::doWorkHex(number) << endl;
		}
		catch (out_of_range) {
			cout << "out of range" << endl;
		}
	}

}
