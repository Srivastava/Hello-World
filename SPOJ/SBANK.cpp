#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <unordered_map>

/***************************************************************
/********************                 *******************************************
/*						SBANK                                                   */
/********************                 *******************************************
/***************************************************************/


int main()
{
	int nInputs;
	std::cin>>nInputs;

	while(nInputs--)
	{
		unsigned int n;
		std::cin>>n;

		// std::cout<<n<<std::endl;
		std::vector<std::string> strvec;
		strvec.reserve(n);
		std::unordered_map<std::string,int> map;

		while(n--)
		{
			// std::cout<<n<<" * "<<std::endl;
			std::string str;
			std::getline(std::cin,str);
			if(str.size()==0){n++;continue;}
			// std::cin>>str;
			strvec.push_back(str);
			// std::getline(std::cin,str);

			// std::cout<<str<<std::endl;


			auto it=map.find(str);
			if(it!=map.end())
			{
				it->second+=1;
			}
			else
			{
				map.insert({str,1});
			}

		}

		// std::copy(strvec.begin(),strvec.end(),std::ostream_iterator<std::string>(std::cout,"*\n"));
		// std::cout<<std::endl;
		std::sort(strvec.begin(),strvec.end());
		auto it=std::unique(strvec.begin(),strvec.end());
		strvec.resize(std::distance(strvec.begin(),it));


		for(const auto& it:strvec)
		{
			std::cout<<it<<" "<<map[it]<<std::endl;
		}
		map.clear();
	}

	return 0;
}