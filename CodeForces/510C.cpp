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
typedef std::vector<bool> vb;

int main()
{
	ll n;
	std::cin>>n;

	vb visited(n,false),present(n,false);

	// std::cout<<"HERE "<<std::endl;
	
	std::vector<char> a;
	std::string prev;
	std::cin>>prev;
	a.push_back(prev[0]);

	for(int i=1;i<n;++i)
	{
		std::string str;
		std::cin>>str;
		a.push_back(str[0]);

		if(i>0)
		{
			// std::cout<<prev[0]<<" "<<str[0]<<std::endl;
			if(prev[0]==str[0])
			{
				ll size=std::min(prev.size(),str.size());
				for(int j=1;j<size;++j)
				{
					if(prev[j]<str[j])
					{
						// a.push_back
						a.push_back(prev[j]);
						break;
					}
				}

			}
		}
		present[str[0]-'a']=true;

		prev=str;
		// std::cout<<prev<<std::endl;
	}

	std::vector<char> alpha(26,'A');
	ll count=0;

	for(char c='a';c<='z';++c)
	{
		if(!present[c-'a'])
		{
			alpha[count]=c;
		}
		++count;
	}

	ll left=0,right=0,c=0;

	// std::copy(a.begin(),a.end(),std::ostream_iterator<char>(std::cout,""));
	// std::cout<<std::endl;

	bool lol=true;
	while(lol && a.size()>1)
	{
		for(int i=1;i<a.size();++i)
		{
			lol=false;
			if(a[i-1]==a[i])
			{
				lol=true;
				a.erase(a.begin()+i);
				break;
			}
		}
	}

	std::copy(a.begin(),a.end(),std::ostream_iterator<char>(std::cout,""));
	std::cout<<std::endl;
	while(left<26)
	{
		// std::cout<<left<<" "<<a[c]<<" "<<a.size()<<std::endl;
		if(alpha[left]!='A')
		{
			++left;
		}
		else
		{
			right=left;
			while(alpha[right]=='A')
			{
				++right;
			}

			// ++left;
			if(alpha[right]>a[c])
			{
				if(visited[a[c]-'a']){break;}
				// if(a[left-1]==a[left]){++left;++c;continue;}
				alpha[left]=a[c];

				// std::cout<<a[c]<<" * "<<std::endl;

				visited[a[c]-'a']=true;
				++c;
			}
			else
			{
				alpha[left]=alpha[right];
				alpha[right]='A';
			}
			++left;

		}
	}

	std::copy(alpha.begin(),alpha.end(),std::ostream_iterator<char>(std::cout,""));
	if(left!=26 || c!=a.size())
	{
		std::cout<<"Impossible"<<std::endl;
	}
	else
	{
		std::copy(alpha.begin(),alpha.end(),std::ostream_iterator<char>(std::cout,""));
		std::cout<<std::endl;
	}
	return 0;
}