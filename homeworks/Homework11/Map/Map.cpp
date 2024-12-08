#include "Dictionary.h"

string ReadFromFile(string& filepath) {
	fstream file(filepath);
	string line;
	if (file.is_open())
		cout << "OK";

	getline(file, line);
	
	file.close();
	return line;
}


int main()
{

	string text = "The sun. was setting, painting .the sky in vibrant shades of orange and pink. The sun was warm, and the sun slowly disappeared behind the hills. The sky changed, and the sky became darker as the sun faded.";
	Dictionary dict(text);

	cout << dict << endl;

	cout << endl;

	cout << dict.theMostUsedWord();

	cout << endl;
	cout << endl;


	string filepath = "text.txt";
	
	Dictionary dict2(ReadFromFile(filepath));

	ofstream file(filepath);

	cout << dict2 << endl;

	cout << endl;

	cout << dict2.theMostUsedWord();

	cout << endl;
	cout << endl;

	file << dict2;

}