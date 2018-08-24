#include "mersenne-twister.h"

#include <stdio.h>

namespace mt_random
{
    MT_Random::MT_Random(int32_t seed)
    {
        setSeed(seed);
    }
            
    void MT_Random::setSeed(int32_t seed)
    {
        Number=0;
        Data[0]=seed;
        for(int i=1; i<COUNT_NUMBER; i++)
        {
            Data[i]=((Data[i-1]^(Data[i-1]>>30))*P1)+i;
        }
    }
    int32_t MT_Random::extrat()
    {
        int32_t s;
        if(Number>=COUNT_NUMBER)
        {
            generate();
            Number=0;
        }
        s=Data[Number]^(Data[Number]>>11);
        
        s=s^((s<<7)&P2);
        
        s=s^((s<<15)&P3);
        Number++;
        return s^(s>>18);
    }

    void MT_Random::generate()
    {
        int32_t n1, n2;
        int32_t s;
        int j=START_GEN_POS;
        for(int i=0; i<COUNT_NUMBER; i++)
        {
            if(j>=COUNT_NUMBER)
            {
                j=0;
            }
            n1=Data[i]&0xFF000000;
            if((i+1)>=COUNT_NUMBER)
            {
                n2=Data[0]&0x000000FF;
            }
            else
            {
                n2=Data[i+1]&0x000000FF;
            }
            if((i+1)>=COUNT_NUMBER)
            {
                Data[i]=((P4|n1)^(Data[0]|n2))^Data[j];
            }
            else
            {
                Data[i]=((P4|n1)^(Data[i+1]|n2))^Data[j];
            }
            j++;
        }
    }
}
