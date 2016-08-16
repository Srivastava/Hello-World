#include <iostream>
#include <vector>
#include <cmath>

unsigned long long exponential(unsigned long long a,unsigned long long b,unsigned long long n)
{
	int res=1;

	a=a%n;

	while(b)
	{
		if(b & 1)
		{
			res=(res*a)%n;
		}

		b=b>>1;
		a=(a*a)%n;
	}
	return res;
}

int main()
{

	unsigned int numofInputs;
	std::cin>>numofInputs;

	int i=0;
	while(i<numofInputs)
	{
		long long a, b;

		std::cin>>a>>b;

		std::cout<<exponential(a,b,10)<<std::endl;
		
		++i;
	}
	return 0;

}
// int main()
// {
// 	unsigned int numofInputs;
// 	std::cin>>numofInputs;

// 	int i=0;
// 	while(i<numofInputs)
// 	{
// 		long long a, b;

// 		std::cin>>a>>b;

// 		a=a%10;
// 		if(b==0){std::cout<<1<<std::endl;++i;continue;}
// 		b=b%4;

// 		// std::cout<<a<<" "<<b<<std::endl;

// 		if(b==0)
// 		{
// 			long long last=std::pow(a,4);
// 			last=last%10;
// 			if(a==0){last=1;}
// 			std::cout<<last<<std::endl;
// 		}

// 		else
// 		{
// 			long long last=std::pow(a,b);
// 			last=last%10;
// 			std::cout<<last<<std::endl;
			
// 		}

// 		++i;
// 	}
// 	return 0;
// }