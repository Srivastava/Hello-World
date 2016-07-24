#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
// #include <map>

/***************************************************************
/********************                 *******************************************
/*						MIXTURES                                                   */
/********************                 *******************************************
/***************************************************************/


int amtSmoke(const std::vector<int>& input)
{

	// if(left==right){return 0;}

	int size=input.size();

	std::vector<std::vector<int> >smk(size,std::vector<int>(size,INT_MAX));

	for(int i=0;i<size;++i)
	{
		smk[i][i]=0;
	}
	
	int j=0;
	for(int l=2;l<size;++l)
	{
		for(int i=1;i<size-l+1;++i)
		{
			j=i+l-1;

			for(int k=i;k<=j-1;++k)
			{
				int val=smk[i][k]+smk[k+1][j] + input[i-1]*input[j];

				if(val<smk[i][k])
				{
					smk[i][k]=val;
				}
			}
		}
	}
	
	for(int i=0;i<size;++i)
	{
		for(int j=0;j<size;++j)
		{
			std::cout<<smk[i][j]<<",";
		}
		std::cout<<std::endl;
	}
	return smk[1][size-1];
}

int main()
{

	int n;
	while(std::cin>>n)
	{
		int nMix=n;
		
		std::vector<int> input;
		input.reserve(n);

		while(nMix--)
		{
			int val;
			std::cin>>val;

			input.push_back(val);
		}

		std::vector<int> smk(input.size()+1,0);

		std::cout<<amtSmoke(input);
	}
	return 0;
}