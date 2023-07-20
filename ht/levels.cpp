#include "includes.h"
int level()
{
    int level;
    int max_val;
    cout << "Welcome to game guess the num" << endl << "level 0 - from 0 to 1000" <<  endl  << "level 1 - from 0 to 10000" << endl << "level 2 - from 0 to 1 000 000" << endl <<  "level 3 - from 0 to 10 000 000" << endl << "level 4 - from 0 to 1 000 000 000" << endl;
    cout << "Choose your level\n>>>";
    cin >> level;
    if(level < 0 || level > 4){
        cout << "Invalid level, input level normally\n>>>";
        cin >> level;
    }
    switch (level){
        case 0:
            max_val = 1000;
            break;
        case 1:
            max_val = 10000;
            break;
        case 2:
            max_val = 1000000;
            break;
        case 3:
            max_val = 10000000;
            break;
        case 4:
            max_val = 1000000000;
            break;
        default:
            return -1;
    }
    return max_val;
}
