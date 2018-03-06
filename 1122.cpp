/*1122. Hamiltonian Cycle (25)
The "Hamilton cycle problem" is to find a simple cycle that contains every vertex in a graph. Such a cycle is called a "Hamiltonian cycle". 
In this problem, you are supposed to tell if a given cycle is a Hamiltonian cycle. 
Input Specification: 
Each input file contains one test case. For each case, the first line contains 2 positive integers N (2< N <= 200), the number of vertices, and M, the number of edges in an undirected graph. Then M lines follow, each describes an edge in the format "Vertex1 Vertex2", where the vertices are numbered from 1 to N. The next line gives a positive integer K which is the number of queries, followed by K lines of queries, each in the format:
n V1 V2 ... Vn 
where n is the number of vertices in the list, and Vi's are the vertices on a path. 
Output Specification: 
For each query, print in a line "YES" if the path does form a Hamiltonian cycle, or "NO" if not. 
Sample Input:
6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
6
7 5 1 4 3 6 2 5
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 3 4 5 2 6
7 6 1 2 5 4 3 1
Sample Output:
YES
NO
NO
NO
YES
NO
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool G[205][205];
bool vis[205];
void Judge(int n)
{
	memset(vis,0,sizeof(vis));
	bool f=true;
	int a;
	scanf("%d",&a);
	int b=a;
	int c;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&c);
		vis[c]=true;
		if(!G[b][c])
		{
			f=false;
		}
		b=c;
	}
	if(c!=a||!f)
	{
		printf("NO\n");
		return;
	}
	for(int i=1;i<n;i++)
	{
		if(!vis[i])
		{
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}
int main()
{
//	freopen("C:\\Users\\asus\\Desktop\\a.txt","r",stdin);
	int N,M,x,y;
	memset(G,0,sizeof(0));
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		scanf("%d %d",&x,&y);
		G[x][y]=true;
		G[y][x]=true;
	}
	int k,n;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d",&n);
		if(n!=N+1)
		{
			printf("NO\n");
			for(int j=0;j<n;j++)
			{
				scanf("%d",&x);
	//			printf("%d",x);
			}
		}
		else
			Judge(n);
	}
	return 0;
 } 
