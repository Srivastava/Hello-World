#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>

/***************************************************************
/********************                 *******************************************
/*						AGGRCOW                                                   */
/********************                 *******************************************
/***************************************************************/

bool minDistance(std::vector<unsigned long>& num,unsigned long& avg,const unsigned long& cows)
{
	std::vector<unsigned long> pos;
	pos.push_back(num[0]);

	unsigned long tempavg=avg;
	bool istrue=true;
	for(int i=0;i<num.size()-1;++i)
	{
		if(num[i+1]-num[i] < avg)
		{
			false;
			break;
		}
		else
		{
			if(tempavg>num[i+1]-num[i])
			{
				tempavg=num[i+1]-num[i];
			}
			else if(tempavg==avg)
			{
				tempavg=num[i+1]-num[i];
			}
		}
	}
	if(istrue)
	{
		avg=tempavg;
	}

	for(unsigned long i=1;i<cows;++i)
	{
		pos.push_back(pos[i-1]+avg);
	}


	// std::vector<bool> test(pos.size(),false);
	// test[0]=true;
	// std::cout<<avg<<" AVG "<<std::endl;
	// std::copy(pos.begin(),pos.end(),std::ostream_iterator<unsigned long>(std::cout," * "));
	// std::cout<<std::endl;
	bool pass=true;
	for(unsigned long i=1;i<pos.size();++i)
	{
		if(std::find(num.begin(),num.end(),pos[i])==num.end())
		{
			// test[i]=true;
			return false;
			break;
		}
		// else
		// {
		// 	pass=false;
		// }
		// // else
		// {
		// 	return avg-1;
		// }
	}
	if(pass)
	{
		unsigned long temp=avg+1;

		if(minDistance(num,temp,cows))
		{
			avg=temp;	
		}
		else
		{
			avg=temp-1;
			return true;
		}
	}


}

int main()
{
	unsigned long nInputs;
	std::cin>>nInputs;

	while(nInputs--)
	{
		unsigned long n,cows;
		std::cin>>n>>cows;

		// unsigned long min=0,max=0;

		std::vector<unsigned long> stall;
		while(n--)
		{
			unsigned long val;
			std::cin>>val;

			stall.push_back(val);
		}

		std::sort(stall.begin(),stall.end());
		unsigned long avg=(stall[stall.size()-1]-stall[0]+1)/cows;
		// std::cout<<minDistance(stall,avg,cows)<<std::endl;
		// std::cout<<avg<<"**"<<std::endl;
		minDistance(stall,avg,cows);
		std::cout<<avg<<std::endl;
	}

	return 0;
}