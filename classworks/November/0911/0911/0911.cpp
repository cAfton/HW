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


	Employer** allWorkers = new Employer*[3];

	cout << "////////////" << endl;

	allWorkers[0] = &president;
	allWorkers[1] = &manager;
	allWorkers[2] = &worker;

	for (size_t i = 0; i < 3; i++)
	{
		allWorkers[i]->Work(8 - (2 * i));
	}

	for (size_t i = 0; i < 3; i++)
	{
		cout << allWorkers[i]->Print() << endl;
	}
}
