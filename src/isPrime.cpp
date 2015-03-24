#include "isPrime.h"

bool isPrime(unsigned long long Number) //Checks for Prime Validity
{
    unsigned long long iterate = 2;
    bool isPrime = 1;
    float half = Number/2;

    while( isPrime && iterate <= half )
    {
        if ( Number % iterate == 0 )
            isPrime = 0;
        iterate++;
    }

    return isPrime;
}