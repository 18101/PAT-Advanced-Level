/*1118. Birds in Forest (25)
Some scientists took pictures of thousands of birds in a forest. Assume that all the birds appear in the same picture belong to the same tree. You are supposed to help the scientists to count the maximum number of trees in the forest, and for any pair of birds, tell if they are on the same tree. 
Input Specification: 
Each input file contains one test case. For each case, the first line contains a positive number N (<= 104) which is the number of pictures. Then N lines follow, each describes a picture in the format:
K B1 B2 ... BK
where K is the number of birds in this picture, and Bi's are the indices of birds. It is guaranteed that the birds in all the pictures are numbered continuously from 1 to some number that is no more than 104.
After the pictures there is a positive number Q (<= 104) which is the number of queries. Then Q lines follow, each contains the indices of two birds. 
Output Specification: 
For each test case, first output in a line the maximum possible number of trees and the number of birds. Then for each query, print in a line "Yes" if the two birds belong to the same tree, or "No" if not.
Sample Input:
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7
Sample Output:
2 10
Yes
No
*/
#include <iostream>
#include <cstdio>
using namespace std;
int father[10005];
bool cc[10005]={false};
int GetFather(int x)
{
	int a=x;
	while(father[a]!=a)
	{
		a=father[a];
	}
	while(father[x]!=x)
	{
		father[x]=a;
		x=father[x];
	}
	return a;
}
void Union(int a,int b)
{
	int fa=GetFather(a);
	int fb=GetFather(b);
	if(fa!=fb)
	{
		father[fb]=fa;
	}
}
int main()
{
//	freopen("C:\\Users\\asus\\Desktop\\a.txt","r",stdin);
	for(int i=1;i<10001;i++)
	{
		father[i]=i;
	}
	int n,x,u,v;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		scanf("%d",&u);
		cc[u]=true;
		for(int i=1;i<x;i++)
		{
			scanf("%d",&v);
			cc[v]=true;
			Union(u,v);
		}
	}
	int co=0,cnt=0;
	for(int i=1;i<10001;i++)
	{
		if(cc[i])
		{
			cnt++;
			GetFather(i);
			if(father[i]==i)
			{
				co++;
			}
		}
	}
	printf("%d %d\n",co,cnt);
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);
		if(father[u]==father[v])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
