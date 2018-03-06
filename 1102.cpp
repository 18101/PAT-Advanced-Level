/*1102. Invert a Binary Tree (25)
The following is from Max Howell @twitter:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can't invert a binary tree on a whiteboard so fuck off.
Now it's your turn to prove that YOU CAN invert a binary tree!
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<=10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N-1. Then N lines follow, each corresponds to a node from 0 to N-1, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.
Output Specification: 
For each test case, print in the first line the level-order, and then in the second line the in-order traversal sequences of the inverted tree. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.
Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:
3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct node{
	int left;
	int right;
}tree[10];
bool vis[10]={false};
vector<int> v;
int Get(char a)
{
	if(a=='-')
		return -1;
	else
		return a-'0';
}
void LevelOrder(int root)
{
	queue<int> q;
	q.push(root);
	bool flag=false;
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		if(tree[temp].right!=-1)
			q.push(tree[temp].right);
		if(tree[temp].left!=-1)
			q.push(tree[temp].left);
		if(flag)
		{
			printf(" ");
		}
		printf("%d",temp);
		flag=true;
	}
}
void InOrder(int root)
{
	if(tree[root].right!=-1)
		InOrder(tree[root].right);
	v.push_back(root);
	if(tree[root].left!=-1)
		InOrder(tree[root].left);
}
int main()
{
	int n,x,y;
	char c1,c2;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++)
	{
		scanf("%c",&c1);
		getchar();
		scanf("%c",&c2);
		getchar();
		x=Get(c1);
		y=Get(c2);
		tree[i].left=x;
		tree[i].right=y;
		if(x!=-1)
			vis[x]=true;
		if(y!=-1)
			vis[y]=true;
	}
	int root;
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
			root=i;
	}
	LevelOrder(root);
	printf("\n");
	InOrder(root);
	printf("%d",v[0]);
	if(!v.empty())
	{
		for(int i=1;i<v.size();i++)
		{
			printf(" %d",v[i]);
		}
	}
	return 0;
}
