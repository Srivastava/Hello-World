#include <iostream>
#include <vector>
#include <algorithm>

class SMBus {
public:
int transmitTime(std::vector<std::string> messages,std::vector<int> times);
};

int max(std::vector<int> vec)
{
	int temp=vec[0];
	for(int i=1;i<vec.size();++i)
	{
		if(temp<vec[i])
		{
			temp=vec[i];
		}
	}
	return temp;
}

int SMBus::transmitTime(std::vector<std::string> messages,std::vector<int> times)
{
	int sum=0;
	
	while(messages.size()!=0)
	{
		int j=0;
	
		
		while(1)
		{
			int index=0;
			j=0;
			int maximum=max(times);
	
			for(int i=0;i<messages.size();++i)
			{
				if(j>=messages[i].size()){index=i;break;}
				if(messages[i].at(j)<messages[index].at(j))
				{
					
					index=i;
				}
				//sum+=maximum;
			}
			sum+=maximum+times[index]*(messages[index].size()-2);

			times.erase(times.begin()+index);
			messages.erase(messages.begin()+index);

			if(messages.size()==0){break;}
			++j;
		
		}
	}
	
	return sum;
	
}
