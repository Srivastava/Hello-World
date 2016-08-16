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

/***************************************************************
/********************                 *******************************************
/*						INVCNT                                                 */
/********************                 *******************************************
/***************************************************************/

typedef std::vector<long long>::iterator itr;

long long merge(itr left,itr mid,itr right)
{
	
	std::vector<long long> temp(std::make_move_iterator(left),std::make_move_iterator(right));

	itr begin=std::begin(temp);
	itr end=std::end(temp);
	
	std::size_t middle=std::distance(begin,end)/2;
	itr midPoint = std::next(begin,middle);
	
	itr l =begin;
	itr r=midPoint;

	itr i = left;

	long long inv=0;

	while(l<midPoint && r <end)
	{
		// *i=std::move((*l<*r) ? *l++ :*r++);
		// ++i;

		if(*l<*r)
		{
			*i++=std::move(*l++);
		}
		else
		{
			inv+=std::distance(l,midPoint);
			*i=std::move(*r++);
			++i;
		}
		
	}
	

	while(l<midPoint)
	{
		*i=std::move(*l++);
		++i;
	}
	

	while(r<end)
	{
		*i=std::move(*r++);
		++i;
	}

	return inv;
	
}

long long mergeSort(itr left,itr right)
{
	
	long long len=std::distance(left,right);
	
	if(len<=1){return 0;}

	
	std::size_t mid=len/2;
	
	itr midpoint=std::next(left,mid);
	

	
	long long leftInv=mergeSort(left,midpoint);
	long long rightInv=mergeSort(midpoint,right);
	
	
	long long mergeInv=merge(left,midpoint,right);
	
	return leftInv+rightInv+mergeInv;

}

long long nInversions(const std::vector<long long>& number)
{
	std::vector<long long> temp=number;

	long long count=0;
	for(int i=0;i<temp.size();++i)
	{
		for(int j=0;j<temp.size();++j)
		{
			if(temp[i]>temp[j] && i < j)
			{
				++count;
			}
		}
	}
	return count;
}

int main()
{
	long long numofInputs;

	std::cin>>numofInputs;

	long long i=0;
	while(i<numofInputs)
	{
		
		long long n;
		std::cin>>n;
		++i;
		// long long n;
		// if(std::cin>>n){//std::cout<<n<<" * "<<std::endl;++i;}
		// else{continue;}
		std::vector<long long> number;

		for(int j=0;j<n;++j)
		{
			long long element;
			std::cin>>element;
			number.push_back(element);
		}


		std::cout<<mergeSort(number.begin(),number.end())<<std::endl;
		// std::cout<<std::endl;
		// std::copy(number.begin(),number.end(), std::ostream_iterator<int>(std::cout, " ** "));
		
	}
	
	//std::cout<<"Here Main ************"<<std::endl;
	// std::vector<int> v{1,5,6,3,7,8,9,4,2};
	// //std::cout<<"Here Main 1 ***************"<<std::endl;
	// std::cout<<mergeSort(v.begin(),v.end())<<std::endl;
	//std::cout<<"Here Main 2 **************"<<std::endl;
	// std::copy(v.begin(),v.end(), std::ostream_iterator<int>(std::cout, " ** "));
	return 0;
}