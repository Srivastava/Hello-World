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

typedef std::vector<int>::iterator itr;

void merge(itr left,itr mid,itr right)
{
	
	std::vector<int> temp(std::make_move_iterator(left),std::make_move_iterator(right));

	itr begin=std::begin(temp);
	itr end=std::end(temp);
	
	std::size_t middle=std::distance(begin,end)/2;
	itr midPoint = std::next(begin,middle);
	
	itr l =begin;
	itr r=midPoint;

	itr i = left;

	
	while(l<midPoint && r <end)
	{
		*i=std::move((*l<*r) ? *l++ : *r++);
		++i;
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
	
}

void mergeSort(itr left,itr right)
{
	
	int len=std::distance(left,right);
	
	if(len<=1){return;}

	
	std::size_t mid=len/2;
	
	itr midpoint=std::next(left,mid);
	

	
	mergeSort(left,midpoint);
	mergeSort(midpoint,right);
	
	
	merge(left,midpoint,right);
	

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
	// long long numofInputs;

	// std::cin>>numofInputs;

	// long long i=0;
	// while(i<numofInputs)
	// {
		
	// 	long long n;
	// 	std::cin>>n;
	// 	++i;
	// 	// long long n;
	// 	// if(std::cin>>n){//std::cout<<n<<" * "<<std::endl;++i;}
	// 	// else{continue;}
	// 	std::vector<long long> number;

	// 	for(int j=0;j<n;++j)
	// 	{
	// 		long long element;
	// 		std::cin>>element;
	// 		number.push_back(element);
	// 	}

	// 	//std::cout<<nInversions(number)<<std::endl;
	// }
	
	//std::cout<<"Here Main ************"<<std::endl;
	std::vector<int> v{1,5,6,3,7,8,9,4,2};
	//std::cout<<"Here Main 1 ***************"<<std::endl;
	mergeSort(v.begin(),v.end());
	//std::cout<<"Here Main 2 **************"<<std::endl;
	// std::copy(v.begin(),v.end(), std::ostream_iterator<int>(std::cout, " ** "));
	return 0;
}