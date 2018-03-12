/*1127. ZigZagging on a Tree (30)
Suppose that all the keys in a binary tree are distinct positive integers. A unique binary tree can be determined by a given pair of postorder and inorder traversal sequences. And it is a simple standard routine to print the numbers in level-order. However, if you think the problem is too simple, then you are too naive. This time you are supposed to print the numbers in "zigzagging order" -- that is, starting from the root, print the numbers level-by-level, alternating between left to right and right to left. For example, for the following tree you must output: 1 11 5 8 17 12 20 15.

Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<= 30), the total number of nodes in the binary tree. The second line gives the inorder sequence and the third line gives the postorder sequence. All the numbers in a line are separated by a space.
Output Specification: 
For each test case, print the zigzagging sequence of the tree in a line. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.
Sample Input:
8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1
Sample Output:
1 11 5 8 17 12 20 15
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int inorder[31];
int postorder[31];
struct node{
	int value;
	int level;
	node* left;
	node* right;
};
struct node2{
	int level;
	int value;
};
node* newNode(int x,int l)
{
	node* root=new node;
	root->value=x;
	root->level=l;
	root->left=NULL;
	root->right=NULL;
	return root;
}
node* LevelOrderTree(int start,int end,int root,int l)
{
	if(start>end)
	{
		return NULL;
	}
	node* p=newNode(postorder[root],l);
	int j=0;
	for(int i=start;i<=end;i++)
	{
		if(inorder[i]==postorder[root])
		{
			j=i;
			break;
		}
	}
	p->left=LevelOrderTree(start,j-1,root-end+j-1,l+1);
	p->right=LevelOrderTree(j+1,end,root-1,l+1);
	return p;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&inorder[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&postorder[i]);
	}
	node* tree=NULL;
	tree=LevelOrderTree(0,n-1,n-1,1);
	queue<node*> q;
	vector<node2> v;
	q.push(tree);
	while(!q.empty())
	{
		node* temp=q.front();
		q.pop();
		if(temp->left!=NULL)
		{
			q.push(temp->left);
		}
		if(temp->right!=NULL)
		{
			q.push(temp->right);
		}
		node2 nn;
		nn.level=temp->level;
		nn.value=temp->value;
		v.push_back(nn);
	}
	printf("%d",v[0].value);
	int u=2;
	for(int i=1;i<v.size();)
	{
		if(u%2)
		{
			int j=i;
			while(v[i].level==u&&i<n)
			{
				i++;
			}
			for(int k=i-1;k>=j;k--)
			{
				printf(" %d",v[k].value);
			}
			u++;
		}
		else
		{
			while(v[i].level==u&&i<n)
			{
				printf(" %d",v[i].value);
				i++;	
			}
			u++;	
		} 
	}
	return 0;
 } 
