/*1086. Tree Traversals Again (25)
An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree. 

Figure 1
Input Specification: 
Each input file contains one test case. For each case, the first line contains a positive integer N (<=30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.
Output Specification: 
For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line. 
Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:
3 4 2 6 5 1
*/
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int preorder[31];
int inorder1[31];
stack<int> inorder2;
int postorder[31];

void GetPos(int start,int end,int p,int q)
{
	if(start>end)
		return;
	for(int i=start;i<=end;i++)
	{
		if(inorder1[i]==preorder[p])
		{
			postorder[q]=inorder1[i];
			GetPos(i+1,end,p+i-start+1,q-1);
			GetPos(start,i-1,p+1,q-end+i-1);
			break;
		}
	}
}
int main()
{
	int n;
	char p[5];
	scanf("%d",&n);
	int pre=0,in=0;
	for(int i=0;i<2*n;i++)
	{
		scanf("%s",p);
		if(p[1]=='u')
		{
			scanf("%d",&preorder[pre]);
			inorder2.push(preorder[pre]);
			pre++;
		}
		else
		{
			inorder1[in]=inorder2.top();
			inorder2.pop();
			in++;
		}
	}
	GetPos(0,n-1,0,n-1);
	printf("%d",postorder[0]);
	for(int i=1;i<n;i++)
	{
		printf(" %d",postorder[i]);
	}
	return 0;
}
