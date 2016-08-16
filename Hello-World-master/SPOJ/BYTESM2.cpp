#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
// #include <map>

/***************************************************************
/********************                 *******************************************
/*						BYTESM2                                                   */
/********************                 *******************************************
/***************************************************************/

unsigned long nPhilospher(const int& h, const int& w,const std::vector<std::vector<unsigned long> >& num )
{
	std::vector<std::vector<unsigned long> > sol(h+1,std::vector<unsigned long> (w+1,0));

	// for(int i=0;i<h;++i)
	// {
	// 	sol[i][0]=num[i][0];
	// }

	// for(int i=0;i<w;++i)
	// {
	// 	sol[0][i]=num[0][i];
	// }


	for(int i=1;i<h+1;++i)
	{
		for(int j=1;j<w+1;++j)
		{
			unsigned long left=sol[i-1][j-1],top=sol[i-1][j],right=0;


			// if(i-1 >= 0){left=sol[i-1][j-1]}
			// std::cout<<j+1 << " "<<sol[i-1][j+1]<<std::endl;
			// std::cout<<j+1<<" ,";
			if(j+1 < w+1){right=sol[i-1][j+1];}
			// std::cout<<left<<" "<<top<<" "<<right<<" "<<num[i-1][j-1]<<",";
			sol[i][j]=num[i-1][j-1]+std::max(left,std::max(right,top));
			// sol[i][j]=std::max(sol[i-1][j-1],std::max(sol[i-1][j+1]))
		}
		// std::cout<<std::endl;
	}


	// for(int i=0;i<=h;++i)
	// {
	// 	for(int j=0;j<=w;++j)
	// 	{
	// 		// int val;
	// 		std::cout<<sol[i][j]<<",";
	// 		// num[i][j]=val;
	// 	}
	// 	std::cout<<std::endl;
	// }

	// std::cout<<"Came out of the"
	int max=sol[h][0];
	for(int i=1;i<=w;++i)
	{
		if(max<sol[h][i])
		{
			max=sol[h][i];
		}
	}
	return max;
}

int main()
{
	int nInputs;
	std::cin>>nInputs;

	while(nInputs--)
	{

		unsigned long long h,w;

		std::cin>>h>>w;
		std::vector<std::vector<unsigned long> > num(h,std::vector<unsigned long> (w,0));


		for(int i=0;i<h;++i)
		{
			for(int j=0;j<w;++j)
			{
				int val;
				std::cin>>val;
				num[i][j]=val;
			}
		}

		std::cout<<nPhilospher(h,w,num)<<std::endl;


		// for(int i=0;i<h;++i)
		// {
		// 	for(int j=0;j<w;++j)
		// 	{
		// 		// int val;
		// 		std::cout<<num[i][j]<<",";
		// 		// num[i][j]=val;
		// 	}
		// 	std::cout<<std::endl;
		// }


	}


	return 0;
}