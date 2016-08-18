#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <climits>
#include <numeric>
#include <queue>

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

struct TreeNode
{
	TreeNode* left;
	TreeNode * right;

	ll val;
};

void insert(TreeNode* root,ll v,ll& parent)
{
	// std::cout<<root->val<<" root val"<<std::endl;
	/*if(root==NULL)
	{
		std::cout<<"HERE"<<std::endl;
		
		root=new TreeNode();
		root->val=v;

		root->left=NULL;
		root->right=NULL;
		
		return;
	}*/
		parent=root->val;
	// std::cout<<"HERE 1"<<std::endl;
	if(v>root->val)
	{
		if(root->right!=NULL)
			insert(root->right,v,parent);
		else
		{
			root->right=new TreeNode();
			root->right->val=v;
			return;
		}
	}
	else
	{
		if(root->left!=NULL)
			insert(root->left,v,parent);
		else
		{
			root->left=new TreeNode();
			root->left->val=v;
			return;
		}
	}
}
int main()
{
	TreeNode* root=new TreeNode();

	ll n;
	std::cin>>n;

	ll t;
	std::cin>>t;

	root->val=t;
	// std::cout<<root->val<<std::endl;
	root->left=NULL;
	root->right=NULL;
	
	// std::cout<<root->left->val<<std::endl;
	// if(root->left){std::cout<<"NULL"<<std::endl;}

	vll a(n,0);
	for(int i=1;i<n;++i)
	{
		std::cin>>t;
		ll value=root->val;
		
		insert(root,t,value);
		// std::cout<<value<<std::endl;
		a[i]=value;
	}

	std::copy(a.begin()+1,a.end(),std::ostream_iterator<ll>(std::cout," "));
	std::cout<<std::endl;
	return 0;
}
