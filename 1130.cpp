/*1130. Infix Expression (25)
Given a syntax tree (binary), you are supposed to output the corresponding infix expression, with parentheses reflecting the precedences of the operators. 
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N ( <= 20 ) which is the total number of nodes in the syntax tree. Then N lines follow, each gives the information of a node (the i-th line corresponds to the i-th node) in the format: 
data left_child right_child 
where data is a string of no more than 10 characters, left_child and right_child are the indices of this node's left and right children, respectively. The nodes are indexed from 1 to N. The NULL link is represented by -1. The figures 1 and 2 correspond to the samples 1 and 2, respectively. 


Figure 1
Figure 2
Output Specification: 
For each case, print in a line the infix expression, with parentheses reflecting the precedences of the operators. Note that there must be no extra parentheses for the final expression, as is shown by the samples. There must be no space between any symbols. 
Sample Input 1:
8
* 8 7
a -1 -1
* 4 1
+ 2 5
b -1 -1
d -1 -1
- -1 6
c -1 -1
Sample Output 1:
(a+b)*(c*(-d))
Sample Input 2:
8
2.35 -1 -1
* 6 1
- -1 4
% 7 8
+ 2 3
a -1 -1
str -1 -1
871 -1 -1
Sample Output 2:
(a*2.35)+(-(str%871))
*/
#include <iostream>
#include <cstdio>
using namespace std;
struct node{
	string str;
	int father;
	int left;
	int right;
}tree[25];
int FindRoot(int a)
{
	while(tree[a].father!=a)
	{
		a=tree[a].father;
	}
	return a;
}
string PreOrder(int root,int x)
{
	if(root==-1)
	{
		return "";
	}
	if(tree[root].right!=-1)
	{
		tree[root].str=PreOrder(tree[root].left,x)+tree[root].str+PreOrder(tree[root].right,x);
		if(root!=x)
		{
			tree[root].str="("+tree[root].str+")";
		}
		return tree[root].str;
	}
	else
	{
		return tree[root].str;	
	}	
}
int main()
{
	int n;
	string s;
	int a,b;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		tree[i].father=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s>>a>>b;
		tree[i].left=a;
		tree[i].right=b;
		tree[i].str=s;
		if(a!=-1)
		{
			tree[a].father=i;
		}
		if(b!=-1)
		{
			tree[b].father=i;
		}
	}
	int root=FindRoot(1);
	cout<<PreOrder(root,root);
	return 0;
 } 
