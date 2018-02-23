/*1066. Root of AVL Tree (25)
An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.
    

    
Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.

Input Specification: 
Each input file contains one test case. For each case, the first line contains a positive integer N (<=20) which is the total number of keys to be inserted. Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.
Output Specification: 
For each test case, print ythe root of the resulting AVL tree in one line.
Sample Input 1:
5
88 70 61 96 120
Sample Output 1:
70
Sample Input 2:
7
88 70 61 96 120 90 65
Sample Output 2:
88
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
	int data;
	int height;
	node* left;
	node* right;
};
node* newNode(int x)
{
	node* root=new node;
	root->data=x;
	root->height=1;
	root->left=NULL;
	root->right=NULL;
	return root;
}
int getHeight(node* root)
{
	if(root==NULL)
		return 0;
	return root->height;
}
int getBalanceFactor(node* root)
{
	return getHeight(root->left)-getHeight(root->right);
}
void updateHeight(node* root)
{
	root->height=max(getHeight(root->left),getHeight(root->right))+1;
}
void L(node* &root)
{
	node* temp=root->right;
	root->right=temp->left;
	temp->left=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}
void R(node* &root)
{
	node* temp=root->left;
	root->left=temp->right;
	temp->right=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}
void Insert(node* &root,int x)
{
	if(root==NULL)
	{
		root=newNode(x);
		return;
	}
	if(x<root->data)
	{
		Insert(root->left,x);
		updateHeight(root);
		if(getBalanceFactor(root)==2)
		{
			if(getBalanceFactor(root->left)==-1)
			{
				L(root->left);	
			}
			R(root);
		}	
	}
	else
	{
		Insert(root->right,x);
		updateHeight(root);
		if(getBalanceFactor(root)==-2)
		{
			if(getBalanceFactor(root->right)==1)
			{
				R(root->right);
			}
			L(root);
		}
	}
}
int main()
{
	int n,x;
	scanf("%d",&n);
	node* root=NULL;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		Insert(root,x);
	}
	printf("%d",root->data);
	return 0;
 } 
