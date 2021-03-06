/*1003. Emergency (25)
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input
Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2. 
Output
For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.
Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF=0x3fffffff;
int weight[500];
int mp[500][500];
int d[500];
int number[500];
int w[500];
bool visit[500]={false};
int n;
void Dijkstra(int s)
{
	fill(d,d+sizeof(d)/sizeof(int),INF);
	memset(number,0,sizeof(number));
	memset(w,0,sizeof(w));
	number[s]=1;
	d[s]=0;
	w[s]=weight[s];
	for(int i=0;i<n;i++)
	{
		int u=-1,minl=INF;
		for(int j=0;j<n;j++)
		{
			if(!visit[j]&&d[j]<minl)
			{
				minl=d[j];
				u=j;
			}
		}
		if(u==-1)
			return;
		visit[u]=true;
		for(int v=0;v<n;v++)
		{
			if(!visit[v]&&mp[u][v]!=INF)
			{
				if(d[u]+mp[u][v]<d[v])
				{
					d[v]=d[u]+mp[u][v];
					w[v]=w[u]+weight[v];
					number[v]=number[u];
				}
				else if(d[u]+mp[u][v]==d[v])
				{
					if(w[u]+weight[v]>w[v])
					{
						w[v]=w[u]+weight[v];
					}
					number[v]+=number[u];
				}
			}
		}
	}
}
int main()
{
	int m,c1,c2,x,y,z;
	scanf("%d %d %d %d",&n,&m,&c1,&c2);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&weight[i]);
	}
	fill(mp[0],mp[0]+500*500,INF);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		mp[x][y]=z;
		mp[y][x]=z;
	}
	Dijkstra(c1);
	printf("%d %d",number[c2],w[c2]);
	return 0;
}
