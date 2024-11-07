#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class File {
    ofstream filesName;

public:
    File(string path) {
        this->filesName.open(path);

        if (!this->filesName.is_open())
        {
            throw runtime_error("");
        }
    }

    virtual void Display(string path) = 0;

    ~File() {
        if (this->filesName.is_open()) {
            this->filesName.close();
        }
    }

};

class FIleASCII : public File {
public:
    FIleASCII(string path) : File(path) {}

    void Display(string path) {
        cout << 
    }
};

int main()
{
    
    std::cout << "Hello World!\n";
}
