#include "Files.h"

int main()
{
    File workWithFiles;
    FileASCII workWithFilesASCII;
    //FileDuoble workWithFilesDouble;
    string path = "test.txt";

    workWithFiles.Display(path);
    workWithFilesASCII.Display(path);
}
