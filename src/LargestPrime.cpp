#include "LargestPrime.h"
#include <math.h>
#include <cstring>

unsigned long long largestPrime(unsigned long long upperBound)	//Eratosthenes Sieve Algorithm
{
    auto upperBoundSquareRoot = sqrt(upperBound);	//uses the sqrt of the upperBound(max) as minValue
    bool *isComposite = new bool[upperBound + 1];	//Bit array to mark composite #s
    memset(isComposite, 0, (size_t) (sizeof(bool) * (upperBound + 1)));
    for (unsigned long long m = 2; m <= upperBoundSquareRoot; m++)
    {
        if (!isComposite[m])
        {
            for (unsigned long long k = m * m; k <= upperBound; k += m)	//makes all multiples of prime #s composite
                isComposite[k] = true;
        }
    }

    unsigned long long maxPrime;
    for (unsigned long long m = upperBound; m >= upperBoundSquareRoot; m--)	//Finds Largest Prime # in range
    {
        if(!isComposite[m])
        {
            maxPrime = m;
            break;
        }
    }

    delete [] isComposite;
    return maxPrime;
}