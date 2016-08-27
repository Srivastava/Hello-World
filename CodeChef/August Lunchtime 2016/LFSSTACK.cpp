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
     
    typedef std::vector<int> vi;
    typedef std::vector<bool> vb;
    typedef std::pair<ll,ll> pa;
    typedef std::vector<pa> vpa;
     
    typedef std::vector<vll> vvll;
  
  	bool subseq(std::string str,std::string str1,int m,int n)
  	{
  		if(m==0){return true;}
  		if(n==0){return false;}

  		if(str[m-1] == str1[n-1])
        return subseq(str, str1, m-1, n-1);
 
	    return subseq(str, str1, m, n-1);
  	}   
     
    int main()
    {
    	int t;
    	std::cin>>t;
     
    	while(t--)
    	{
    		int n,sum=0;
    		std::cin>>n;
    		std::vector<std::string> vstr;
    		// std::stack<int> s;
    		for(int i=0;i<n;++i)
    		{
	    		std::string valstr;
    			int m;
    			std::cin>>m;
    			sum+=m;
    			for(int i=0,val;i<m;++i)
    			{
    				std::cin>>val;
    				valstr+='0'+val;
    				// s.push(val);
    			}
    			vstr.push_back(valstr);
    		}
     
     
    		std::string str,test;
    		/*while(!s.empty())
    		{
    			int top=s.top();
    			s.pop();
     
    			str+='0'+top;
    			// str+=" ";
    		}*/
     
    		// std::cout<<str<<std::endl;
    		
    		for(int i=0,val;i<sum;++i)
    		{
    			std::cin>>val;
    			test+='0'+val;
    			// std::cout<<val<<" * ";
    		}
     		
     		std::reverse(test.begin(),test.end());

     		/*for(int i=0;i<n;++i)
     		{
     			for(int j=0;j<vstr[i].size();++j)
     			{

     			}
     		}*/
     		/*std::cout<<test<<std::endl;
     		std::cout<<str<<std::endl;*/
     		// std::string ori=str;
    		str+=str;
     
    		if (str.find(test) != std::string::npos) 
    		{
    		    std::cout << "Yes" << '\n';
    		}
    		else
    		{
    			for(int i=0;i<n;++i)
    			{
    				if(subseq(vstr[i],test,vstr[i].size(),test.size()))
    				{

    				}
    				else
    				{
    					std::cout<<"No"<<std::endl;
    					return 0;
    				}
    			}
    			/*for(int i=0;i<test.size();++i)
    			{

    			}*/
    			std::cout<<"No"<<std::endl;
    		}
    	}
     
    	return 0;
    } 