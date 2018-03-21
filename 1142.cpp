/*C Maximal Clique£¨25 ·Ö£©
A clique is a subset of vertices of an undirected graph such that every two distinct vertices in the clique are adjacent. A maximal clique is a clique that cannot be extended by including one more adjacent vertex. (Quoted from https://en.wikipedia.org/wiki/Clique_(graph_theory))
Now it is your job to judge if a given subset of vertices can form a maximal clique.
Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers Nv (¡Ü 200), the number of vertices in the graph, and Ne, the number of undirected edges. Then Ne lines follow, each gives a pair of vertices of an edge. The vertices are numbered from 1 to Nv.
After the graph, there is another positive integer M (¡Ü 100). Then M lines of query follow, each first gives a positive number K (¡Ü Nv), then followed by a sequence of K distinct vertices. All the numbers in a line are separated by a space.
Output Specification:
For each of the M queries, print in a line Yes if the given subset of vertices can form a maximal clique; or if it is a clique but not a maximal clique, print Not Maximal; or if it is not a clique at all, print Not a Clique.
Sample Input:
8 10
5 6
7 8
6 4
3 6
4 5
2 3
8 2
2 7
5 3
3 4
6
4 5 4 3 6
3 2 8 7
2 2 3
1 1
3 4 3 6
3 3 2 1
Sample Output:
Yes
Yes
Yes
Yes
Not Maximal
Not a Clique
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
bool G[205][205];
bool vis[205];
int main()
{
	int nv,ne,x,y;
	memset(G,0,sizeof(G));
	scanf("%d %d",&nv,&ne);
	for(int i=0;i<ne;i++)
	{
		scanf("%d %d",&x,&y);
		G[x][y]=true;
		G[y][x]=true;
	}
	int m,k,u;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		vector<int> vv;
		memset(vis,0,sizeof(vis));
		scanf("%d",&k);
		for(int ii=0;ii<k;ii++)
		{
			scanf("%d",&u);
			vis[u]=true;
			vv.push_back(u);
		}
		bool flag1=true;
		for(int j=0;j<vv.size();j++)
		{
			for(int p=j+1;p<vv.size();p++)
			{
				if(!G[vv[j]][vv[p]])
				{
					flag1=false;
					break;
				}
			}
			if(!flag1)
			{
				break;
			}
		}
		if(!flag1)
		{
			printf("Not a Clique\n");
			continue;
		}
		else
		{
			bool flag2=true;
			for(int j=1;j<=nv;j++)
			{
				if(!vis[j])
				{
					bool flag3=true;
					for(int p=0;p<vv.size();p++)
					{
						if(!G[vv[p]][j])
						{
							flag3=false;
							break;
						}
					}
					if(flag3==true)
					{
						flag2=false;
						break;
					}
				}
			}
			if(!flag2)
			{
				printf("Not Maximal\n");
			}
			else
			{
				printf("Yes\n");
			}
		}
	}
	return 0;
}
