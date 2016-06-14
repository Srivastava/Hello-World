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
// void collect(const std::string& str,std::string& ans,const int& numofColumns, const int& index)
// {
// 	int val=0,skip=(numofColumns-index)*2-1+index;
	
// 	bool jump=true;
	
// 	int i =0; 
	
// 	int lenStr=str.size();
// 	int len =ans.size();

// 	ans+=str[index];
// 	while(1)
// 	{
// 		if(jump)
// 		{
// 			skip=(numofColumns-index)*2-1+index;
// 			if(val+skip>lenStr){break;}
// 			ans+=str[val+skip];
// 			val+=skip;
// 			jump=false;
// 		}
// 		else
// 		{
// 			skip=index+1;
// 			if(val+skip>lenStr){break;}
// 			ans+=str[val+skip];
// 			val+=skip;
// 			jump=true;

// 		}
// 		// ++i;

// 	}
// }

// int main()
// {
// 	while(1)
// 	{
// 		int numofColumns;
// 		std::cin>>numofColumns;

// 		std::string str;
// 		std::cin>>str;


// 		std::string ans;

// 		// ans+=str[0];

// 		int i=0;
// 		while(i<numofColumns)
// 		{
// 			collect(str,ans,numofColumns ,i);
// 			++i;	
// 		}

// 		std::cout<<ans<<std::endl;

// 	}

// 	return 0;
// }

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

		// for (int i = 0; i < matrix.size(); ++i)
		// {
		// 	std::cout<<matrix[i]<<std::endl;
		// }

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