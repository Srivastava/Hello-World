#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>


typedef std::vector<int>::iterator itr;

itr partition(itr left,itr right)
{

    itr i=left;

    itr it=left;


    while(it<right)
    {
        if(*it<*right)
        {

            // using std::swap;
            
           std::iter_swap(i,it);
            std::advance(i,1);
        }
        std::advance(it,1);
    }

    using std::swap;

    std::iter_swap((i),right); 
    // std::advance(i,1);
    return i;
}

void quicksort(itr left, itr right)
{
    if(std::distance(left,right)>=2)
    {
        itr q=partition(left,right);

        if(left!=q)
        	quicksort(left,std::prev(q));
        
        if(right!=q)
        	quicksort(std::next(q),right);
    }
}


int main()
{
    std::vector<int> v={6,10,4,5,3,9,13,8,1};

    std::copy(v.begin(),v.end(),std::ostream_iterator<int>(std::cout," "));
    std::cout<<std::endl;

    quicksort(std::begin(v),std::end(v));

    std::copy(v.begin(),v.end(),std::ostream_iterator<int>(std::cout," "));
    std::cout<<std::endl;


    return 0;
}