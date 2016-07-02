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

/***************************************************************
/********************                 *******************************************
/*						Little Robber                                                 */
/********************                 *******************************************
/***************************************************************/


// void calcInversions(std::vector<unsigned long long>& height)
// {
// 	int l=1;
// 	unsigned long long prev=height[0],curr;
// 	for(int i=1;i<height.size();i+=2)
// 	{
// 		prev=height[i-1];
// 		// std::cout<<height[i]<<" * "<<std::endl;
// 		// if(!std::is_sorted(height.begin(),height.begin()+i))
// 		// {
// 		// 	std::cout<<l<<" "<<i<<std::endl;
// 		// 	std::sort(height.begin(),height.begin()+i);
// 		// 	l=i;
// 		// }
// 		curr=height[i];

// 		if(prev<curr)
// 		{
// 			l=i+1;
// 			if(i>1)
// 			{

// 				std::cout<<l<<" "<<i-1<<std::endl;
// 				i=i-1;
// 			}

// 		}
// 		else
// 		{
// 			height[i]=prev;
// 			height[i-1]=curr;
// 		}

// 	}

// 	std::cout<<l<<" "<<height.size()<<std::endl;
// 	if(!std::is_sorted(height.begin(),height.end()))
// 	{
// 		calcInversions(height);
// 	}
	
// }

void sortV(std::vector<unsigned long long>& height,int a,int b)
{
	// std::cout<<a-1<<b-1<<std::endl;
	for(int i=a-1;i<b-1;)
	{
		int temp=height[i+1];
		height[i+1]=height[i];
		height[i]=temp;
		// std::cout<<"Here"<<std::endl;
		i+=2;
	}
	// std::sort(height.begin()+a-1,height.begin()+b-1);
}
void calcInversions(std::vector<unsigned long long>& height)
{
	int l=1;
	int r=2;
	int count=0;

	while((r-1)<height.size())
	{
		if(count==0){r=l+1;}
		else{r+=2;}
		++count;
		if(r==height.size())
		{
			std::cout<<l<<" "<<r<<std::endl;
			sortV(height,l,r);
			// std::copy(height.begin(), height.end(), std::ostream_iterator<int>(std::cout, " * "));
			// continue;
			break;
		}

		if(height[r-2]<height[r-1])
		{
			if(r-2!=0)
			{

				std::cout<<l<<" "<<r-2<<std::endl;
			}
			sortV(height,l,r-1);
			// std::copy(height.begin(), height.end(), std::ostream_iterator<int>(std::cout, " * "));
			// std::cout<<std::endl;
			l=r;
			r=l+1;
			// std::cout<<l<<" "<<r<<" "<<height.size()<<std::endl;
			count=0;
		}

		
	}
	if(!std::is_sorted(height.begin(),height.end()))
	{
		calcInversions(height);
	}
	// if(count==height.size()-1 ){std::cout<<l<<" "<<r-2<<std::endl;}
}

int main()
{
	int n;
	std::cin>>n;

	std::vector<unsigned long long> height;
	int count=1;

	unsigned long long prev=0;
	int l=1;
	int r=1;
	while(n--)
	{
		unsigned long long x;
		std::cin>>x;

		// if(count!=1 && count%2==0)
		// {
		// 	if(prev>=x)
		// 	{
		// 		r=count;
		// 	}

		// 	else
		// 	{
		// 		std::cout<<l<<" "<<r<<std::endl;
		// 		l=r;
		// 	}
		// }
		 height.push_back(x);

		// prev=x;
		// ++count;
	}

	calcInversions(height);
	// std::cout<<l<<" * "<<r<<std::endl;

	return 0;
}