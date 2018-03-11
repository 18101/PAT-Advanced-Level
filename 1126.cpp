/*1126. Eulerian Path (25)
In graph theory, an Eulerian path is a path in a graph which visits every edge exactly once. Similarly, an Eulerian circuit is an Eulerian path which starts and ends on the same vertex. They were first discussed by Leonhard Euler while solving the famous Seven Bridges of Konigsberg problem in 1736. It has been proven that connected graphs with all vertices of even degree have an Eulerian circuit, and such graphs are called Eulerian. If there are exactly two vertices of odd degree, all Eulerian paths start at one of them and end at the other. A graph that has an Eulerian path but not an Eulerian circuit is called semi-Eulerian. (Cited from https://en.wikipedia.org/wiki/Eulerian_path) 
Given an undirected graph, you are supposed to tell if it is Eulerian, semi-Eulerian, or non-Eulerian. 
Input Specification:
Each input file contains one test case. Each case starts with a line containing 2 numbers N (<= 500), and M, which are the total number of vertices, and the number of edges, respectively. Then M lines follow, each describes an edge by giving the two ends of the edge (the vertices are numbered from 1 to N).
Output Specification:
For each test case, first print in a line the degrees of the vertices in ascending order of their indices. Then in the next line print your conclusion about the graph -- either "Eulerian", "Semi-Eulerian", or "Non-Eulerian". Note that all the numbers in the first line must be separated by exactly 1 space, and there must be no extra space at the beginning or the end of the line. 
Sample Input 1:
7 12
5 7
1 2
1 3
2 3
2 4
3 4
5 2
7 6
6 3
4 5
6 4
5 6
Sample Output 1:
2 4 4 4 4 4 2
Eulerian
Sample Input 2:
6 10
1 2
1 3
2 3
2 4
3 4
5 2
6 3
4 5
6 4
5 6
Sample Output 2:
2 4 4 4 3 3
Semi-Eulerian
Sample Input 3:
5 8
1 2
2 5
5 4
4 1
1 3
3 2
3 4
5 3
Sample Output 3:
3 3 4 3 3
Non-Eulerian
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> v1[501];
bool vis[501]={false};
void DFS(int a)
{
	vis[a]=true;
	for(int i=0;i<v1[a].size();i++)
	{
		if(!vis[v1[a][i]])
		{
			DFS(v1[a][i]);
		}
	}
}
int main()
{
	int v,e;
	int x,y;
	scanf("%d %d",&v,&e);
	for(int i=1;i<=e;i++)
	{
		scanf("%d %d",&x,&y);
		v1[x].push_back(y);
		v1[y].push_back(x);
	}
	vector<int> v2;
	DFS(1);
	int cntodd=0;
	bool flag2=false;
	for(int i=1;i<=v;i++)
	{
		v2.push_back(v1[i].size());
		if(v1[i].size()%2)
			cntodd++;
		if(!vis[i])
			flag2=true;
	}
	printf("%d",v2[0]);
	if(v2.size()>1)
	{
		for(int i=1;i<v2.size();i++)
		{
			printf(" %d",v2[i]);
		}
	}
	printf("\n");
	if(flag2)
	{
		printf("Non-Eulerian");
		return 0;
	}
	if(!cntodd)
		printf("Eulerian");
	else if(cntodd==2)
		printf("Semi-Eulerian");
	else
		printf("Non-Eulerian");
	return 0;
 } 
