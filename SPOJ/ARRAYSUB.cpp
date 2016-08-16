#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <set>

/***************************************************************
/********************                 *******************************************
/*						ARRAYSUB                                                   */
/********************                 *******************************************
/***************************************************************/

// int main()
// {
// 	unsigned long n,k;

// 	std::cin>>n>>k;
// 	int count=0;
// 	unsigned long max=0;
// 	while(count<n)
// 	{

// 		if(count<k)
// 		{
// 			std::vector<unsigned long> input;
// 			input.reserve(k);

// 			for(int i=0;i<k;++i)
// 			{
// 				int val;
// 				std::cin>>val;

// 				input.push_back(val);
// 				++count;
// 			}
			
// 			std::sort(input.begin(),input.end());
// 			max=input[k-1];
// 			std::cout<<max<<std::endl;
// 		}

// 		int val;
// 		std::cin>>val;
// 		if(max<val)
// 		{
// 			max=val;
// 		}
// 		std::cout<<max<<std::endl;
		
// 	}
// 	return 0;
// }

int main()
{
	unsigned long n,k;

	std::cin>>n;
	unsigned long temp=n;
	

	std::vector<unsigned long> input;
	// input.reserve(k);
	
	while(n--)
	{
		unsigned long val;
		std::cin>>val;

		input.push_back(val);
	}

	std::cin>>k;

	unsigned long count=0;

	// while(count<=temp-k)
	// {
	// 	std::vector<unsigned long> tempArr(input.begin()+count,input.begin()+count+k);
	// 	std::sort(tempArr.begin(),tempArr.end());

	// 	std::cout<<tempArr[k-1]<<" ";
	// 	++count;
	// }

	std::vector<unsigned long> tempArr(input.begin(),input.begin()+k);
	std::sort(tempArr.begin(),tempArr.end());

	unsigned long max=tempArr[k-1];
	unsigned long leave = input[0];
	std::cout<<max<<" ";
	for(int i=1;i<=temp-k;++i)
	{
		if(max<input[i+k-1])
		{
			max=input[i+k-1];
		}
		else if(max==leave)
		{
			std::vector<unsigned long> tempArr1(input.begin()+i,input.begin()+i+k);
			std::sort(tempArr1.begin(),tempArr1.end());
			// std::copy(tempArr1.begin(),tempArr1.end(),std::ostream_iterator<unsigned long>(std::cout,"*"));
			// std::cout<<std::endl;
			max=tempArr1[k-1];
		}
		leave=input[i];
		std::cout<<max<<" ";
	}

	// unsigned long leave=input[0];
	// std::sort(input.begin(),input.begin()+k);

	// unsigned long max=input[k-1];
	// std::cout<<max<<" ";

	// unsigned long count=1;

	// while(count<temp)
	// {
	// 	unsigned long val=input[count];
	// 	leave=input[count-k];
	// 	if(max<val)
	// 	{
	// 		max=val;
	// 	}
	// 	else if(max==leave)
	// 	{
	// 		std::vector<unsigned long> tempArr(input.begin()+count-k+1,input.begin()+count);

	// 		std::sort(tempArr.begin()+count-k+1,tempArr.begin()+count);
	// 		max=tempArr[count-1];
	// 	}

	// 	std::copy(input.begin()+count-k+1,input.begin()+count,std::ostream_iterator<unsigned long>(std::cout,"*"));
	// 	// std::cout<<max<<" ";
	// 	++count;
	// }

	return 0;
}