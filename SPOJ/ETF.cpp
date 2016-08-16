#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <stack>
#include <queue>
#include <iterator>
#include <algorithm>
#include <string>
#include <set>

/***************************************************************
/********************                 *******************************************
/*						ETF                                                 */
/********************                 *******************************************
/***************************************************************/

std::set<int> primeFactors(int n)
{
    std::set<int> primes;
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        // printf("%d ", 2);
        n = n/2;
        primes.insert(2);
    }
 
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
        	primes.insert(i);
            // printf("%d ", i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
    {
     
     primes.insert(n);
        // printf ("%d ", n);
    }
    return primes;
}

int totient(const std::set<int>& primes,const int& n)
{
	double mul=n;
	for(const auto& it:primes)
	{
		mul*=(1.0-1.0/(it));
	}
	return mul;
}

int main()
{

	int nInputs;
	std::cin>>nInputs;
	while(nInputs--)
	{
		unsigned long long val;
		std::cin>>val;

		std::set<int> primes=primeFactors(val);
		// std::copy(primes.begin(),primes.end(),std::ostream_iterator<int>(std::cout,"*"));

		// std::cout<<std::endl;
		std::cout<<totient(primes,val)<<std::endl;
		
	}
	return 0;
}