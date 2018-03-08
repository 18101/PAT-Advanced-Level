/*1107. Social Clusters (30)
When register on a social network, you are always asked to specify your hobbies in order to find some potential friends with the same hobbies. A "social cluster" is a set of people who have some of their hobbies in common. You are supposed to find all the clusters.
Input Specification: 
Each input file contains one test case. For each test case, the first line contains a positive integer N (<=1000), the total number of people in a social network. Hence the people are numbered from 1 to N. Then N lines follow, each gives the hobby list of a person in the format:
Ki: hi[1] hi[2] ... hi[Ki]
where Ki (>0) is the number of hobbies, and hi[j] is the index of the j-th hobby, which is an integer in [1, 1000].
Output Specification: 
For each case, print in one line the total number of clusters in the network. Then in the second line, print the numbers of people in the clusters in non-increasing order. The numbers must be separated by exactly one space, and there must be no extra space at the end of the line. 
Sample Input:
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
Sample Output:
3
4 3 1
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
int father[1005]; 
int counts[1005];
bool cmp(int a,int b)
{
	return a>b;
}
int GetFather(int a)
{
	if(father[a]==0)
		return 0;
	int x=a;
	while(father[x]!=x)
	{
		x=father[x];
	}
	while(father[a]!=a)
	{
		int u=a;
		a=father[a];
		father[u]=x;
	}
	return x;
}
int main()
{
	memset(father,0,sizeof(father));
	memset(counts,0,sizeof(counts));
	int n,x,y;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d: ",&x);
		vector<int> v1;
		for(int j=0;j<x;j++)
		{
			scanf("%d",&y);
			v1.push_back(y);
		}
		set<int> u;
		int kk=GetFather(v1[0]);
		if(!kk)
		{
			kk=v1[0];
			father[v1[0]]=v1[0];
		}
		counts[kk]++;
		for(int j=1;j<x;j++)
		{
			if((GetFather(v1[j])!=kk)&&GetFather(v1[j]))
			{
				u.insert(GetFather(v1[j]));
			}
			if(!GetFather(v1[j]))
			{
				father[v1[j]]=v1[0];
			}
			else
			{
				father[GetFather(v1[j])]=kk;
			}
		}
		if(!u.empty())
		{
			for(set<int>::iterator it=u.begin();it!=u.end();it++)
			{
				counts[kk]+=counts[*it];
				counts[*it]=0;
			}
		}
	}
	vector<int> v2;
	for(int i=1;i<=1000;i++)
	{
		if(counts[i])
			v2.push_back(counts[i]);
	}
	printf("%d\n",v2.size());
	sort(v2.begin(),v2.end(),cmp);
	printf("%d",v2[0]);
	for(int i=1;i<v2.size();i++)
	{
		printf(" %d",v2[i]);
	} 
	return 0;
 } 
