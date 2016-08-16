#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <set>

/***************************************************************
/********************                 *******************************************
/*						FACEFRND                                                   */
/********************                 *******************************************
/***************************************************************/


int main()
{
	int nInputs;
	std::cin>>nInputs;

	int minus=nInputs;
	std::set<int> nFriends;
	while(nInputs--)
	{
		int n,m;
		std::cin>>n>>m;

		// std::cout<<n<<" "<<m<<std::endl;
		nFriends.insert(n);
		while(m--)
		{
			int val;
			std::cin>>val;
			// std::cout<<val<<"* "<<std::endl;
			nFriends.insert(val);
		}
		// std::cout<<m<<" ** "<<nFriends.size()<<std::endl;


	}

	// std::copy(nFriends.begin(),nFriends.end(),std::ostream_iterator<int>(std::cout," * "));
	int ans=nFriends.size()-minus;

	std::cout<<ans<<std::endl;

	return 0;
}