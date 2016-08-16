// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <stdio.h>
// #include <algorithm>
// #include <iterator>
// #include <stack>
// #include <queue>

// /***************************************************************
// /********************                 *******************************************
// /*						STPAR                                                 */
// /********************                 *******************************************
// /***************************************************************/


// int main()
// {
// 	while(1)
// 	{
// 		int numCars;
// 		std::cin>>numCars;

// 		if(numCars==0){break;}

// 		int prev,current;

// 		std::cin>>prev;

// 		std::stack<int> order;
// 		std::vector<int> line;
// 		line.push_back(prev);
// 		for(int i=1;i<numCars;++i)
// 		{
// 			std::cin>>current;

// 			if(current>prev)
// 			{
				
// 				if(!order.empty())
// 				{
// 					int top=order.top();
// 					if(top<current)
// 					{
// 						line.push_back(top);
// 						order.pop();
// 					}
// 				}
// 				line.push_back(current);
// 				prev=current;
// 			}

// 			else
// 			{
// 				line[i-1]=current;
// 				order.push(prev);
// 				prev=current;
// 			}

// 		}

		
// 		while(!order.empty())
// 		{
// 			int top=order.top();
// 			line.push_back(top);
			
// 			order.pop();
// 		}

// 		std::copy(line.begin(), line.end(), std::ostream_iterator<int>(std::cout, " * "));


// 		bool ordered=true;
// 		for(int i=1;i<line.size();++i)
// 		{
// 			if(line[i]<line[i-1])
// 			{
// 				ordered=false;
// 				std::cout<<"no"<<std::endl;

// 				break;
// 			}
// 		}
// 		if(ordered)
// 		{
// 			std::cout<<"yes"<<std::endl;
// 		}


// 	}

// 	return 0;
// }

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
/*						STPAR                                                 */
/********************                 *******************************************
/***************************************************************/


int main()
{
	while(1)
	{
		int numCars;
		std::cin>>numCars;

		if(numCars==0){break;}

		int prev,current;

		std::cin>>prev;

		std::stack<int> order;
		std::vector<int> line;

		order.push(prev);
		// line.push_back(prev);
		
		// std::cout<<" Here "<<std::endl;
		for(int i=1;i<numCars;++i)
		{
			std::cin>>current;

			// std::cout<<" Here 1 "<<std::endl;

			if(order.top() > current)
			{
				order.push(current);
			}
			// std::cout<<" Here 2"<<std::endl;
			else
			{
				// std::cout<<" Here 3"<<std::endl;
				while(order.top()<current)
				{
					int top=order.top();
					line.push_back(top);

					// std::cout<<" Here 4 "<<order.size()<<std::endl;

					order.pop();
					if(order.empty()){break;}
				}
				// std::cout<<" Here 5 "<<std::endl;
				order.push(current);
			}
			
		}
		
		// std::cout<<" Here 6"<<std::endl;
		while(!order.empty())
		{
			int top=order.top();
			line.push_back(top);
			
			order.pop();
		}

		// std::cout<<" Here 7"<<std::endl;
		// std::copy(line.begin(), line.end(), std::ostream_iterator<int>(std::cout, " * "));

		bool ordered=true;

		for(int i=1;i<line.size();++i)
		{
			if(line[i]<line[i-1])
			{
				ordered=false;
				std::cout<<"no"<<std::endl;

				break;
			}
		}
		if(ordered)
		{
			std::cout<<"yes"<<std::endl;
		}



	}

	return 0;
}