#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>
#include <stack>

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1000000007;

typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::pair<ll,ll> pa;

typedef std::vector<pa> pvll;
typedef std::vector<pvll> vpvll;

int main()
{

	std::vector<vll> input;

	ll n,m;
	std::cin>>n>>m;

	ll x,y;

	ll nodes=0;
	for(int i=0;i<n;++i)
	{
		std::string str;
		std::cin>>str;

		std::vector<ll> temp;

		for(int j=0;j<m;++j)
		{
			if(str[j]=='*')
			{

				temp.push_back(-2);
			}
			else if(str[j]=='.')
			{
				++nodes;
				temp.push_back(0);
			}
			else if(str[j]=='C')
			{
				x=i;y=j;
				++nodes;
				temp.push_back(2);
			}
		}
		input.push_back(temp);
	}

	/*for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			std::cout<<input[i][j]<<",";
		}
		std::cout<<std::endl;
	}*/


	std::queue<pa> q;
	q.push(std::make_pair(x,y));

	std::string str;
	pa prev=std::make_pair(-1,-1);
	nodes*=2;

	char d='r';
	while(!q.empty())
	{
		pa temp =q.front();

		
		ll xi,yi;
		xi=temp.first;
		yi=temp.second;
		--nodes;

		q.pop();

		input[xi][yi]-=1;
		
		std::cout<<xi<<" "<<yi<<" "<<input[xi][yi]<<" "<<nodes<<std::endl;

		if(nodes<0){break;}

		if(d=='r')
		{
			str+='R';
			if(input[xi][yi+1]<=-2)
			{

				if(input[xi-1][yi]!=-2)
				{
					d='u';
					q.push(std::make_pair(xi-1,yi));
				}
				else if(input[xi+1][yi]!=-2)
				{
					d='d';
					q.push(std::make_pair(xi+1,yi));
				}
				else if(input[xi][yi-1]!=-2)
				{
					d='l';
					q.push(std::make_pair(xi,yi-1));
				}
			}
			else
			{
				q.push(std::make_pair(xi,yi+1));
			}
		}

		else if(d=='l')
		{
			str+='L';
			if(input[xi][yi-1]<=-2)
			{

				if(input[xi-1][yi]!=-2)
				{
					d='u';
					q.push(std::make_pair(xi-1,yi));
				}
				else if(input[xi+1][yi]!=-2)
				{
					d='d';
					q.push(std::make_pair(xi+1,yi));
				}
				else if(input[xi][yi+1]!=-2)
				{
					d='r';
					q.push(std::make_pair(xi,yi+1));
				}
			}
			else
			{
				q.push(std::make_pair(xi,yi-1));
			}
		}

		else if(d=='u')
		{
			str+='U';
			if(input[xi-1][yi]<=-2)
			{

				if(input[xi][yi+1]!=-2)
				{
					d='r';
					q.push(std::make_pair(xi,yi+1));
				}
				else if(input[xi+1][yi]!=-2)
				{
					d='d';
					q.push(std::make_pair(xi+1,yi));
				}
				else if(input[xi][yi-1]!=-2)
				{
					d='l';
					q.push(std::make_pair(xi,yi-1));
				}
			}
			else
			{
				q.push(std::make_pair(xi-1,yi));
			}
		}

		else if(d=='d')
		{
			str+='D';
			if(input[xi+1][yi]<=-2)
			{

				if(input[xi][yi+1]!=-2)
				{
					d='r';
					q.push(std::make_pair(xi,yi+1));
				}
				else if(input[xi-1][yi]!=-2)
				{
					d='u';
					q.push(std::make_pair(xi-1,yi));
				}
				else if(input[xi][yi-1]!=-2)
				{
					d='l';
					q.push(std::make_pair(xi,yi-1));
				}
			}
			else
			{
				q.push(std::make_pair(xi+1,yi));
			}
		}


		// if(xi!=x || yi!=y)
		// {
		// 	input[xi][yi]-=1;
		// }
		// else if(xi==x && yi==y && input[x][y]==1)
		// {
		// 	input[x][y]=0;
		// }

		// std::cout<<xi<<" "<<yi<<" "<<input[xi][yi]<<" "<<nodes<<std::endl;
		
		// if(prev.first!=-1)
		// {
		// 	if(temp.first<=prev.first && temp.second==prev.second)
		// 	{
		// 		d='u';
		// 		str+="U";
		// 		// continue;
		// 	}

		// 	else if(temp.first>=prev.first && temp.second==prev.second)
		// 	{
		// 		d='d';
		// 		str+="D";
		// 		// continue;
		// 	}
		// 	else if(temp.first==prev.first && temp.second<=prev.second)
		// 	{
		// 		str+="L";
		// 		d='l';
		// 		// continue;
		// 	}
		// 	else if(temp.first==prev.first && temp.second>=prev.second)
		// 	{
		// 		d='r';
		// 		str+="R";
		// 		// continue;
		// 	}

		// }



		// if(input[xi-1][yi]>=0)
		// {
		// 	// str+="U";
		// 	q.push(std::make_pair(xi-1,yi));
		// }
		// if(input[xi][yi-1]>=0)
		// {
		// 	// str+="L";
		// 	q.push(std::make_pair(xi,yi-1));
		// }
		// if(input[xi+1][yi]>=0)
		// {
		// 	// str+="D";
		// 	q.push(std::make_pair(xi+1,yi));
		// }
		// if(input[xi][yi+1]>=0 && d=='r')
		// {
		// 	// str+="R";
		// 	q.push(std::make_pair(xi,yi+1));
		// }

		// prev=temp;
		// if(nodes<0){break;}
		
	}
	// input[x][y]=1;
	/*while(!q.empty())
	{
		pa temp =q.top();

		
		ll xi,yi;
		xi=temp.first;
		yi=temp.second;

		
		if(xi!=x || yi!=y)
		{
			input[xi][yi]+=1;
		}
		else if(xi==x && yi==y && input[x][y]==1)
		{
			input[x][y]=0;
		}

		std::cout<<xi<<" "<<yi<<" "<<input[x][y]<<" "<<nodes<<std::endl;
		q.pop();

		--nodes;

		if(nodes==1){input[x][y]=1;q.push(std::make_pair(x,y));}

		if(prev.first!=-1)
		{
			if(temp.first<=prev.first && temp.second==prev.second)
			{
				str+="U";
				// continue;
			}

			else if(temp.first>=prev.first && temp.second==prev.second)
			{
				str+="D";
				// continue;
			}
			else if(temp.first==prev.first && temp.second<=prev.second)
			{
				str+="L";
				// continue;
			}
			else if(temp.first==prev.first && temp.second>=prev.second)
			{
				str+="R";
				// continue;
			}

		}


		if(input[xi-1][yi]!=0)
		{
			// str+="U";
			q.push(std::make_pair(xi-1,yi));
		}
		if(input[xi][yi-1]!=0)
		{
			// str+="L";
			q.push(std::make_pair(xi,yi-1));
		}
		if(input[xi+1][yi]!=0)
		{
			// str+="D";
			q.push(std::make_pair(xi+1,yi));
		}
		if(input[xi][yi+1]!=0)
		{
			// str+="R";
			q.push(std::make_pair(xi,yi+1));
		}


		prev=temp;
		if(nodes<0){break;}
	}*/

	std::cout<<str<<std::endl;

	for(int i=0;i<str.size();++i)
	{
		if(str[i]=='U'){str[i]='D';}
		else if(str[i]=='L'){str[i]='R';}
		else if(str[i]=='D'){str[i]='U';}
		else if(str[i]=='R'){str[i]='L';}
	}
	std::cout<<str<<std::endl;

	// vpvll graph;

	// for(int i=1;i<n-1;++i)
	// {
	// 	for(int j=1;j<m-1;++j)
	// 	{
	// 		if(input[i][j]!=0)
	// 		{
	// 			if(input[i-1][j]!=0)
	// 			{
	// 				std::make_pair()
	// 			}
	// 			if(input[i+1][j]!=0)
	// 			{

	// 			}
	// 			if(input[i][j-1]!=0)
	// 			{

	// 			}
	// 			if(input[i][j+1]!=0)
	// 			{

	// 			}
	// 		}

	// 	}
		// std::cout<<std::endl;
	// }


	return 0;
}