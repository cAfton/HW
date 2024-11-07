#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class File {
public:

    void openFile(ifstream& file, string path) {
        file.open(path);
    }

    void closeFile(ifstream& file) {
        file.close();
    }

    virtual void Display(string path) {
        ifstream file;

        openFile(file, path);
        string line;
        while (!file.eof())
        {
            getline(file, line);
            cout << line << endl;
        }

        closeFile(file);
    }


};

class FileASCII : public File {
public:

    void Display(string path) override { 
        ifstream file;

        openFile(file, path);
        string line;

        while (!file.eof())
        {
            getline(file, line);
            for (size_t i = 0; i < line.length(); i++)
            {
                cout << static_cast<int>(line[i]) << " ";
            }
            cout << endl;
        }

        closeFile(file);
    }
};

int main()
{
    File workWithFiles;
    FileASCII workWithFilesASCII;
    //FileDuoble workWithFilesDouble;
    string path = "test.txt";

    workWithFiles.Display(path);
    workWithFilesASCII.Display(path);
}
