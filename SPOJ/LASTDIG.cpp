#include <iostream>
#include <vector>
#include <cmath>


int main()
{
	unsigned int numofInputs;
	std::cin>>numofInputs;

	int i=0;
	while(i<numofInputs)
	{
		long long a, b;

		std::cin>>a>>b;

		a=a%10;
		b=b%4;

		// std::cout<<a<<" "<<b<<std::endl;

		if(b==0)
		{
			int last=std::pow(a,4);
			last=last%10;
			if(a==0){last=1;}
			std::cout<<last<<std::endl;
		}

		else
		{
			int last=std::pow(a,b);
			last=last%10;
			std::cout<<last<<std::endl;
			
		}

		++i;
	}
	return 0;
}