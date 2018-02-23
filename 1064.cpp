/*1064. Complete Binary Search Tree (30)
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than the node's key. 
The right subtree of a node contains only nodes with keys greater than or equal to the node's key. 
Both the left and right subtrees must also be binary search trees. 
A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.
Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT. You are supposed to output the level order traversal sequence of this BST.
Input Specification: 
Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.
Output Specification: 
For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line. 
Sample Input:
10
1 2 3 4 5 6 7 8 9 0
Sample Output:
6 3 8 1 5 7 9 0 2 4
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct node{
	int data;
	int left;
	int right;
}tree[1000];
int d[1000];
int num=0;
void PreOrder(int a)
{
	if(a==-1)
		return;
	PreOrder(tree[a].left);
	tree[a].data=d[num++];
	PreOrder(tree[a].right);
}
void LevelOrder(int a)
{
	queue<int> q;
	q.push(a);
	bool flag=true;
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		if(!flag)
		{
			printf(" ");
		}
		flag=false;
		printf("%d",tree[temp].data);
		if(tree[temp].left!=-1)
			q.push(tree[temp].left);
		if(tree[temp].right!=-1)
			q.push(tree[temp].right);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&d[i]);
	}
	sort(d,d+n);
	for(int i=0;i<n;i++)
	{
		int tempr=2*i+2;
		if(tempr<n)
		{
			tree[i].left=tempr-1;
			tree[i].right=tempr;
		}
		else if(tempr==n)
		{
			tree[i].left=tempr-1;
			tree[i].right=-1;
		}
		else
		{
			tree[i].left=-1;
			tree[i].right=-1;
		}
	}
	PreOrder(0);
	LevelOrder(0);
	return 0;
 } 
