#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
// #include <map>

/***************************************************************
/********************                 *******************************************
/*						310Div1A                                               */
/********************                 *******************************************
/***************************************************************/

int main()
{
	unsigned long n,k;
	std::cin>>n>>k;

	int kval=k;
	// std::vector<std::vector<int> > vec;
	// std::vector<int> temp;
	// temp.reserve(n);

	int count=0;

	while(k--)
	{
		int num;
		std::cin>>num;

		// if(num==1){count=0;}
		int nextVal=0;
		while(num--)
		{
			int val2;
			std::cin>>val2;
			// std::cout<<val2<<" "<<nextVal<<" "<<count<<" "<<std::endl;
			if(val2!=nextVal+1 && nextVal!=0){count+=num+1;}

			nextVal=val2;
			// temp.push_back(val2);
		}
		// vec.push_back(temp);
	}

	if(count!=0){std::cout<<count*2<<std::endl;}
	if(count==0){count=kval-1;std::cout<<count<<std::endl;}
	// int count=0;
	// for(int i=0;i<temp.size()-1;++i)
	// {
	// 	if(temp[i]==i+1){continue;}
	// 	for(int j=i;j<temp.size();++j)
	// 	{
	// 		if(temp[j]==i+1)
	// 		{
	// 			int tempVal=temp[j];
	// 			temp[j]=temp[i];
	// 			temp[i]=tempVal;
	// 			++count;
	// 		}
	// 	}
	// }
	// std::cout<<count*2+kval-1<<std::endl;
	// std::copy(temp.begin(),temp.end(),std::ostream_iterator<int>(std::cout,","));
	return 0;
}