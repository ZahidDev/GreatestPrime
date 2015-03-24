#include <iostream>
#include <string>
#include <math.h>

//DEBUG
#include <chrono>

using namespace std;

bool Is_Prime(unsigned long long Number) //Checks for Prime Validity
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

auto LargestPrime(unsigned long long upperBound)	//Eratosthenes Sieve Algorithm
{
	auto upperBoundSquareRoot = sqrt(upperBound);	//uses the sqrt of the upperBound(max) as minValue
	bool *isComposite = new bool[upperBound + 1];	//Bit array to mark composite #s
	for (unsigned long long m = 2; m <= upperBoundSquareRoot; m++) {
		if (!isComposite[m]) {
			for (unsigned long long k = m * m; k <= upperBound; k += m)	//makes all multiples of prime #s composite
				isComposite[k] = true;
		}
	}

	unsigned long long maxPrime = 2;
	for (unsigned long long m = upperBound; m >= upperBoundSquareRoot; m--)	//Finds Largest Prime # in range
	{
		if(!isComposite[m]) {
			maxPrime = m;
			break;
		}
	}

	delete [] isComposite;
	return maxPrime;
}


int main()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "              Max Prime Finder V3.0b                 " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
	
	char contin = 'y';
	while(contin == 'y' || contin == 'Y')
	{
		cout << "High Range #: ";
		unsigned long long maxNum;
		cin >> maxNum;
		while(maxNum < 1)
		{
			cout << "Input # Greater than 1: ";
			cin >> maxNum;
		}
		
		if(maxNum == 1)
		{
			cout << "1 is neither a prime nor a composite #" << endl;
		}
		else
		{	
			char nextMax = 'y';
			while(nextMax == 'y' || nextMax == 'Y')
			{
				//DEBUG
				using namespace std::chrono;

				if(Is_Prime(maxNum)) {
					cout<<"The number " << maxNum << " is prime"<<endl;
				}
				else cout<<"The number "<< maxNum << " isn't prime"<<endl;

				//DEBUG
				auto start = high_resolution_clock::now();

				auto maxPrime = LargestPrime(maxNum);
			
				//DEBUG				
				auto end = high_resolution_clock::now();
				auto timeSpan = duration_cast<milliseconds>(end-start);
				
				cout << "The Highest Prime # within the given range is "
				<< maxPrime << endl;
				
				//DEBUG
				cout << "       ~~That took " << timeSpan.count()
				<< " milliseconds~~        \n"<<endl;
				
				cout << "Would you like the next Highest Prime #?(y/n) ";
				cin >> nextMax;
				cout << endl;
				
				if(nextMax == 'Y' || 'y')
					maxNum = maxPrime - 1;
			}
		}
		
		cout << "\nRestart?(y/n) ";
		cin >> contin;
	}
	
	return 0;
}
