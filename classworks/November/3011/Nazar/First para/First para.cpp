#include "avtomatithation.h"

ostream& operator<<(ostream& out, information& copy) {
	for_each(copy.trains.begin(), copy.trains.end(), [&out](train tmp) {out << tmp.print() << endl; });
	return out;
}

int main()
{
	ifstream file;
	file.open("text.txt");
	if (!file.is_open()) {
		cout << "Not Ok";
	}
	string line;
	getline(file, line);



	train one;
	information mainS;
	mainS.add(one);
	information second;
	second.add(one);

	cout << mainS;
}
