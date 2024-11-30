#include "avtomatithation.h"

ostream& operator<<(ostream& out, information& copy) {
	for_each(copy.trains.begin(), copy.trains.end(), [&out](train tmp) {out << tmp.print() << endl; });
	return out;
}

int main()
{
	information mainA;

	ifstream file;
	file.open("text.txt");
	if (!file.is_open()) {
		cout << "Not Ok";
	}
	string line;
	getline(file, line);
	train one(line);
	
	mainA.add(one);

	cout << mainA;
	
}
