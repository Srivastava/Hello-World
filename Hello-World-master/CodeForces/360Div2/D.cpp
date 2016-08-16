#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
// #include <map>

/***************************************************************
/********************                 *******************************************
/*						D                                                 */
/********************                 *******************************************
/***************************************************************/

unsigned long gcd(unsigned long a, unsigned long b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

unsigned long lcm(unsigned long a, unsigned long b)
{
    unsigned long temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main()
{
	unsigned long n,k;

	// std::cout<<gcd(6,3)<<std::endl;
	std::cin>>n>>k;

	// bool val=false;

	unsigned long s=1;
	while(n--)
	{
		int num;
		std::cin>>num;

		
		s=gcd(k,lcm(s,num));

		// if(num==k){val=true;}
	}
	if(s==k){std::cout<<"Yes"<<std::endl;}
	else{std::cout<<"No"<<std::endl;}

	// if(val==true){std::cout<<"Yes"<<std::endl;}
	// else
	// {
	// 	std::cout<<"No"<<std::endl;
	// }

	return 0;
}

// int main()
// {
// 	int n,k;

// 	std::cin>>n>>k;

// 	bool val=false;
// 	while(n--)
// 	{
// 		int num;
// 		std::cin>>num;

// 		if(num==k){val=true;}
// 	}
// 	if(val==true){std::cout<<"Yes"<<std::endl;}
// 	else
// 	{
// 		std::cout<<"No"<<std::endl;
// 	}

// 	return 0;
// }