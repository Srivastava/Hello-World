#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>

int main()
{
	std::string str;
	std::cin>>str;

	int size=str.size();

	bool zero=false;
	for(int i=0;i<size-1;++i)
	{
		if(str[i]=='0' && str[i+1]=='1')
		{
			str.erase(str.begin()+i);
			zero=true;
			break;
		}
	}

	if(!zero){if(str[size-1]=='0'){str.erase(str.begin()+size-1);zero=true;}}
	
	if(!zero)
	{
		for(int i=size-1;i>=0;--i)
		{
			if(str[i]=='1')
			{
				str.erase(str.begin()+i);
				break;
			}
		}
	}
	
	std::cout<<str<<std::endl;
	return 0;
}