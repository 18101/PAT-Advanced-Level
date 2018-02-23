/*1004. Counting Leaves (30)
A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.

Input
Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:
ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.

Output
For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.
The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.
Sample Input
2 1
01 1 02
Sample Output
0 1
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct node{
	int level;
	vector<int> v;
}tree[105];
int main()
{
	queue<int> q;
	int countl[105];
	memset(countl,0,sizeof(countl));
	int n,m,father,num,l;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&father);
		scanf("%d",&num);
		for(int j=0;j<num;j++)
		{
			scanf("%d",&l);
			tree[father].v.push_back(l);
		}
	}
	q.push(1);
	tree[1].level=0;
	int maxl=-1;
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		if(tree[temp].level>maxl)
			maxl=tree[temp].level;
		if(tree[temp].v.size()==0)
		{
			countl[tree[temp].level]++;
		}
		for(int i=0;i<tree[temp].v.size();i++)
		{
			q.push(tree[temp].v[i]);
			tree[tree[temp].v[i]].level=tree[temp].level+1;
		}
	}
	printf("%d",countl[0]);
	for(int i=1;i<=maxl;i++)
		printf(" %d",countl[i]);
	return 0;
 } 
