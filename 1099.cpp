/*1099. Build A Binary Search Tree (30)
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than the node's key. 
The right subtree of a node contains only nodes with keys greater than or equal to the node's key. 
Both the left and right subtrees must also be binary search trees. 
Given the structure of a binary tree and a sequence of distinct integer keys, there is only one way to fill these keys into the tree so that the resulting tree satisfies the definition of a BST. You are supposed to output the level order traversal sequence of that tree. The sample is illustrated by Figure 1 and 2. 

Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<=100) which is the total number of nodes in the tree. The next N lines each contains the left and the right children of a node in the format "left_index right_index", provided that the nodes are numbered from 0 to N-1, and 0 is always the root. If one child is missing, then -1 will represent the NULL child pointer. Finally N distinct integer keys are given in the last line.
Output Specification: 
For each test case, print in one line the level order traversal sequence of that tree. All the numbers must be separated by a space, with no extra space at the end of the line. 
Sample Input:
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
Sample Output:
58 25 82 11 38 67 45 73 42
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct node{
	int data;
	int left;
	int right;
	string pos;
}tree[100];
vector<node> v1;
int d[100],u=0;
void PreOrder(int k)
{
	if(k==-1)
		return;
	PreOrder(tree[k].left);
	tree[k].data=d[u++];
	PreOrder(tree[k].right);
}
int main()
{
	int n;
	queue<int> q;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&tree[i].left,&tree[i].right);
	}
	for(int i=0;i<n;i++)
		scanf("%d",&d[i]);
	sort(d,d+n);
	int num=0;
	PreOrder(0);
	q.push(0);
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		if(num)
			printf(" ");
		num++;
		printf("%d",tree[temp].data);
		if(tree[temp].left!=-1)
			q.push(tree[temp].left);
		if(tree[temp].right!=-1)
			q.push(tree[temp].right);
	}
	return 0;
 } 
