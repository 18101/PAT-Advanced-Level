/*1111. Online Map (30)
Input our current position and a destination, an online map can recommend several paths. Now your job is to recommend two paths to your user: one is the shortest, and the other is the fastest. It is guaranteed that a path exists for any request. 
Input Specification: 
Each input file contains one test case. For each case, the first line gives two positive integers N (2 <= N <= 500), and M, being the total number of streets intersections on a map, and the number of streets, respectively. Then M lines follow, each describes a street in the format:
V1 V2 one-way length time 
where V1 and V2 are the indices (from 0 to N-1) of the two ends of the street; one-way is 1 if the street is one-way from V1 to V2, or 0 if not; length is the length of the street; and time is the time taken to pass the street. 
Finally a pair of source and destination is given.
Output Specification: 
For each case, first print the shortest path from the source to the destination with distance D in the format: 
Distance = D: source -> v1 -> ... -> destination 
Then in the next line print the fastest path with total time T: 
Time = T: source -> w1 -> ... -> destination 
In case the shortest path is not unique, output the fastest one among the shortest paths, which is guaranteed to be unique. In case the fastest path is not unique, output the one that passes through the fewest intersections, which is guaranteed to be unique. 
In case the shortest and the fastest paths are identical, print them in one line in the format: 
Distance = D; Time = T: source -> u1 -> ... -> destination 
Sample Input 1:
10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
3 4 0 3 2
3 9 1 4 1
0 6 0 1 1
7 5 1 2 1
8 5 1 2 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
1 4 0 1 1
9 7 1 3 1
5 1 0 5 2
6 5 1 1 2
3 5
Sample Output 1:
Distance = 6: 3 -> 4 -> 8 -> 5
Time = 3: 3 -> 1 -> 5
Sample Input 2:
7 9
0 4 1 1 1
1 6 1 1 3
2 6 1 1 1
2 5 1 2 2
3 0 0 1 1
3 1 1 1 3
3 2 1 1 2
4 5 0 2 2
6 5 1 1 2
3 5
Sample Output 2:
Distance = 3; Time = 4: 3 -> 2 -> 5
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <vector>
using namespace std;
const int INF=0x3fffffff;
int G[505][505];
int G2[505][505];
int ti[505],dis[505],num[505];
int pre[505];
bool vis[505]={false};
int n;
void Get(int sourse)
{
	memset(vis,0,sizeof(vis));
	fill(ti,ti+505,INF);
	fill(dis,dis+505,INF);
	fill(num,num+505,INF);
	ti[sourse]=0;
	dis[sourse]=0;
	num[sourse]=0;
	for(int i=0;i<n;i++)
	{
		pre[i]=i;
	}
	for(int i=0;i<n;i++)
	{
		int mind=INF,u=-1;
		for(int j=0;j<n;j++)
		{
			if(!vis[j]&&dis[j]!=INF)
			{
				if(dis[j]<mind)
				{
					mind=dis[j];
					u=j;
				}
			}
		}
		if(u==-1)
			return;
		vis[u]=true;
		for(int v=0;v<n;v++)
		{
			if(!vis[v]&&G[u][v]!=INF)
			{
				if(dis[u]+G[u][v]<dis[v])
				{
					dis[v]=dis[u]+G[u][v];
					ti[v]=ti[u]+G2[u][v];
					pre[v]=u;
				}
				else if(dis[u]+G[u][v]==dis[v])
				{ 
					if(ti[u]+G2[u][v]<ti[v])
					{
						ti[v]=ti[u]+G2[u][v];
						pre[v]=u;
					}
				}
			}
		}
	}
}
void Get2(int sourse)
{
	fill(dis,dis+505,INF);
	fill(ti,ti+505,INF);
	fill(num,num+505,INF);
	memset(vis,0,sizeof(vis));
	dis[sourse]=0;
	ti[sourse]=0;
	num[sourse]=0;
	for(int i=0;i<n;i++)
	{
		pre[i]=i;
	}
	for(int i=0;i<n;i++)
	{
		int mint=INF,u=-1;
		for(int j=0;j<n;j++)
		{
			if(!vis[j]&&ti[j]<mint)
			{
				mint=ti[j];
				u=j;
			}
		}
		if(u==-1)
			return;
		vis[u]=true;
		for(int v=0;v<n;v++)
		{
			if(!vis[v]&&G2[u][v]!=INF)
			{
				if(ti[u]+G2[u][v]<ti[v])
				{
					ti[v]=ti[u]+G2[u][v];
					num[v]=num[u]+1;
					pre[v]=u;
				}
				else if(ti[u]+G2[u][v]==ti[v])
				{
					if(num[u]+1<num[v])
					{
						num[v]=num[u]+1;
						pre[v]=u;
					}
				}
			}
		}
	}
}
int main()
{
	fill(G[0],G[0]+505*505,INF);
	fill(G2[0],G2[0]+505*505,INF);
	int m,a,b,c,d,e;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
		G[a][b]=d;
		G2[a][b]=e;
		if(c!=1)
		{
			G[b][a]=d;
			G2[b][a]=e;
		}
	}
	int sourse,destination;
	scanf("%d %d",&sourse,&destination);
	vector<int> v;
	vector<int> v2;
	Get(sourse);
	int thedis=dis[destination];
	int des=destination,des2=destination;
	while(pre[des]!=des)
	{
		v.push_back(des);
		des=pre[des];
	}
	Get2(sourse);
	while(pre[des2]!=des2)
	{
		v2.push_back(des2);
		des2=pre[des2];
	}
	if(v==v2)
	{
		printf("Distance = %d; Time = %d: %d",thedis,ti[destination],sourse);
		for(int i=v.size()-1;i>=0;i--)
		{
			printf(" -> %d",v[i]);
		}
	}
	else
	{
		printf("Distance = %d: %d",thedis,sourse);
		for(int i=v.size()-1;i>=0;i--)
		{
			printf(" -> %d",v[i]);
		}
		printf("\n");
		printf("Time = %d: %d",ti[destination],sourse);
		for(int i=v2.size()-1;i>=0;i--)
		{
			printf(" -> %d",v2[i]);
		}
	}
	return 0;
 } 
