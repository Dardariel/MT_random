#include <stdio.h>
#include "mersenne-twister.h"

using namespace mt_random;

int main(void)
{
    MT_Random *mtr = new MT_Random(0x6C078965);
    
    
    
    for(int i=0; i<COUNT_NUMBER; i++)
    {
        printf("%d ", mtr->extrat());
    }
    printf("\n");
    for(int i=0; i<COUNT_NUMBER; i++)
    {
        printf("%d ", mtr->extrat());
    }
    printf("\n");
    for(int i=0; i<COUNT_NUMBER; i++)
    {
        printf("%d ", mtr->extrat());
    }
    printf("\n");
    for(int i=0; i<COUNT_NUMBER; i++)
    {
        printf("%d ", mtr->extrat());
    }
    printf("\n");
    
    delete mtr;
    return 0;
    
    
}
