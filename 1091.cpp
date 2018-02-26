/*1091. Acute Stroke (30)
One important factor to identify acute stroke (¼±ÐÔÄÔ×äÖÐ) is the volume of the stroke core. Given the results of image analysis in which the core regions are identified in each MRI slice, your job is to calculate the volume of the stroke core.
Input Specification: 
Each input file contains one test case. For each case, the first line contains 4 positive integers: M, N, L and T, where M and N are the sizes of each slice (i.e. pixels of a slice are in an M by N matrix, and the maximum resolution is 1286 by 128); L (<=60) is the number of slices of a brain; and T is the integer threshold (i.e. if the volume of a connected core is less than T, then that core must not be counted).
Then L slices are given. Each slice is represented by an M by N matrix of 0's and 1's, where 1 represents a pixel of stroke, and 0 means normal. Since the thickness of a slice is a constant, we only have to count the number of 1's to obtain the volume. However, there might be several separated core regions in a brain, and only those with their volumes no less than T are counted. Two pixels are "connected" and hence belong to the same region if they share a common side, as shown by Figure 1 where all the 6 red pixels are connected to the blue one. 

Figure 1
Output Specification: 
For each case, output in a line the total volume of the stroke core. 
Sample Input:
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0
Sample Output:
26
*/
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int data[1290][130][65];
int X[6]={1,-1,0,0,0,0};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={0,0,0,0,1,-1};
int tv=0;
int m,n,l,t;
struct node{
	int x,y,z;
};
bool Judge(int j,int k,int i)
{
	if(j<0||j>=m||k<0||k>=n||i<0||i>=l)
		return false;
	if(!data[j][k][i])
		return false;
	return true;
}
int BFS(int x,int y,int z)
{
	int tempv=0;
	node nnode;
	nnode.x=x;
	nnode.y=y;
	nnode.z=z;
	queue<node> q;
	data[x][y][z]=0;
	q.push(nnode);
	while(!q.empty())
	{
		node p=q.front();
		q.pop();
		tempv++;
		for(int ii=0;ii<6;ii++)
		{
			nnode.x=p.x+X[ii];
			nnode.y=p.y+Y[ii];
			nnode.z=p.z+Z[ii];
			if(Judge(nnode.x,nnode.y,nnode.z))
			{
				data[nnode.x][nnode.y][nnode.z]=0;
				q.push(nnode);
			}
		}
	}
	if(tempv>=t)
		return tempv;
	return 0;
}
int main()
{
	scanf("%d %d %d %d",&m,&n,&l,&t);
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<n;k++)
			{
				scanf("%d",&data[j][k][i]);
			}
		}
	}
	int vv;
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(Judge(j,k,i))
					tv+=BFS(j,k,i);
			}
		}
	}
	printf("%d",tv);
	return 0;
 }
