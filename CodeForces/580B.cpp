#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;


typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::vector<std::pair<ull,ull> > pvull;
typedef std::vector<std::pair<ll,ll> > pvll;

ull dist;

// ull maxFriend(const pvull& cf,ull left,ull right)
// {
// 	ull mid = left + (right-left)/2;

// 	std::cout<<left <<" "<<right<<" "<< mid<<std::endl;
// 	if(left==right){/*std::cout<<"Here"<<std::endl;*/return cf[left].second;}

// 	ull leftVal=0,rightVal=0,sum=0;

// 	if(cf[right].first-cf[left].first >=dist)
// 	{
// 		std::cout<<"left"<<std::endl;
// 		leftVal=maxFriend(cf,left,mid);
// 		++mid;
// 		rightVal=maxFriend(cf,mid,right);
// 	}
// 	else
// 	{
// 		for(int i=left;i<=right;++i)
// 		{
// 			sum+=cf[i].second;
// 		}

// 		ull len=(right-left)/2;

// 		ull l=0,r=0;
// 		if(right-left>1)
// 		{

// 			std::cout<<"hmmmm"<<std::endl;
// 			if(left!=0 && left-len!=0)
// 			l=maxFriend(cf,left-len,right);

// 			if(right!=cf.size()-1 && right+len!=cf.size()-1)
// 			r=maxFriend(cf,left,right+len);
// 		}

// 		sum+=std::max(l,r);
// 	}

// 	return std::max(sum,std::max(leftVal,rightVal));

// }

ull sum(const pvull& cf,ull left,ull right)
{
	ull s=0;
	for(ull i=left;i<=right;++i)
	{
		s+=cf[i].second;
		std::cout<<s<<" s "<<std::endl;
	}
	return s;
}
ull maxFriend(const pvull& cf,ull left,ull right)
{
	ll j=right; ll add=0;
	ll i = right-1;
	for(;i>=left;)
	{
		std::cout<<left<<" "<<i<<" "<<j<<" "<<dist<<std::endl;
		if(cf[j].first-cf[i].first <dist)
		{
			--i;	
		}
		else
		{
			ll addition=sum(cf,i+1,j);
			std::cout<<"Here "<<addition <<" " <<i<<" "<<j<<std::endl;
			if(cf[i].second > cf[j].second && cf[j-1].first - cf[i].first<dist)
			{
				addition+=cf[i].second-cf[j].second;
				std::cout<<" unf "<<std::endl;
				j-=1;
				--i;
			}
			else
			{
				j=i;
				--i;
			}
			if(add<addition)
			{
				add=addition;
			}
			
		}
		if(i<0){break;}
	}
	// ll addition=0;
	// if(j==right)
	// {
	// 	i=0;
	// 	addition=sum(cf,i,j);
	// }

	// std::cout<<addition<<" addition "<<i<<" "<<j<<std::endl;
	// if(add<addition)
	// {
	// 	add=addition;
	// }
	return add;
}
int main()
{
	ull n,d;
	std::cin>>n>>d;

	dist =d;

	pvull cf;
	cf.reserve(n);


	for(ull i=0;i<n;++i)
	{
		ull a,b;
		std::cin>>a>>b;
		cf.push_back(std::make_pair(a,b));
	}

	std::sort(cf.begin(), cf.end(), [](const std::pair<long long,long long> &left, const std::pair<long long,long long> &right) {
    return left.first < right.first;
	});

	std::cout<<maxFriend(cf,0,n-1)<<std::endl;

	return 0;
}