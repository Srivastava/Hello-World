#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>

int max(int a,int b,int c)
{
	if(c>=a&&c>=b)return c;
	return a>b?a:b;

}

int main()
{

	unsigned long n;
	std::cin>>n;

	int size=n;

	std::vector<unsigned long long> values;
	while(n--)
	{
		unsigned long long val;
		std::cin>>val;

		values.push_back(val);

	}

	std::vector<int> inc(size,0),dec(size,0);
	inc[0]=1;dec[size-1]=1;

	for(int i=1;i<size;++i)
	{
		inc[i]=values[i]>values[i-1] ? inc[i-1]+1:1;
		dec[size-1-i] =  values[size-1-i]<values[size-i] ? dec[size-i] +1:1;
	}

	// std::copy(inc.begin(),inc.end(),std::ostream_iterator<int>(std::cout," "));
	// std::cout<<std::endl;

	// std::copy(dec.begin(),dec.end(),std::ostream_iterator<int>(std::cout," "));
	// std::cout<<std::endl;

	unsigned long ans=0;
	for(int i=1;i<size-1;++i)
	{
		int temp=0;
		if(values[i-1]<values[i+1]-1 && (inc[i]==1 || dec[i]==1))
		{
			temp=inc[i-1]+dec[i+1]+1;
		}

		else if(values[i-1]<values[i]){temp=inc[i-1]+2;}
		else if(values[i]<values[i+1]){temp=dec[i+1]+2;}
		else temp = max(inc[i-1]+1,dec[i+1]+1,0);

		ans=max(temp,ans,inc[i]);
		// std::cout<<ans<<",";
	}
	ans=max(ans,inc[size-2]+1,dec[1]+1);
	std::cout<<ans<<std::endl;
	return 0;
}
// int main()
// {

// 	unsigned long n;
// 	std::cin>>n;

// 	std::vector<unsigned long long> values;
// 	while(n--)
// 	{
// 		unsigned long long val;
// 		std::cin>>val;

// 		values.push_back(val);

// 	}

// 	unsigned long long left=0,right=0,max=0;
// 	bool change=false;

// 	for(int i=1;i<values.size();++i)
// 	{
// 		// left=i-1;
// 		// right=i+1;
// 		// if(values[i]<values[i-1] && values[i+1]<values[i-1])
// 		// {
// 		// 	left=i;
// 		// 	// if(max<right-left){max=right-left;}
// 		// }
// 		right=i;
// 		if(values[i]<values[i-1])
// 		{
// 			if(max<right-left+1){max=right-left+1;}
// 			if(change)
// 			{
// 				change=false;
// 			}
// 			else
// 			{
// 				change=true;	
// 				left=i;
// 			}
// 			// change=true;
// 		}
// 		// else if(change==true)
// 		// {
// 		// 	if(values[left]>values[right])
// 		// 	{

// 		// 	}
// 		// }

// 		if(i+1==values.size())
// 		{
// 			if(max<right-left+1){max=right-left+1;}
// 		}
// 	}

// 	std::cout<<max<<std::endl;

// 	return 0;
// }