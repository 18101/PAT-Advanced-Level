/*1139. First Contact (30)
Unlike in nowadays, the way that boys and girls expressing their feelings of love was quite subtle in the early years. When a boy A had a crush on a girl B, he would usually not contact her directly in the first place. Instead, he might ask another boy C, one of his close friends, to ask another girl D, who was a friend of both B and C, to send a message to B -- quite a long shot, isn't it? Girls would do analogously. 
Here given a network of friendship relations, you are supposed to help a boy or a girl to list all their friends who can possibly help them making the first contact. 
Input Specification: 
Each input file contains one test case. For each case, the first line gives two positive integers N (1 < N <= 300) and M, being the total number of people and the number of friendship relations, respectively. Then M lines follow, each gives a pair of friends. Here a person is represented by a 4-digit ID. To tell their genders, we use a negative sign to represent girls. 
After the relations, a positive integer K (<= 100) is given, which is the number of queries. Then K lines of queries follow, each gives a pair of lovers, separated by a space. It is assumed that the first one is having a crush on the second one. 
Output Specification: 
For each query, first print in a line the number of different pairs of friends they can find to help them, then in each line print the IDs of a pair of friends. 
If the lovers A and B are of opposite genders, you must first print the friend of A who is of the same gender of A, then the friend of B, who is of the same gender of B. If they are of the same gender, then both friends must be in the same gender as theirs. It is guaranteed that each person has only one gender. 
The friends must be printed in non-decreasing order of the first IDs, and for the same first ones, in increasing order of the seconds ones. 
Sample Input:
10 18
-2001 1001
-2002 -2001
1004 1001
-2004 -2001
-2003 1005
1005 -2001
1001 -2003
1002 1001
1002 -2004
-2004 1001
1003 -2002
-2003 1003
1004 -2002
-2001 -2003
1001 1003
1003 -2001
1002 -2001
-2002 -2003
5
1001 -2001
-2003 1001
1005 -2001
-2002 -2004
1111 -2003
Sample Output:
4
1002 2004
1003 2002
1003 2003
1004 2002
4
2001 1002
2001 1003
2002 1003
2002 1004
0
1
2003 2001
0
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
	int a;
	int b;
};
vector<int> vbb[20000],vgg[20000],vbg[20000];
bool cmp(node z,node x)
{
	if(z.a==x.a)
		return z.b<x.b;
	return z.a<x.a;
}
int main()
{
	int n,m,x,y;
	scanf("%d %d",&n,&m);
	char xx[6],yy[6];
	char zero2[6]="-0000";
	for(int i=0;i<m;i++)
	{
		scanf("%s %s",xx,yy);
		if(!strcmp(xx,zero2))
		{
			x=10000;		
		}
		else
			x=atoi(xx);
		if(!strcmp(yy,zero2))
		{
			y=10000;
		}
		else
			y=atoi(yy);
		if(x<0)
			x=-x+10000;
		if(y<0)
			y=-y+10000;
		if(x<10000&&y>=10000||x>=10000&&y<10000)
		{
			vbg[x].push_back(y);
			vbg[y].push_back(x);
		}
		else if(x<10000&&y<10000)
		{
			vbb[x].push_back(y);
			vbb[y].push_back(x);
		}
		else
		{
			vgg[x].push_back(y);
			vgg[y].push_back(x);
		}
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d %d",&x,&y);
		if(x<0)
			x=-x+10000;
		if(y<0)
			y=-y+10000;
		vector<node> vv;
		node temp;
		if(x<10000&&y>=10000)
		{
			for(int j=0;j<vbb[x].size();j++)
			{
				int tb=vbb[x][j];
				for(int q=0;q<vbg[tb].size();q++)
				{
					int tg=vbg[tb][q];
					for(int w=0;w<vgg[tg].size();w++)
					{
						if(vgg[tg][w]==y)
						{
							temp.a=tb;
							temp.b=tg;
							vv.push_back(temp);
						}
					}
				}
			}
			printf("%d\n",vv.size());
			if(!vv.empty())
			{
				sort(vv.begin(),vv.end(),cmp);
			//	printf("hh%dhh\n",vv.size());
				for(int i=0;i<vv.size();i++)
				{
					printf("%04d %04d\n",vv[i].a,vv[i].b-10000);
				}	
			}
		}
		else if(x>=10000&&y<10000)
		{
			for(int j=0;j<vgg[x].size();j++)
			{
				int tg=vgg[x][j];
				for(int q=0;q<vbg[tg].size();q++)
				{
					int tb=vbg[tg][q];
					for(int w=0;w<vbb[tb].size();w++)
					{
						if(vbb[tb][w]==y)
						{
							temp.a=tg;
							temp.b=tb;
							vv.push_back(temp);
						}
					}
				}
			}
			printf("%d\n",vv.size());
			if(!vv.empty())
			{
				sort(vv.begin(),vv.end(),cmp);
				for(int i=0;i<vv.size();i++)
				{
					printf("%04d %04d\n",vv[i].a-10000,vv[i].b);
				}	
			}	
		}
		else if(x<10000&&y<10000)
		{
			for(int j=0;j<vbb[x].size();j++)
			{
				if(vbb[x][j]==y)
					continue;
				int tg=vbb[x][j];
				for(int q=0;q<vbb[tg].size();q++)
				{
					if(vbb[tg][q]==x)
						continue;
					int tb=vbb[tg][q];
					for(int w=0;w<vbb[tb].size();w++)
					{
						if(vbb[tb][w]==y)
						{
							temp.a=tg;
							temp.b=tb;
							vv.push_back(temp);
						}
					}
				}
			}
			printf("%d\n",vv.size());
			if(!vv.empty())
			{
				sort(vv.begin(),vv.end(),cmp);
				for(int i=0;i<vv.size();i++)
				{
					printf("%04d %04d\n",vv[i].a,vv[i].b);
				}	
			}	
		}
		else if(x>=10000&&y>=10000)
		{
			for(int j=0;j<vgg[x].size();j++)
			{
				if(vgg[x][j]==y)
					continue;
				int tg=vgg[x][j];
				for(int q=0;q<vgg[tg].size();q++)
				{
					if(vgg[tg][q]==x)
						continue;
					int tb=vgg[tg][q];
					for(int w=0;w<vgg[tb].size();w++)
					{
						if(vgg[tb][w]==y)
						{
							temp.a=tg;
							temp.b=tb;
							vv.push_back(temp);
						}
					}
				}
			}
			printf("%d\n",vv.size());
			if(!vv.empty())
			{
				sort(vv.begin(),vv.end(),cmp);
				for(int i=0;i<vv.size();i++)
				{
					printf("%04d %04d\n",vv[i].a-10000,vv[i].b-10000);
				}	
			}	
		}
	}
	return 0;
}
