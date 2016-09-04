#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
// #include <unordered_map>


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

	// std::unordered_map<char,int> map;
	for(int i=0;i<str.size();++i)
	{
		int index= str[i]-'a';
		sol[index]++;
		// map[str[i]]++;
	}

	std::string temp;

	for(char c='a';c<='z';++c)
	{
		if(sol[c-'a']%2!=0)
		{
			std::string t(sol[c-'a'],c);
			temp+=t;
			// sol[c-'a']++;
		}
	}
	int size=temp.size();
	for(int i=0;i<size/2;++i)
	{
		sol[temp[size-i-1]-'a']--;
		temp[size-i-1]=temp[i];
		sol[temp[i]-'a']++;
		i+=sol[temp[i]-'a'];
	}
	char c;
	if(size%2==0){c=temp[size/2-1];}
	else{c=temp[size/2];}
	// std::cout<<temp<<" temp "<<c<<std::endl;

	size=str.size();int j=0;
	for(int i=0;i<size/2+1;++i)
	{
		int index = str[i]-'a';
		// std::cout<<str[i]<<std::endl;
		if(sol[index]%2==0 && sol[index]!=0)
		{	
			int k=sol[index]/2;
			// std::cout<<k<<" "<<str[i]-'a'<<std::endl;
			while(k>=1)
			{
				ans[j]=str[i];
				ans[size-j-1]=str[i];
				++j;
				--k;
			}
			i+=sol[index]/2-1;
			sol[index]=0;
		}

	}

	// ans[size/2]=c;
	if(size%2!=0){ans[size/2]=c;}
	else
	{
		ans[size/2-1]=c;
	}
	std::cout<<ans<<std::endl;
	// std::copy(sol.begin(),sol.end(),std::ostream_iterator<int>(std::cout," "));
	// std::cout<<std::endl;

	return 0;
}