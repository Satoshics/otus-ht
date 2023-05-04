#include "includes&&headers.h"
int rand_num(){
    int max_val = level();
    int num = max_val + 1; 
    while(num > max_val) {
        srand(time(nullptr)); 
        num = rand() % (max_val + 1); 
    }
    return num;
}