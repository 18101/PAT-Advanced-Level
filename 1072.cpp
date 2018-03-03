/*1072. Gas Station (30)
A gas station has to be built at such a location that the minimum distance between the station and any of the residential housing is as far away as possible. However it must guarantee that all the houses are in its service range.
Now given the map of the city and several candidate locations for the gas station, you are supposed to give the best recommendation. If there are more than one solution, output the one with the smallest average distance to all the houses. If such a solution is still not unique, output the one with the smallest index number.
Input Specification: 
Each input file contains one test case. For each case, the first line contains 4 positive integers: N (<= 103), the total number of houses; M (<= 10), the total number of the candidate locations for the gas stations; K (<= 104), the number of roads connecting the houses and the gas stations; and DS, the maximum service range of the gas station. It is hence assumed that all the houses are numbered from 1 to N, and all the candidate locations are numbered from G1 to GM.
Then K lines follow, each describes a road in the format
P1 P2 Dist
where P1 and P2 are the two ends of a road which can be either house numbers or gas station numbers, and Dist is the integer length of the road.
Output Specification: 
For each test case, print in the first line the index number of the best location. In the next line, print the minimum and the average distances between the solution and all the houses. The numbers in a line must be separated by a space and be accurate up to 1 decimal place. If the solution does not exist, simply output ¡°No Solution¡±. 
Sample Input 1:
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2
Sample Output 1:
G1
2.0 3.3
Sample Input 2:
2 1 2 10
1 G1 9
2 G1 20
Sample Output 2:
No Solution
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF=0x3fffffff;
int n,m,k,ds;
int G[1015][1015];
int d[1015];
bool vis[1015];
int mind=INF,minsum=INF,minmin=-1;
int station=-1;
int sum;
int GetI(char a[])
{
	int b=0;
	for(int i=0;a[i]!='\0';i++)
	{
		b=a[i]-'0'+10*b;
	}
	return b;
}
int GetInt(char a[])
{
	if(a[0]=='G')
		return GetI(a+1)+n;
	else
		return GetI(a);
}
void Dijkstra(int s)
{
	fill(d,d+1015,INF);
	memset(vis,0,sizeof(vis));
	d[s]=0;
	for(int i=1;i<=n+m;i++)
	{
		int u=-1,minl=INF;
		for(int j=1;j<=n+m;j++)
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
		for(int v=1;v<=n+m;v++)
		{
			if(!vis[v]&&G[u][v]!=INF&&G[u][v]+d[u]<d[v])
			{
				d[v]=G[u][v]+d[u];
			}
		}
	}
	sum=0,mind=INF;
	bool flag=true;
	for(int j=1;j<=n;j++)
	{
		if(d[j]>ds)
		{
			flag=false;
			break;
		}
		if(d[j]<mind)
		{
			mind=d[j];
		}
		sum+=d[j];
	}
	if(flag)
	{
		if(mind>minmin)
		{
			station=s;
			minmin=mind;
			minsum=sum;
		}	
		else if(mind==minmin&&minsum>sum)
		{
			station=s;
			minsum=sum;		
		}		
	}
}
int main()
{
	scanf("%d %d %d %d",&n,&m,&k,&ds);
	char a1[5],b1[5];
	int a,b;
	fill(G[0],G[0]+1015*1015,INF);
	for(int i=0;i<k;i++)
	{
		scanf("%s %s",a1,b1);
		a=GetInt(a1);
		b=GetInt(b1);
		scanf("%d",&G[a][b]);
		G[b][a]=G[a][b];
	}
	for(int i=n+1;i<=n+m;i++)
	{
		Dijkstra(i);
	}
	if(station==-1)
	{
		printf("No Solution");
	}
	else
	{
		printf("G%d\n",station-n);
		printf("%.1f %.1f",round(minmin*1.0),minsum*1.0/n);
	}
	return 0;
 } 
