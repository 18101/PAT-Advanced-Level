/*1131. Subway Map (30)
In the big cities, the subway systems always look so complex to the visitors. To give you some sense, the following figure shows the map of Beijing subway. Now you are supposed to help people with your computer skills! Given the starting position of your user, your task is to find the quickest way to his/her destination.

Input Specification: 
Each input file contains one test case. For each case, the first line contains a positive integer N (< =100), the number of subway lines. Then N lines follow, with the i-th (i = 1, ..., N) line describes the i-th subway line in the format:
M S[1] S[2] ... S[M] 
where M (<= 100) is the number of stops, and S[i]'s (i = 1, ... M) are the indices of the stations (the indices are 4-digit numbers from 0000 to 9999) along the line. It is guaranteed that the stations are given in the correct order -- that is, the train travels between S[i] and S[i+1] (i = 1, ..., M-1) without any stop.
Note: It is possible to have loops, but not self-loop (no train starts from S and stops at S without passing through another station). Each station interval belongs to a unique subway line. Although the lines may cross each other at some stations (so called "transfer stations"), no station can be the conjunction of more than 5 lines. 
After the description of the subway, another positive integer K (<= 10) is given. Then K lines follow, each gives a query from your user: the two indices as the starting station and the destination, respectively. 
The following figure shows the sample map. 

Note: It is guaranteed that all the stations are reachable, and all the queries consist of legal station numbers. 
Output Specification: 
For each query, first print in a line the minimum number of stops. Then you are supposed to show the optimal path in a friendly format as the following: 
Take Line#X1 from S1 to S2.
Take Line#X2 from S2 to S3.
......
where Xi's are the line numbers and Si's are the station indices. Note: Besides the starting and ending stations, only the transfer stations shall be printed. 
If the quickest path is not unique, output the one with the minimum number of transfers, which is guaranteed to be unique. 
Sample Input:
4
7 1001 3212 1003 1204 1005 1306 7797
9 9988 2333 1204 2006 2005 2004 2003 2302 2001
13 3011 3812 3013 3001 1306 3003 2333 3066 3212 3008 2302 3010 3011
4 6666 8432 4011 1306
3
3011 3013
6666 2001
2004 3001
Sample Output:
2
Take Line#3 from 3011 to 3013.
10
Take Line#4 from 6666 to 1306.
Take Line#3 from 1306 to 2302.
Take Line#2 from 2302 to 2001.
6
Take Line#2 from 2004 to 1204.
Take Line#1 from 1204 to 1306.
Take Line#3 from 1306 to 3001.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
struct node{
	int sta;
	int l;
};
vector<node> v[10000];
bool vis[10000]={false};
int minstops,minturns;
vector<int> road;
vector<int> final;
vector<int> ss;
vector<int> finalsta;
int GetTurn(vector<int> vv)
{
	if(vv.size()==1)
		return 0;
	int a=vv[0],count=0;
	for(int i=1;i<vv.size();i++)
	{
		if(vv[i]!=vv[i-1])
			count++;
	}
	return count;
}
void DFS(int x,int y,int stop)
{
	if(x==y)
	{
		if(stop<minstops)
		{
			final=road;
			finalsta=ss;
			minturns=GetTurn(road);
			minstops=stop;
			return;
		}
		else if(stop==minstops)
		{
			int aturns=GetTurn(road);
			if(aturns<minturns)
			{
				minturns=aturns;
				finalsta=ss;
				final=road;
			}
			return; 
		}
	}
	if(stop==minstops)
	{
		return;
	}
	else
	{
		for(int i=0;i<v[x].size();i++)
		{
			if(vis[v[x][i].sta])
				continue;
			vis[v[x][i].sta]=true;
			road.push_back(v[x][i].l);
			ss.push_back(v[x][i].sta);
			DFS(v[x][i].sta,y,stop+1);
			road.pop_back();
			ss.pop_back();
			vis[v[x][i].sta]=false;
		}
	}
}
int main()
{
	int n,m,x,y;
	node temp1,temp2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		temp1.l=i;
		temp2.l=i;
		scanf("%d",&m);
		scanf("%d",&temp1.sta);
		for(int j=1;j<m;j++)
		{
			scanf("%d",&temp2.sta);
			v[temp1.sta].push_back(temp2);
			v[temp2.sta].push_back(temp1);
			temp1=temp2;
		}
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		memset(vis,0,sizeof(vis));
		minstops=10005;
		minturns=10005;
		scanf("%d %d",&x,&y);
		road.clear();
		final.clear();
		ss.clear();
		ss.push_back(x);
		vis[x]=true;
		finalsta.clear();
		if(x==y)
		{
			printf("0\n");
			continue;
		}
		DFS(x,y,0);
		printf("%d\n",final.size());
		int aa=0;
		int kk;
		while(true)
		{
			printf("Take Line#%d from %04d ",final[aa],finalsta[aa]);
			while(aa+1<final.size()&&final[aa+1]==final[aa])
			{
				aa++;
			}
			aa++;
			printf("to %04d.\n",finalsta[aa]);
			if(aa==finalsta.size()-1)
			{
				break;
			}
		}
	}
	return 0;
 } 
