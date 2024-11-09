#include "Employer.h"
#include "President.h"
#include "Manager.h"
#include "Worker.h"


int main()
{
	President president("J", 20, 10);
	Manager manager("V", 19, 9);
	Worker worker("N", 19, 1);

	cout << president << endl;
	cout << manager << endl;
	cout << worker << endl;

}
