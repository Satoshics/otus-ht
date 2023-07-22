#include "includes.h"
uint64_t rand_num(){
    uint64_t max_val = level();
    uint64_t num = max_val + 1; 
    while(num > max_val) {
        srand(time(nullptr)); 
        num = rand() % (max_val + 1); 
    }
    return num;
}