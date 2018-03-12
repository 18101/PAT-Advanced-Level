/*1119. Pre- and Post-order Traversals (30)
Suppose that all the keys in a binary tree are distinct positive integers. A unique binary tree can be determined by a given pair of postorder and inorder traversal sequences, or preorder and inorder traversal sequences. However, if only the postorder and preorder traversal sequences are given, the corresponding tree may no longer be unique.
Now given a pair of postorder and preorder traversal sequences, you are supposed to output the corresponding inorder traversal sequence of the tree. If the tree is not unique, simply output any one of them.
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the preorder sequence and the third line gives the postorder sequence. All the numbers in a line are separated by a space.
Output Specification: 
For each test case, first printf in a line "Yes" if the tree is unique, or "No" if not. Then print in the next line the inorder traversal sequence of the corresponding binary tree. If the solution is not unique, any answer would do. It is guaranteed that at least one solution exists. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.
Sample Input 1:
7
1 2 3 4 6 7 5
2 6 7 4 5 3 1
Sample Output 1:
Yes
2 1 6 4 7 3 5
Sample Input 2:
4
1 2 3 4
2 4 3 1
Sample Output 2:
No
2 1 3 4
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int postorder[31];
int preorder[31];
struct node{
	int value;
	node* left;
	node* right;
};
node* newNode(int x)
{
	node* root=new node;
	root->value=x;
	root->left=NULL;
	root->right=NULL;
	return root;
}
bool flag=false;
node* GetLevelOrder(int pres,int pree,int posts,int poste)
{
	if(posts>poste)
		return NULL;
	node* p=newNode(postorder[poste]);
	if(poste==posts)
		return p;
	int j;
	for(int i=posts;i<=poste-1;i++)
	{
		if(preorder[pres+1]==postorder[i])
		{
			j=i;
			if(i==poste-1)
				flag=true;
			break;
		}
	}
	p->left=GetLevelOrder(pres+1,pres+j-posts+1,posts,j);
	p->right=GetLevelOrder(pres+j-posts+2,pree,j+1,poste-1);
	return p;
}
vector<int> v;
void Inorder(node* root)
{
	if(root->left!=NULL)
	{
		Inorder(root->left);
	}
	v.push_back(root->value);
	if(root->right!=NULL)
	{
		Inorder(root->right);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&preorder[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&postorder[i]);
	}
	node* root=GetLevelOrder(0,n-1,0,n-1);
	if(flag)
		printf("No\n");
	else
		printf("Yes\n");
	Inorder(root);
	printf("%d",v[0]);
	for(int i=1;i<v.size();i++)
	{
		printf(" %d",v[i]);
	}
	printf("\n");
	return 0;
 } 
