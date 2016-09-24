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

const ll MOD = 1000000007;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;

typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::pair<ll,ll> pa;
typedef std::vector<pa> vpa;

typedef std::vector<vll> vvll;


int main()
{
	std::string str;
	std::cin>>str;

	std::string ans=str;

	std::sort(str.begin(),str.end());

	vi sol(26,0);

	
	for(int i=0;i<str.size();++i)
	{
		int index= str[i]-'a';
		sol[index]++;
		
	}

	std::string temp;

	for(char c='a';c<='z';++c)
	{
		if(sol[c-'a']%2!=0)
		{
			
			temp+=c;
			
		}
	}
	int size=temp.size();
	for(int i=0;i<size/2;++i)
	{
		sol[temp[size-i-1]-'a']--;
		temp[size-i-1]=temp[i];
		sol[temp[i]-'a']++;
	}
	
	char c;
	if(size%2==0){c=temp[size/2-1];}
	else{c=temp[size/2];}

	
	int j=0; bool odd=false;
	size=ans.size();

	for(int i=0;i<26;++i)
	{
		
		if(sol[i]!=0)
		{
			int cnt=sol[i]/2;
			if(sol[i]==1){ans[size/2]=i+'a';}
			
			int k=0;
			while(k<cnt && j<size)
			{
				if(j==size/2){++j;continue;}
				ans[j]=i+'a';
				ans[size-j-1]=i+'a';
				++j;
				++k;
			}


		}
		if(sol[i]%2!=0 && sol[i]!=1)
		{
			ans[size/2]=i+'a';
			odd=true;
		}
	}
	
	std::cout<<ans<<std::endl;
	// std::copy(sol.begin(),sol.end(),std::ostream_iterator<int>(std::cout," "));
	// std::cout<<std::endl;

	return 0;
}