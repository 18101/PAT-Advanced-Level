/*1076. Forwards on Weibo (30)
Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may follow many other users as well. Hence a social network is formed with followers relations. When a user makes a post on Weibo, all his/her followers can view and forward his/her post, which can then be forwarded again by their followers. Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.
Input Specification: 
Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=1000), the number of users; and L (<=6), the number of levels of indirect followers that are counted. Hence it is assumed that all the users are numbered from 1 to N. Then N lines follow, each in the format:
M[i] user_list[i]
where M[i] (<=100) is the total number of people that user[i] follows; and user_list[i] is a list of the M[i] users that are followed by user[i]. It is guaranteed that no one can follow oneself. All the numbers are separated by a space.
Then finally a positive K is given, followed by K UserID's for query. 
Output Specification: 
For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can triger, assuming that everyone who can view the initial post will forward it once, and that only L levels of indirect followers are counted. 
Sample Input:
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
Sample Output:
4
5
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
bool mp[1001][1001];
bool visit[1001];
int n,l,count;
struct node{
	int num;
	int level;
}tempnode;
void BFS(int y)
{
	tempnode.level=0;
	tempnode.num=y;
	visit[y]=true;
	queue<node> q;
	q.push(tempnode);
	while(!q.empty())
	{
		node tnode=q.front();
		q.pop();
		if(tnode.level>l)
			break;
		count++;
		for(int i=1;i<=n;i++)
		{
			if(!visit[i]&&mp[tnode.num][i])
			{
				visit[i]=true;
				tempnode.num=i;
				tempnode.level=tnode.level+1;
				q.push(tempnode);
			}
		}
	}
}
int main()
{
	int x,y;
	memset(mp,0,sizeof(mp));
	scanf("%d %d",&n,&l);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for(int j=0;j<x;j++)
		{
			scanf("%d",&y);
			mp[y][i]=true;
		}
	}
	scanf("%d",&x);
	for(int i=0;i<x;i++)
	{
		scanf("%d",&y);
		memset(visit,0,sizeof(visit));
		count=0;
		BFS(y);
		printf("%d\n",count-1);
	}
	return 0;
 } 
