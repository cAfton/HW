1#include "Handbook.h"

int main()
{
	Handbook hand;

    string path = "text.txt";
    hand.Load("text.txt");


    hand.Save(path);


    try {
        cout << hand.findByName("Auto Galaxy").getCompanyName() << endl;
        cout << hand.findByDirector("Ethan Davis").getCompanyName() << endl;
        cout << hand.findByNumber("3652582635").getCompanyName() << endl;
        cout << hand.findByActivity("Tourism").getCompanyName() << endl;
    }
    catch (runtime_error) {
        cout << "didnt found" << endl;
    }
}