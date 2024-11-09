#include "Worker.h"

string Worker::Print()
{
	string res = "Bronze: " + to_string(this->bronze);

	return res;
}

void Worker::Work(int works)
{
	cout << "Worker is working for " << works << endl;
	this->bronze += (works / 300.);
}

ostream& operator<<(ostream& out, Worker& worker)
{
	out << static_cast<Employer&>(worker) << "\nWorker" << endl;
	out << worker.Print() << endl;

	return out;
}
