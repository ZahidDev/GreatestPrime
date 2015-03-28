///////////DEBUG////////////
#include <boost/chrono.hpp>
////////////////////////////
#include "isPrime.h"
#include "LargestPrime.h"

using std::cout;
using std::endl;
using std::cin;

int main() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "              Max Prime Finder V3.1b                 " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

    char userContinue = 'y';
    while (userContinue == 'y') {
        cout << "Limit #: ";
        int_fast64_t limitNum = 2;
        cin >> limitNum;

        while (limitNum < 1) {
            cout << "Enter # that is greater than 0: ";
            cin >> limitNum;
        }

        if (limitNum == 1) {
            cout << "1 is neither a prime nor a composite #" << endl;
        }
        else {
            char nextMaxPrime = 'y';
            while (nextMaxPrime == 'y') {
                if (isPrime(limitNum))
                    cout << "The number " << limitNum << " is prime" << endl;

                else cout << "The number " << limitNum << " isn't prime" << endl;

                //DEBUG
                using namespace boost;
                chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

                auto maxPrime = largestPrime(limitNum);

                //DEBUG
                chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
                typedef chrono::duration<double> sec;
                sec timeSpent = end - start;

                cout << "The Highest Prime # within the given range is "
                << maxPrime << endl;

                //DEBUG
                cout << "\n~~~~~ That took " << timeSpent << "  ~~~~\n" << endl;

                cout << "Would you like the next Highest Prime #?(y/n) ";
                cin >> nextMaxPrime;
                cout << endl;

                if (nextMaxPrime == 'y')
                    limitNum = maxPrime - 1;
            }
        }

        cout << "\nRestart?(y/n) ";
        cin >> userContinue;
        userContinue = (char) tolower(userContinue);
    }

    return 0;
}
