#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;


class Dictionary {
	map <string, int> dictionary;

public:
	Dictionary(string text) {
        auto begin = text.begin();

        while (true) {
            auto index = find(begin, text.end(), ' ');
            string newWord = string(begin, index);

            for (size_t i = 0; i < newWord.length(); i++)
            {
                newWord[i] = tolower(newWord[i]);
            }

            if (ispunct(newWord[0])) {
                newWord = newWord.substr(1);
            }
            else if (ispunct(newWord[newWord.length() - 1])) {
                newWord = newWord.substr(0, newWord.length() - 1);
            }

            auto it = this->dictionary.find(newWord);
            if (it == this->dictionary.end()) {
                
                this->dictionary.insert({ newWord, 1 });
            }
            else {
                it->second++;
            }
            if (index == text.end())
            {
                break;
            }

            begin = index + 1;

            
        }
	}

    string theMostUsedWord() {
        int max = 0;
        string ret;

        for_each(this->dictionary.begin(), this->dictionary.end(), [&max](pair <string, int> elem) {
            if (elem.second > max)
            {
                max = elem.second;
            }
            });
        for_each(this->dictionary.begin(), this->dictionary.end(), [&max, &ret](pair <string, int> elem) {
            if (elem.second == max)
            {
                ret = elem.first;
            }
            });

        return ret;
    }

	friend ostream& operator<<(ostream& out, const Dictionary& dict) {
		for_each(dict.dictionary.begin(), dict.dictionary.end(), [&out](pair <string, int> elem) {out << "\n\033[0m word: \033[32m" << elem.first << "\n\033[0m Repeated: \033[33m" << elem.second << endl; });
        cout << "\033[0m" << endl;
		return out;
	}




    friend ofstream& operator<<(ofstream& out, const Dictionary& dict) {
        for_each(dict.dictionary.begin(), dict.dictionary.end(), [&out](pair <string, int> elem) {out << "\nword: " << elem.first << "\n Repeated: " << elem.second << endl; });
        cout << "" << endl;
        return out;
    }

};