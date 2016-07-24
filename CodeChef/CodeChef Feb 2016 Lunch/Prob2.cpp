#include <iostream>
#include <vector>
#include <utility>

int main()
{

	int T,N,K; //T test cases, N number of lines and K length of sequence

	std::cin>>T>>N>>K;

	//std::cout<<T<<N<<K;

	while(T>0)
	{
		char c;
    int val=0;

    bool isTrue=false;
		std::vector<std::vector<int> > matrix;
    std::vector<std::pair<int,int> > pos;

		for (int i=0;i<N;++i)
		{
			std::vector<int> temp;

			for (int j=0;j<N;++j)
			{
				std::cin>>c;
				//std::cout<<c;
				if(c!='\n')
				{
					if(c=='X'){val=1;}
					else if(c=='O'){val=0;}
          else {val=-1;std::pair<int,int> pair(i,j);pos.push_back(pair);}

					temp.push_back(val);
				}

			}
      matrix.push_back(temp);
      //std::cout<<std::endl;
		}

    /*for(int i=0;i<pos.size();++i)
    {
      std::cout<<pos.at(0).first<<" "<<pos.at(0).second<<std::endl;
    }*/

    for(int i=0;i<pos.size();++i)
    {
      int sum=0;
      if(N==K)
      {
        int row=0,col=0,diag=0;
        for(int i=0;i<N;++i)
        {
          row+=matrix[pos.at(i).first][i];
        }

        for(int i=0;i<N;++i)
        {
          row+=matrix[i][pos.at(i).second];
        }

        for(int i=0;i<N;++i)
        {
          row+=matrix[i][i];
        }

        if(row==K || col==K || diag==K)
        isTrue=true;
      }

      else
      {
        for(int i=0;i<N;++i)
        {
          int j=0;
          int row=0,col=0,diag=0;
          if(pos.at(i).first<K){j=0;}else{j=pos.at(i).first-K;}

          for(j=j+i;j<pos.at(i).first+1;++j)
          {
            row+=matrix[pos.at(j).first][i];
          }
          if(row==K){isTrue;break;}
        }
        if(isTrue){break;}
        for(int i=0;i<N;++i)
        {
          int j=0;
          int row=0,col=0,diag=0;
          if(pos.at(i).second<K){j=0;}else{j=pos.at(i).second-K;}

          for(j=j+i;j<pos.second+1;++j)
          {
            col+=matrix[j][pos.at(j).second];
          }
          if(col==K){isTrue;break;}
        }

        if(isTrue){break;}

      }
    }


		for (int i=0;i<N;++i)
		{

			for (int j=0;j<N;++j)
			{
				std::cout<<matrix[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
		std::cout<<"Case Ended"<<std::endl;
		--T;
	}
	return 0;
}
