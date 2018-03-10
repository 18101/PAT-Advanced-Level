/*1115. Counting Nodes in a BST (30)
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than or equal to the node's key. 
The right subtree of a node contains only nodes with keys greater than the node's key. 
Both the left and right subtrees must also be binary search trees. 
Insert a sequence of numbers into an initially empty binary search tree. Then you are supposed to count the total number of nodes in the lowest 2 levels of the resulting tree.
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<=1000) which is the size of the input sequence. Then given in the next line are the N integers in [-1000 1000] which are supposed to be inserted into an initially empty binary search tree.
Output Specification: 
For each case, print in one line the numbers of nodes in the lowest 2 levels of the resulting tree in the format:
n1 + n2 = n 
where n1 is the number of nodes in the lowest level, n2 is that of the level above, and n is the sum. 
Sample Input:
9
25 30 42 16 20 20 35 -5 28
Sample Output:
2 + 4 = 6
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
struct node{
	int value;
	int level;
	node* left;
	node* right;
};
int levels[1005];
int data[1005];
node* newNode(int x)
{
	node* root=new node;
	root->value=x;
	root->left=NULL;
	root->right=NULL;
	root->level=0;
	return root;
}
void Insert(node* &root,int x,int l)
{
	if(root==NULL)
	{
		root=newNode(x);
		root->level=l;
		levels[l]++;
	}
	else
	{
		if(x<=root->value)
		{
			Insert(root->left,x,l+1);
		}
		else
		{
			Insert(root->right,x,l+1);
		}
	}
}
void Create(int x,node* root)
{
	for(int i=0;i<x;i++)
	{
		Insert(root,data[i],0);
	}
}
int main()
{
	memset(levels,0,sizeof(levels));
	int n;
	node* root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
	}
	Create(n,root);
	int j=0;
	for(int i=0;i<=1000;i++)
	{
		if(!levels[i])
		{
			j=i;
			break;
		}
	}
	printf("%d + %d = %d",levels[j-1],levels[j-2],levels[j-1]+levels[j-2]);
	return 0;
 } 
