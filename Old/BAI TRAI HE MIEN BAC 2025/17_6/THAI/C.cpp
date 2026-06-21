#include "prisonlib.h"
int a[129];
int play(int i) {
    int box = i;                    
    for (int cnt = 0; cnt < 64; cnt++) {
        int shirt = watch(box);
        if (shirt == i)    
            return box;
        box = shirt;             
    }
    return box;   
}