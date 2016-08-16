#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>

long long binaryAux(const int& left,const int& right, const std::vector<long long>& a,const long long& val)
{
	// long long len=std::distance(a.begin(),a.end());
	// if(right-left+1==1){return a[0]==val ? 1:0;}
	if(right==left){return a[left]==val ? 1:0;}
	// if(right-left +1 ==0){return 0;}
	if(right-left == 0 ){return a[left]==val ? 1:0;}
	if(left>right){return 0;}

	// std::cout<<"Here binaryAux "<<val<<std::endl;

	long long mid=left+(right-left)/2;

	std::cout<<left<<" "<<right<<" "<<mid<<std::endl;
	// std::cout<<"Here binaryAux 1 "<<mid<<" "<<a.size()<<std::endl;


	// std::vector<long long> left(a.begin(),a.begin()+mid);
	// std::vector<long long> right(a.begin()+mid,a.end());


	// std::copy(left.begin(),left.end(),std::ostream_iterator<long long>(std::cout," "));
	// std::cout<<" left"<<std::endl;

	// std::copy(right.begin(),right.end(),std::ostream_iterator<long long>(std::cout," "));
	// std::cout<<" right"<<std::endl;

	// std::cout<<"Here binaryAux 3 "<<mid<<std::endl;

	// if(right-left==1){mid=0;}
	long long leftVal=binaryAux(left,mid-1,a,val);
	long long rightVal=binaryAux(mid+1,right,a,val);

	// std::cout<<val<<" "<<leftVal+rightVal<<std::endl;
	// if(leftVal==1 && rightVal==1){return 2;}
	// else{return 0;}
	return leftVal+rightVal;
}

long long binary(const std::vector<long long>& a, const long long& i,const long long& fac)
{	
	long long val=a[i];
	if(val%fac!=0){return 0;}

	long long leftValF=val/fac,rightValF=val*fac;

	// std::vector<long long> left(a.begin(),a.begin()+i);
	// std::vector<long long> right(a.begin()+i+1,a.end());

	// std::cout<<"----------BINARY------------"<<std::endl;
	
	// std::copy(left.begin(),left.end(),std::ostream_iterator<long long>(std::cout," "));
	// std::cout<<" left"<<std::endl;

	// std::copy(right.begin(),right.end(),std::ostream_iterator<long long>(std::cout," "));
	// std::cout<<" right"<<std::endl;

	// std::cout<<"Here binary "<<std::endl;
	long long leftVal=binaryAux(0,i,a,leftValF);
	long long rightVal=binaryAux(i+1,a.size()-1,a,rightValF);
	// std::cout<<"Here binary 1 "<<std::endl;

	// std::cout<<leftVal*rightVal<<std::endl;
	return leftVal*rightVal;

}	

int main()
{
	unsigned long n,k;
	std::cin>>n>>k;

	long long size=n;

	std::vector<long long> a;
	while(n--)
	{
		long long val;
		std::cin>>val;

		a.push_back(val);
	}

	long long ans=0;

	for(long long i=1;i<size-1;++i)
	{
		// std::cout<<"-------------------"<<std::endl;
		// std::cout<<i<<std::endl;
		ans+=binary(a,i,k);
	}

	std::cout<<ans<<std::endl;
	return 0;
}