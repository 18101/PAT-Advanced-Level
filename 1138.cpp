/*1138. Postorder Traversal (25)
Suppose that all the keys in a binary tree are distinct positive integers. Given the preorder and inorder traversal sequences, you are supposed to output the first number of the postorder traversal sequence of the corresponding binary tree. 
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<=50000), the total number of nodes in the binary tree. The second line gives the preorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.
Output Specification: 
For each test case, print in one line the first number of the postorder traversal sequence of the corresponding binary tree. 
Sample Input:
7
1 2 3 4 5 6 7
2 3 1 5 4 7 6
Sample Output:
3
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int preorder[50010];
int inorder[50010];
bool flag=false;
void LevelOrder(int start,int end,int root)
{
	if(flag||start>end)
	{
		return;
	}
	if(start==end)
	{
		printf("%d",inorder[start]);
		flag=true;
		return;
	}
	for(int i=start;i<=end;i++)
	{
		if(inorder[i]==preorder[root])
		{
			LevelOrder(start,i-1,root+1);
			LevelOrder(i+1,end,root+i-start+1);
			break;
		}
	}

}
int main()
{
	memset(preorder,0,sizeof(preorder));
	memset(inorder,0,sizeof(inorder));
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&preorder[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&inorder[i]);
	}
	LevelOrder(0,n-1,0);
	return 0;
 } 
