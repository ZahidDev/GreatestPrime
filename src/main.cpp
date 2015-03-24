#include <iostream>
#include "isPrime.h"
#include "LargestPrime.h"
//DEBUG
//#include <chrono>

using namespace std;

int main()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "              Max Prime Finder V3.0b                 " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
	
	char userContinue = 'y';
	while(userContinue == 'y')
	{
		cout << "High Range #: ";
		unsigned long long maxNum = 2;
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
			char nextMaxPrime = 'y';
			while(nextMaxPrime == 'y')
			{
				//DEBUG
				//using namespace std::chrono;

				if(isPrime(maxNum)) {
					cout<<"The number " << maxNum << " is prime"<<endl;
				}
				else cout<<"The number "<< maxNum << " isn't prime"<<endl;

				//DEBUG
				//auto start = high_resolution_clock::now();

				auto maxPrime = largestPrime(maxNum);
			
				//DEBUG				
				//auto end = high_resolution_clock::now();
				//auto timeSpan = duration_cast<milliseconds>(end-start);
				
				cout << "The Highest Prime # within the given range is "
				<< maxPrime << endl;
				
				//DEBUG
				/*cout << "       ~~That took " << timeSpan.count()
				<< " milliseconds~~        \n"<<endl;*/
				
				cout << "Would you like the next Highest Prime #?(y/n) ";
				cin >> nextMaxPrime;
				cout << endl;

				if(nextMaxPrime == 'y')
					maxNum = maxPrime - 1;
			}
		}
		
		cout << "\nRestart?(y/n) ";
		cin >> userContinue;
		userContinue = tolower(userContinue);
	}
	
	return 0;
}
