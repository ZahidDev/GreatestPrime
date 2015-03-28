#include <stdint.h>
#include "isPrime.h"

bool isPrime(int_fast64_t Number) //Checks for Prime Validity
{
    auto iterate = 2;
    bool isPrime = 1;
    float half = Number / 2;

    while (isPrime && iterate <= half) {
        if (Number % iterate == 0)
            isPrime = 0;
        iterate++;
    }

    return isPrime;
}