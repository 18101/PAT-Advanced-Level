/*1123. Is It a Complete AVL Tree (30)
An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.
    

    
Now given a sequence of insertions, you are supposed to output the level-order traversal sequence of the resulting AVL tree, and to tell if it is a complete binary tree.
Input Specification: 
Each input file contains one test case. For each case, the first line contains a positive integer N (<= 20). Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.
Output Specification: 
For each test case, insert the keys one by one into an initially empty AVL tree. Then first print in a line the level-order traversal sequence of the resulting AVL tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line. Then in the next line, print "YES" if the tree is complete, or "NO" if not. 
Sample Input 1:
5
88 70 61 63 65
Sample Output 1:
70 63 88 61 65
YES
Sample Input 2:
8
88 70 61 96 120 90 65 68
Sample Output 2:
88 65 96 61 70 90 120 68
NO
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
struct node{
  int value;
  int height;
  node* left;
  node* right;
};
int data[2000];
bool judge[2000]={false};
node* newNode(int x)
{
  node* root=new node;
  root->height=1;
  root->value=x;
  root->left=NULL;
  root->right=NULL;
  return root;
}
int GetHeight(node* root)
{
  if(root==NULL)
    return 0;
  else
    return root->height;
}
int BalanceFactor(node* root)
{
  if(root==NULL)
    return 0;
//  printf("hhh");
  return GetHeight(root->left)-GetHeight(root->right);
}
void L(node* &root)
{
  node* temp=root->right;
  root->right=temp->left;
  temp->left=root;
  root=temp;
  temp=root->left;
  temp->height=max(GetHeight(temp->left),GetHeight(temp->right))+1;
  root->height=max(GetHeight(root->left),GetHeight(root->right))+1;
}
void R(node* &root)
{
  node* temp=root->left;
  root->left=temp->right;
  temp->right=root;
  root=temp;
  temp=root->right;
  temp->height=max(GetHeight(temp->left),GetHeight(temp->right))+1;
  root->height=max(GetHeight(root->left),GetHeight(root->right))+1;
}
void Insert(node* &root,int x)
{
  if(root==NULL)
  {
    root=newNode(x);
  }
  else
  {
    if(x<root->value)
    {
      Insert(root->left,x);
      root->height=max(GetHeight(root->left),GetHeight(root->right))+1;
      if(BalanceFactor(root)==2)
      {
        if(BalanceFactor(root->left)==1)
        {
          R(root);
        }
        else
        {
          L(root->left);
          R(root);
        }
      }
    }
    else
    {
      Insert(root->right,x);
      root->height=max(GetHeight(root->left),GetHeight(root->right))+1;
      if(BalanceFactor(root)==-2)
      {
        if(BalanceFactor(root->right)==-1)
        {
          L(root);
        }
        else
        {
          R(root->right);
          L(root);
        }
      }
    }
  }
}
void Level(node* root,int p)
{
  data[p]=root->value;
  judge[p]=true;
  if(root->left!=NULL)
  {
    Level(root->left,2*p+1);
  }
  if(root->right!=NULL)
  {
    Level(root->right,2*p+2);
  }
}
int main()
{
  int n,x;
  scanf("%d",&n);
  node* root=NULL;
  for(int i=0;i<n;i++)
  {
    scanf("%d",&x);
    Insert(root,x);
  }
  Level(root,0);
  bool ff=false;
  for(int i=0;i<2000;i++)
  {
    if(judge[i])
    {
      if(ff)
      {
        printf(" ");
      }
      printf("%d",data[i]);
      ff=true;
    }
  }
  printf("\n");
  for(int i=0;i<n;i++)
  {
    if(!judge[i])
    {
      printf("NO");
      return 0;
    }
  }
  printf("YES");
  return 0;
 } 
