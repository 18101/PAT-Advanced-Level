/*1021. Deepest Root (25)
A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.
Input Specification: 
Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N-1 lines follow, each describes an edge by given the two adjacent nodes' numbers.
Output Specification: 
For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print "Error: K components" where K is the number of connected components in the graph.
Sample Input 1:
5
1 2
1 3
1 4
2 5
Sample Output 1:
3
4
5
Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
int n;
vector<int> v[10001];
set<int> s;
int father[10001];
bool flag[10001];
void init()
{
	for(int i=1;i<=n;i++)
	{
		father[i]=i;
	}
}
int findFather(int x)
{
	int a=x;
	while(x!=father[x])
	{
		x=father[x];
	}
	while(a!=father[a])
	{
		int z=a;
		father[z]=x;
		a=father[a];
	}
	return x;
}
void Union(int x,int y)
{
	int a=findFather(x);
	int b=findFather(y);
	if(a!=b)
		father[a]=b;
}
int countBlock()
{
	int a=0;
	for(int i=1;i<=n;i++)
	{
		if(father[i]==i)
			a++;
	}
	return a;
}
int maxheight;
void DFS(int a,int height)
{ 
	if(height>maxheight)
	{
		s.clear();
		s.insert(a);
		maxheight=height;
	}
	else if(height==maxheight)
	{
		s.insert(a);
	}
	flag[a]=true;
	for(int i=0;i<v[a].size();i++)
	{
		if(!flag[v[a][i]])
		{
			DFS(v[a][i],height+1);
		}
	}
	flag[a]=false;
}
int main()
{
	scanf("%d",&n);
	int x,y;
	init();
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
		Union(x,y);
	}
	int count=countBlock();
	if(count!=1)
	{
		printf("Error: %d components",count);
	}
	else
	{
		memset(flag,0,sizeof(flag));
		maxheight=0;
		DFS(1,1);
		vector<int> ss;
		for(set<int>::iterator it=s.begin();it!=s.end();it++)
		{
			ss.push_back(*it);
		}
		memset(flag,0,sizeof(flag));
		DFS(*(s.begin()),1);
		for(int i=0;i<ss.size();i++)
		{
			s.insert(ss[i]);
		}
		for(set<int>::iterator it=s.begin();it!=s.end();it++)
		{
			printf("%d\n",*it);
		}
	}
	return 0;
 } 
