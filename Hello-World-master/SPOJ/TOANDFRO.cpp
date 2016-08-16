#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <stack>
#include <queue>

/***************************************************************
/********************                 *******************************************
/*						TOANDFRO                                                 */
/********************                 *******************************************
/***************************************************************/


int main()
{
	while(1)
	{
		
		int numofColumns;
		std::cin>>numofColumns;
		if(numofColumns==0){break;}

		std::string str;
		std::cin>>str;

		std::vector<std::string> matrix;

		int val=0;
		for(int i=0;i<str.size()/numofColumns;++i)
		{
			
			val=numofColumns*i;
			std::string ans = str.substr(val,numofColumns);
			
			if(i%2==0){matrix.push_back(ans);}
			else
			{
				std::reverse(ans.begin(),ans.end());
				matrix.push_back(ans);
			}
		}

		for(int i = 0 ;i<numofColumns;++i)
		{
			for (int j = 0; j<matrix.size(); ++j)
			{
				std::cout<<matrix[j][i];
			}
		}
		std::cout<<std::endl;
	}

	return 0;
}