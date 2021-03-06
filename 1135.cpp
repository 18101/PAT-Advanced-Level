/*1135. Is It A Red-Black Tree (30)
There is a kind of balanced binary search tree named red-black tree in the data structure. It has the following 5 properties:
(1) Every node is either red or black.
(2) The root is black.
(3) Every leaf (NULL) is black.
(4) If a node is red, then both its children are black.
(5) For each node, all simple paths from the node to descendant leaves contain the same number of black nodes. 
For example, the tree in Figure 1 is a red-black tree, while the ones in Figure 2 and 3 are not.



Figure 1
Figure 2
Figure 3
For each given binary search tree, you are supposed to tell if it is a legal red-black tree.
Input Specification: 
Each input file contains several test cases. The first line gives a positive integer K (<=30) which is the total number of cases. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the preorder traversal sequence of the tree. While all the keys in a tree are positive integers, we use negative signs to represent red nodes. All the numbers in a line are separated by a space. The sample input cases correspond to the trees shown in Figure 1, 2 and 3.
Output Specification: 
For each test case, print in a line "Yes" if the given tree is a red-black tree, or "No" if not.
Sample Input:
3
9
7 -2 1 5 -4 -11 8 14 -15
9
11 -2 1 -7 5 -4 8 14 -15
8
10 -7 5 -6 8 15 -11 17
Sample Output:
Yes
No
No

*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct node{
	int value;
	bool black;
	node* left;
	node* right;
};
node* newNode(int x)
{
	node* root=new node;
	root->left=NULL;
	root->right=NULL;
	if(x<0)
	{
		root->value=-x;
		root->black=false;
	}
	else
	{
		root->value=x;
		root->black=true;
	}
	return root;
}
void Insert(node* &root,int x)
{
	if(root==NULL)
	{
		root=newNode(x);
		return;
	}
	if(abs(x)<=root->value)
	{
		Insert(root->left,x);
	}
	else
	{
		Insert(root->right,x);
	}
}
bool Judge(node* root)
{
	if(!root->black)
	{
		return false;
	}
	return true;
}
bool flag2=true;
void Judge2(node* root)
{
	if(!flag2)
		return;
	if(!(root->black))
	{
		if(root->left!=NULL)
		{
			if(!(root->left->black))
			{
				flag2=false;
				return;
			}
			Judge2(root->left);
		}
		if(root->right!=NULL)
		{
			if(!(root->right->black))
			{
				flag2=false;
				return;
			}
			Judge2(root->right);
		}
	}
	else
	{
		if(root->left!=NULL)
		{
			Judge2(root->left);
		}
		if(root->right!=NULL)
		{
			Judge2(root->right);
		}
	}
}
int GetBlack(node* root)
{
	int a=0;
	node* temp=root;
	while(temp!=NULL)
	{
		if(temp->black)
			a++;
		temp=temp->left;
	}
	return a;	
}
bool flag3=true;
void Judge3(node* root,int u,int k)
{
	if(!flag3)
		return;
	if(root==NULL)
	{
		if(k!=u)
			flag3=false;
		return;
	}
	if(root->black)
	{
		Judge3(root->left,u,k+1);
		Judge3(root->right,u,k+1);
	}
	else
	{
		Judge3(root->left,u,k);
		Judge3(root->right,u,k);
	}
}
int main()
{
	int k,n,x;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d",&n);
		node* root=NULL;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			Insert(root,x);
		}
		flag2=true;
		flag3=true;
		Judge2(root);
		Judge3(root,GetBlack(root),0);
		if((!Judge(root))||(!flag2)||(!flag3))
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
 } 
