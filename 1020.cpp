/*1020. Tree Traversals (25)
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.
Output Specification: 
For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.
Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int postorder[30];
int inorder[30]; 
int level[100000];

void LevelOrder(int start,int end,int root,int p)
{
	if(start>end)
		return;
	for(int i=start;i<=end;i++)
	{
		if(inorder[i]==postorder[root])
		{
			level[p]=inorder[i];
			LevelOrder(start,i-1,root-end+i-1,2*p+1);
			LevelOrder(i+1,end,root-1,2*p+2);
			break;
		}
	}
}
int main()
{
	memset(level,0,sizeof(level));
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&postorder[i]);
	}
	for(int i=0;i<N;i++)
	{
		scanf("%d",&inorder[i]);
	}
	LevelOrder(0,N-1,N-1,0);
	printf("%d",level[0]);
	int cn=1;
	for(int i=1;i<100000;i++)
	{
		if(level[i])
		{
			printf(" %d",level[i]);
			cn++;
		}
		if(cn==N)
			break;
	}
	return 0;
 } 
