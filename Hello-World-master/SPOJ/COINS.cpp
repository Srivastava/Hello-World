#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <map>

/***************************************************************
/********************                 *******************************************
/*						COINS                                                   */
/********************                 *******************************************
/***************************************************************/

// int maxCoins(const int& n)
// {
// 	std::vector<int> values;
// 	values.push_back(0);
// 	values.push_back(1);

// 	for(int i=2;i<n+1;++i)
// 	{
// 		int n1=i/2,n2=i/3,n3=i/4;

// 		int sum=(values[n1]+values[n2]+values[n3]);
// 		sum=sum>i?sum:i;
// 		values.push_back(sum);
// 	}

// 	return values[n];
// }

// int main()
// {

// 	int n;
// 	while(std::cin>>n)
// 	{
// 		std::cout<<maxCoins(n)<<std::endl;
// 	}

// 	return 0;
// 

std::map<long long, long long> arr;


long long maxCoins(const long long& n)
{
	
	
	if(n==0){return 0;}

	long long val=arr[n];

	if(val==0)
	{
		long long sum=maxCoins(n/2)+maxCoins(n/3)+maxCoins(n/4);

		val=sum>n?sum:n;
		arr[n]=val;
		
	}

	return val;
}

int main()
{
	arr[0]=0;
	arr[1]=1;
	arr[2]=2;
	arr[3]=3;
	arr[4]=4;
	arr[5]=5;
	arr[6]=6;
	arr[7]=7;
	arr[8]=8;
	arr[9]=9;
	arr[10]=10;
	arr[11]=11;
	
	int n;
	while(std::cin>>n)
	{
		std::cout<<maxCoins(n)<<std::endl;
	}

	return 0;
}