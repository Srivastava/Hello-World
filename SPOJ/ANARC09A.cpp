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
/*						ANARC09A                                                   */
/********************                 *******************************************
/***************************************************************/

// int numOper(int start,int end,const std::string& str,std::vector<std::vector<int> >& num)
// {
// 	int cost=0;

// 	std::cout<<start<<" "<<end<<std::endl;
// 	if(start>end){return 0;}
// 	if(start==end){return 0;}
// 	if(start>str.size() || end < 1) {return 0;}

// 	if(num[start][end]!=-1){return num[start][end];}

// 	int val=INT_MAX,val1=INT_MAX,val2=INT_MAX;
// 	if(str[start]=='{' && str[end]=='}')
// 	{
// 		cost=0;
// 	}

// 	else if(str[end]=='{' && str[start]=='}')
// 	{
// 		cost=2;
// 	}

// 	else
// 	{
// 		cost=1;
// 	}
	
// 	if(end-start == 1){return cost;}
// 	// val=std::min(numOper(start+1,end-1,str,num)+cost,std::min(numOper(start,start+1,str,num),numOper(end-1,end,str,num)));
// 	val=std::min(numOper(start+1,end-1,str,num)+cost,numOper(start,start+1,str,num));
// 	num[start][end]=val;

// 	return val;
// }



int numOper(int start,int end,const std::string& str,std::vector<std::vector<int> >& num)
{
	int cost=0;

	std::cout<<start<<" "<<end<<std::endl;
	if(start>end){return 0;}
	if(start==end){return 0;}
	if(start>str.size() || end < 1) {return 0;}

	if(num[start][end]!=-1){return num[start][end];}

	int val=INT_MAX,val1=INT_MAX,val2=INT_MAX;
	if(str[start]=='{' && str[end]=='}')
	{
		cost=0;
	}

	else if(str[end]=='{' && str[start]=='}')
	{
		cost=2;
	}

	else
	{
		cost=1;
	}
	

	if(cost==0)
	{
		val=numOper(start+1,end-1,str,num);
	}
	else
	{
		
	}
	if(end-start == 1){return cost;}
	// val=std::min(numOper(start+1,end-1,str,num)+cost,std::min(numOper(start,start+1,str,num),numOper(end-1,end,str,num)));
	val=std::min(numOper(start+1,end-1,str,num)+cost,numOper(start,start+1,str,num));
	num[start][end]=val;

	return val;
}

int main()
{
	int i=1;
	while(1)
	{
		std::string str;

		std::cin>>str;

		if(str[0]=='-')
		{
			break;
		}

		std::vector<std::vector<int> > num(str.size(),std::vector<int> (str.size(),-1));
		std::cout<<i<<". "<<numOper(0,str.size()-1,str,num)<<std::endl;
		++i;
	}

	return 0;
}