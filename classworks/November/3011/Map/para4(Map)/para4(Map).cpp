#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Dictionary {

    map<string, string> Word;

public:
    void addWord(string word, string tranclation) {
        auto it = this->Word.find(word);

        if (it == this->Word.end())
        {
            Word.insert({ word, tranclation });
        }
    }

    void DeleteWord(string word) {
        auto it = this->Word.find(word);
        if (it != Word.end())
        {
            Word.erase(word);
        }
    }

    void EditWord(string word, string trans) {
        auto it = Word.find(word);
        if (it == Word.end())
        {
            addWord(word, trans);
        }
        else {
            it->second = trans;
        }
    }

    friend ostream& operator<<(ostream& out, const Dictionary& dict) {
        for_each(dict.Word.begin(), dict.Word.end(), [&out](pair <string, string> ipso) {out << "\nword: " << ipso.first << "\ntranslation: " << ipso.second; });
        return out;
    }
};


int main()
{
    Dictionary diction;
    diction.addWord("Hello", "Pruvit");
    diction.addWord("Hi", "Pruv");
    diction.addWord("kurukuru", "kukururu");

    cout << diction << endl;
    
    diction.DeleteWord("Hi");

    cout << diction << endl;

    diction.EditWord("Nazar", "Love");

    cout << diction << endl;

}