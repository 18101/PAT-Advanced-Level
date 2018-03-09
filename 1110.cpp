/*1110. Complete Binary Tree (25)
Given a tree, you are supposed to tell if it is a complete binary tree.
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<=20) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N-1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.
Output Specification: 
For each case, print in one line "YES" and the index of the last node if the tree is a complete binary tree, or "NO" and the index of the root if not. There must be exactly one space separating the word and the number. 
Sample Input 1:
9
7 8
- -
- -
- -
0 1
2 3
4 5
- -
- -
Sample Output 1:
YES 8
Sample Input 2:
8
- -
4 5
0 6
- -
2 3
- 7
- -
- -
Sample Output 2:
NO 1
*/
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct node{
	int father;
	int left;
	int right;
}tree[20];
int getRoot(int a)
{
	while(tree[a].father!=a)
	{
		a=tree[a].father;
	}
	return a;
}
int main()
{
	int n;
	int c1=-1,c2=-1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		tree[i].father=i;
	}
	for(int i=0;i<n;i++)
	{
		getchar();
		if(cin.peek()=='-')
		{
			tree[i].left=-1;
			cin.get();
		}
		else
		{
			cin>>c1;
			tree[i].left=c1;
			tree[c1].father=i;
		}
		getchar();
		if(cin.peek()=='-')
		{
			tree[i].right=-1;
			cin.get();
		}
		else
		{
			cin>>c2;
			tree[i].right=c2;
			tree[c2].father=i;
		}
	}
	if(c1==-1&&c2==-1)
	{
		cout<<"YES 0\n";
		return 0;
	}
	int root=-1;
	if(c1==-1)
		c1=c2;
	root=getRoot(c1);
	queue<int> q;
	q.push(root);
	bool flag1=true,flag2=true;
	int temp;
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		if(tree[temp].left!=-1)
		{
			if(!flag1)
			{
				flag2=false;
				break;
			}
			q.push(tree[temp].left);
		}
		else
		{
			flag1=false;
		}
		if(tree[temp].right!=-1)
		{
			if(!flag1)
			{
				flag2=false;
				break;
			}
			q.push(tree[temp].right);
		}
		else
		{
			flag1=false;
		}
	}
	if(!flag2)
	{
		cout<<"NO "<<root;
	}
	else
	{
		cout<<"YES "<<temp;
	}
	return 0;
 } 
