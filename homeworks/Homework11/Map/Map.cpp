#include "Dictionary.h"

int main()
{

	string text = "The sun. was setting, painting .the sky in vibrant shades of orange and pink. The sun was warm, and the sun slowly disappeared behind the hills. The sky changed, and the sky became darker as the sun faded.";
	Dictionary dict(text);

	cout << dict << endl;

	cout << endl;

	cout << dict.theMostUsedWord();

	cout << endl;
	cout << endl;


}