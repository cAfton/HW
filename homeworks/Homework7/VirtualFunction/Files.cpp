#include "Files.h"

void File::openFile(ifstream& file, string path)
{
    file.open(path);
}

void File::closeFile(ifstream& file)
{
    file.close();
}

void File::Display(string path)
{
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

void FileASCII::Display(string path)
{

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
