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
typedef std::vector<std::vector<ull> > vvull;

ull maximum(const std::string& str, const int& k)
{
	int num=0,max=0;


	ull count=0;
	if(str.size()==1){return 1;}
	for(int c=0;c<2;++c)
	{
		num=0;
		for(int i=0,left=0;i<str.size();++i)
		{
			// std::cout<<str[i]<<" "<<count<<std::endl;
			if(str[i]-'a'!=c)
			{
				++num;
			}
			if(num>k)
			{
				// std::cout<<"HERE1: "<<str[i]<<" "<<count<<" "<<num<<std::endl;
				// max<count ? max=count:max=max;
				while(left<=i && str[left]-'a'==c)
				{
					++left;
					// --count;
				}
				++left;

				// --count;
				--num;
			}
			max=std::max(max,i-left+1);
		}
	}
	return max;
}


// ull maximum(const std::string& str, const int& k)
// {
// 	ull left=0,right=1,num=k,max=0;

// 	if(str.size()==1){return 1;}
// 	for(int i=0;i<str.size()-1;++i)
// 	{
// 		right=i+1;
// 		while(num>=0 && right<str.size())
// 		{
// 			if(right==str.size()){break;}

// 			if(str[i]==str[right])
// 			{
// 				++right;
// 			}
// 			else if(str[i]!= str[right] && num>0)
// 			{
// 				++right;
// 				num--;
// 			}
// 			else
// 			{
// 				max<(right - i ) ? max=right-i: max=max;
				
// 				num=k;
// 				break;
// 			}
// 		}
// 		max<(right - i ) ? max=right-i : max=max;
// 		// std::cout<<left<<" "<<right<<std::endl;
// 	}
// 	return max;
// }

// ull n,k;

// vull dp;

// ull val(std::string str,ull i, ull num,bool change)
// {
// 	ull val=0,val1=0,val2=0;
// 	if(change)
// 	{
// 		char temp=str[i-1];
// 		str[i-1]=='a' ? str[i-1]=='b' : str[i-1]='a';
// 		str[i-1]==str[i] ? val=dp[i-1]+1 : val=0;

// 	}
// 	else
// 	{

// 	}
// }

// int main()
// {
// 	ull n,k;
// 	std::cin>>n>>k;

// 	// vull dp(n+1,0);
// 	// dp[0]=0;

// 	std::string str;
// 	std::cin>>str;
// 	dp.resize(n+1);
// 	dp[1]=1;

// 	// std::cout<<dp.size()<<std::endl;
// 	// std::copy(dp.begin(),dp.end(),std::ostream_iterator<ull>(std::cout," "));
	
// 	std::cout<<val(str,1,k,false)<<std::endl;

// 	return 0;
// }


int main()
{
	ull n,k;
	std::cin>>n>>k;

	std::string str;
	std::cin>>str;

	std::cout<<maximum(str,k)<<std::endl;

	return 0;
}