/*1030. Travel Plan (30)
A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique. 
Input Specification: 
Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:
City1 City2 Distance Cost 
where the numbers are all integers no more than 500, and are separated by a space. 
Output Specification: 
For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output. 
Sample Input
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output
0 2 3 3 40
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int INF=0x3fffffff;
struct node{
	int cost;
	int dis;
};
int n,m,s,di;
node G[500][500];
int vis[500]={false};
int cost[500],d[500],pre[500];
void Dijxstra(int a)//
{
	for(int i=0;i<n;i++)
		pre[i]=i;
	fill(d,d+500,INF);
	memset(cost,0,sizeof(cost));
	d[a]=0;
	for(int i=0;i<n;i++)
	{
		int u=-1,minl=INF;
		for(int j=0;j<n;j++)
		{
			if(!vis[j]&&d[j]<minl)
			{
				minl=d[j];
				u=j;
			}
		}
		if(u==-1)
			return;
		vis[u]=true;
		for(int v=0;v<n;v++)
		{
			if(!vis[v]&&G[u][v].dis!=INF)
			{
				if(G[u][v].dis+d[u]<d[v])
				{
					pre[v]=u;
					d[v]=G[u][v].dis+d[u];
					cost[v]=cost[u]+G[u][v].cost;
				}
				else if(G[u][v].dis+d[u]==d[v])
				{
					if(cost[u]+G[u][v].cost<cost[v])
					{
						pre[v]=u;
						cost[v]=cost[u]+G[u][v].cost;
					}
				}
			}
		}
	}
}
int main()
{
	int x,y;
	scanf("%d %d %d %d",&n,&m,&s,&di);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			G[i][j].dis=INF;
		}
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		scanf("%d %d",&G[x][y].dis,&G[x][y].cost);
		G[y][x].dis=G[x][y].dis;
		G[y][x].cost=G[x][y].cost;
	}
	Dijxstra(s);
	int e=di;
	vector<int> v;
	while(e!=s)
	{
		v.push_back(e);
		e=pre[e];
	}
	printf("%d",s);
	for(int i=v.size()-1;i>=0;i--)
	{
		printf(" %d",v[i]);
	}
	printf(" %d %d",d[di],cost[di]);
	return 0;
 } 
