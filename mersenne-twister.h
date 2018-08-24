#ifndef MERSENNE_TWISTER_H
#define MERSENNE_TWISTER_H

#define COUNT_NUMBER 624
#define START_GEN_POS 397

#include <stdint.h>

namespace mt_random
{
    class MT_Random
    {
    public:
        MT_Random(int32_t seed);
        
        void setSeed(int32_t seed); // инициализация массива
        int32_t extrat(); // получение числа
        void generate(); // генерация нового числа
    private:
        
        int Number;
        int32_t Data[COUNT_NUMBER];
        int32_t P1=0x6C078965;
        int32_t P2=0x9D2C5680;
        int32_t P3=0xEFC60000;  
        int32_t P4=0x9908B0DF;
    };
}




#endif // MERSENNE_TWISTER_H
