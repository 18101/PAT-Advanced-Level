/*1043. Is It a Binary Search Tree (25)
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than the node's key. 
The right subtree of a node contains only nodes with keys greater than or equal to the node's key. 
Both the left and right subtrees must also be binary search trees. 
If we swap the left and right subtrees of every node, then the resulting tree is called the Mirror Image of a BST.
Now given a sequence of integer keys, you are supposed to tell if it is the preorder traversal sequence of a BST or the mirror image of a BST.
Input Specification: 
Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N integer keys are given in the next line. All the numbers in a line are separated by a space.
Output Specification: 
For each test case, first print in a line "YES" if the sequence is the preorder traversal sequence of a BST or the mirror image of a BST, or "NO" if not. Then if the answer is "YES", print in the next line the postorder traversal sequence of that tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line. 
Sample Input 1:
7
8 6 5 7 10 8 11
Sample Output 1:
YES
5 7 6 8 11 10 8
Sample Input 2:
7
8 10 11 8 6 7 5
Sample Output 2:
YES
11 8 10 7 5 6 8
Sample Input 3:
7
8 6 8 5 10 9 11
Sample Output 3:
NO
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> v2,v3,v4;
struct node{
	int data;
	node* left;
	node* right;
};
node* newNode(int x)
{
	node* Node=new node;
	Node->data=x;
	Node->left=Node->right=NULL;
	return Node;
}
void insert(node* &root,int x)
{
	if(root==NULL)
	{
		root=newNode(x);
		return;
	}
	else
	{
		if(x<root->data)
		{
			insert(root->left,x);
		}
		else
		{
			insert(root->right,x);
		}
	}
}
node* Create(int data[],int n)
{
	node* root=NULL;
	for(int i=0;i<n;i++)
	{
		insert(root,data[i]);
	}
	return root;
}
void PreOrder(node* root)
{
	if(root==NULL)
		return;
	v2.push_back(root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
void MirrorOrder(node* root)
{
	if(root==NULL)
		return;
	v4.push_back(root->data);
	MirrorOrder(root->right);
	MirrorOrder(root->left);
}
void PostOrder(node* root)
{
	if(root==NULL)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	v3.push_back(root->data);
}
void PostOrder2(node* root)
{
	if(root==NULL)
		return;
	PostOrder2(root->right);
	PostOrder2(root->left);
	v3.push_back(root->data);
}
int main()
{
	int n,x;
	int data[1000];
	scanf("%d",&n);
	vector<int> v1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
	}
	node* root=Create(data,n);
	PreOrder(root);
	MirrorOrder(root);
	bool flag1=true,flag2=true;
	for(int i=0;i<n;i++)
	{
		if(v2[i]!=data[i])
		{
			flag1=false;
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(v4[i]!=data[i])
		{
			flag2=false;
			break;
		}
	}
	if(!flag1&&!flag2)
		printf("NO");
	else
	{
		printf("YES\n");
		if(flag1)
		{
			PostOrder(root);
			printf("%d",v3[0]);
			for(int i=1;i<n;i++)
			{
				printf(" %d",v3[i]);
			}
		}
		else
		{
			PostOrder2(root);
			printf("%d",v3[0]);
			for(int i=1;i<n;i++)
			{
				printf(" %d",v3[i]);
			}
		}
	}
	return 0;
 } 
