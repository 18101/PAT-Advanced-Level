/*1087. All Roads Lead to Rome (30)
Indeed there are many different tourist routes from our city to Rome. You are supposed to find your clients the route with the least cost while gaining the most happiness.
Input Specification: 
Each input file contains one test case. For each case, the first line contains 2 positive integers N (2<=N<=200), the number of cities, and K, the total number of routes between pairs of cities; followed by the name of the starting city. The next N-1 lines each gives the name of a city and an integer that represents the happiness one can gain from that city, except the starting city. Then K lines follow, each describes a route between two cities in the format "City1 City2 Cost". Here the name of a city is a string of 3 capital English letters, and the destination is always ROM which represents Rome. 
Output Specification: 
For each test case, we are supposed to find the route with the least cost. If such a route is not unique, the one with the maximum happiness will be recommended. If such a route is still not unique, then we output the one with the maximum average happiness -- it is guaranteed by the judge that such a solution exists and is unique.
Hence in the first line of output, you must print 4 numbers: the number of different routes with the least cost, the cost, the happiness, and the average happiness (take the integer part only) of the recommended route. Then in the next line, you are supposed to print the route in the format "City1->City2->...->ROM". 
Sample Input:
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
Sample Output:
3 3 195 97
HZH->PRS->ROM
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int INF=0x3fffffff;
int n,k;
int G[210][210];
int happy[210];
bool vis[210]={false};
int pre[210],d[210],ha[210],num[210],count[210];
map<string,int> mpsi;
map<int,string> mpis;
void Dijkstra(int s)
{
	memset(pre,0,sizeof(pre));
	memset(ha,0,sizeof(ha));
	memset(num,0,sizeof(num));
	memset(count,0,sizeof(count));
	fill(d,d+210,INF);
	num[s]=1;
	d[s]=0;
	for(int i=0;i<n;i++)
	{
		int u=-1,minc=INF;
		for(int j=0;j<n;j++)
		{
			if(!vis[j]&&d[j]<minc)
			{
				minc=d[j];
				u=j;
			}
		}
		if(u==-1)
			return;
		vis[u]=true;
		for(int v=0;v<n;v++)
		{
			if(!vis[v]&&G[u][v]!=INF)
			{
				if(d[u]+G[u][v]<d[v])
				{
					d[v]=d[u]+G[u][v];
					pre[v]=u;
					ha[v]=ha[u]+happy[v];
					num[v]=num[u];
					count[v]=count[u]+1;
				}
				else if(d[u]+G[u][v]==d[v])
				{
					if(ha[u]+happy[v]>ha[v])
					{
						pre[v]=u;
						ha[v]=ha[u]+happy[v];
						count[v]=count[u]+1;
					}
					else if((ha[u]+happy[v])==ha[v])
					{
						if(count[u]+1<count[v])
						{
							pre[v]=u;
							count[v]=count[u]+1;
						}
					}
					num[v]+=num[u];
				}
			}
		}
	}
}
int main()
{
	int x;
	char c[5],start[5],c2[5];
	scanf("%d %d",&n,&k);
	scanf("%s",start);
	mpsi[start]=0;
	mpis[0]=start;
	for(int i=1;i<n;i++)
	{
		scanf("%s %d",c,&happy[i]);
		mpsi[c]=i;
		mpis[i]=c;
	}
	fill(G[0],G[0]+210*210,INF);
	for(int i=0;i<k;i++)
	{
		scanf("%s %s",c,c2);
		scanf("%d",&x);
		G[mpsi[c]][mpsi[c2]]=x;
		G[mpsi[c2]][mpsi[c]]=x;
	}
	Dijkstra(0);
	x=mpsi["ROM"];
	printf("%d %d %d %d\n",num[x],d[x],ha[x],ha[x]/count[x]);
	vector<int> v;
	int e=x;
	while(e!=0)
	{
		v.push_back(e);
		e=pre[e];
	}
	printf("%s",mpis[0].c_str());
	for(int i=v.size()-1;i>=0;i--)
	{
		printf("->%s",mpis[v[i]].c_str());
	}
	return 0;
 } 
