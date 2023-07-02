#include "includes&&headers.h"
int file_write(string nick, int attempts)
{
    fstream file("gamedata.txt",ofstream::app);
    if (!file.is_open()) {
        cout << "Error opening file\n";
        return -1;
    }
    file << nick << " " <<  attempts << endl;
    file.close();
    return 0;
}