/*1053. Path of Equal Weight (30)
Given a non-empty tree with root R, and with weight Wi assigned to each tree node Ti. The weight of a path from R to L is defined to be the sum of the weights of all the nodes along the path from R to any leaf node L.
Now given any weighted tree, you are supposed to find all the paths with their weights equal to a given number. For example, let's consider the tree showed in Figure 1: for each node, the upper number is the node ID which is a two-digit number, and the lower number is the weight of that node. Suppose that the given number is 24, then there exists 4 different paths which have the same given weight: {10 5 2 7}, {10 4 10}, {10 3 3 6 2} and {10 3 3 6 2}, which correspond to the red edges in Figure 1. 

Figure 1
Input Specification: 
Each input file contains one test case. Each case starts with a line containing 0 < N <= 100, the number of nodes in a tree, M (< N), the number of non-leaf nodes, and 0 < S < 230, the given weight number. The next line contains N positive numbers where Wi (<1000) corresponds to the tree node Ti. Then M lines follow, each in the format:
ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 00.
Output Specification: 
For each test case, print all the paths with weight S in non-increasing order. Each path occupies a line with printed weights from the root to the leaf in order. All the numbers must be separated by a space with no extra space at the end of the line. 
Note: sequence {A1, A2, ..., An} is said to be greater than sequence {B1, B2, ..., Bm} if there exists 1 <= k < min{n, m} such that Ai = Bi for i=1, ... k, and Ak+1 > Bk+1.
Sample Input:
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
Sample Output:
10 5 2 7
10 4 10
10 3 3 6 2
10 3 3 6 2
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct node{
	int father;
	int weight;
	vector<int> children;
}tree[101];
int ww[101];
void Get(int a)
{
	for(int i=0;i<tree[a].children.size();i++)
	{
		ww[tree[a].children[i]]=tree[tree[a].children[i]].weight+ww[a];
		Get(tree[a].children[i]);
	}
}
bool cmp(vector<int> a,vector<int> b)
{
	int s1=a.size(),s2=b.size();
	int s=min(s1,s2);
	for(int i=1;i<=s;i++)
	{
		if(a[s1-i]>b[s2-i])
			return true;
		else if(a[s1-i]<b[s2-i])
			return false;
		if(i==s)
		{
			if(s1>s2)
				return true;
			else
				return false;
		}
	}
 } 
int main()
{
	int n,m,s,f,k,x;
	vector<vector<int> >v;
//	vector<int> v2;
	scanf("%d %d %d",&n,&m,&s);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tree[i].weight);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&f,&k,&x);
		for(int i=0;i<k;i++)
		{
			scanf("%d",&x);
			tree[f].children.push_back(x);
			tree[x].father=f;
		}
	}
	ww[0]=tree[0].weight;
	Get(0);
	int intex;
	for(int i=0;i<n;i++)
	{
		vector<int> v2;
		if(!tree[i].children.size()&&ww[i]==s)
		{
			intex=i;
			while(intex!=0)
			{
				v2.push_back(tree[intex].weight);
				intex=tree[intex].father;
			}
			v2.push_back(tree[0].weight);
			v.push_back(v2);
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++)
	{
		printf("%d",v[i][v[i].size()-1]);
		for(int j=v[i].size()-2;j>=0;j--)
		{
			printf(" %d",v[i][j]);
		}
		printf("\n");
	}
	return 0;
}
