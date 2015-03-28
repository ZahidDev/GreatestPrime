#include "LargestPrime.h"
#include <cmath>
#include <cstring>
#include <iostream>


int_fast64_t largestPrime(int_fast64_t upperBound)    //Eratosthenes Sieve Algorithm
{
    try {

        auto upperBoundSquareRoot = sqrt(upperBound);    //uses the sqrt of the upperBound(max) as minValue
        bool *isComposite = new bool[upperBound + 1];    //Bit array to mark composite #s
        memset(isComposite, 0, (size_t) (sizeof(bool) * (upperBound + 1)));
        for (int_fast64_t m = 2; m <= upperBoundSquareRoot; m++) {
            if (!isComposite[m]) {
                for (int_fast64_t k = m * m; k <= upperBound; k += m)    //makes all multiples of prime #s composite
                    isComposite[k] = true;
            }
        }

        int_fast64_t maxPrime = 2;
        for (int_fast64_t m = upperBound; m >= upperBoundSquareRoot; m--)    //Finds Largest Prime # in range
        {
            if (!isComposite[m]) {
                maxPrime = m;
                break;
            }
        }

        delete[] isComposite;
        return maxPrime;
    }
    catch (const std::bad_alloc) {
        std::cout << "Oops, ran out of space/memory. Use a smaller #! " << std::endl;
        exit(EXIT_FAILURE);
    }

}