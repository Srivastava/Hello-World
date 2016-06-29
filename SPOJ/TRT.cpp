#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
// #include <unordered_map>
/***************************************************************
/********************                 *******************************************
/*						TRT                                                   */
/********************                 *******************************************
/***************************************************************/

// unsigned long maxRevenue(const std::vector<unsigned long>& treat)
// {
// 	int size=treat.size();
// 	std::vector<std::vector<unsigned long> > num(size,std::vector<unsigned long> (size,0));

// 	num[0][0]=treat[0];
// 	num[0][size-1]=treat[size-1];

// 	for(int i=1;i<size;++i)
// 	{
// 		for(int j=0;j<size;++j)
// 		{
// 			int indexX=i-1,indexY1=size-j-1,indexY2=j-1;
// 			if(j>size/2){indexY2=j+1;}
// 			if(indexY1==-1){indexY1=size-1;}
// 			// if(indexY2==size){indexY2=0;}

// 			int valL=num[indexX][indexY1],valR=num[indexX][indexY2];
// 			if(j==0){valR=0;}
// 			if(j==size-1){valR=0;}
// 			// int valT
// 			if(valL==0 && valR==0){num[i][j]=0;}
// 			else
// 			{
// 				num[i][j]=((i+1)*treat[j])+std::max(valL,valR);
// 			}
				
// 		}
// 	}

// 	for(int i=0;i<size;++i)
// 	{
// 		for(int j=0;j<size;++j)
// 		{
// 			std::cout<<num[i][j]<<",";
// 		}
// 		std::cout<<std::endl;
// 	}
// 	return num[size-1][size-1];
// }


unsigned long maxRevenue(int start,int end,const std::vector<unsigned long>& treat,std::vector<std::vector<unsigned long> >& num)
{
	if(start>end){return 0;}

	if(num[start][end]!=0){return num[start][end];}

	int year=num.size()-(start-end+1)+1;

	num[start][end]=std::max(maxRevenue(start+1,end,treat,num)+year*(treat[start]),maxRevenue(start,end-1,treat,num)+year*treat[end]);

	return num[start][end];
}

int main()
{
	int n;
	std::cin>>n;

	std::vector<unsigned long> treat;
	treat.reserve(n);

	while(n--)
	{
		unsigned long val;
		std::cin>>val;

		treat.push_back(val);
	}

	std::vector<std::vector<unsigned long> > num(treat.size(),std::vector<unsigned long> (treat.size(),0));
	std::cout<<maxRevenue(0,treat.size()-1,treat,num)<<std::endl;

	for(int i=0;i<num.size();++i)
	{
		for(int j=0;j<num[i].size();++j)
		{
			std::cout<<num[i][j]<<",";
		}
		std::cout<<std::endl;
	}
	return 0;
}