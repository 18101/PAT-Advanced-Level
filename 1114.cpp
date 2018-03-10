/*1114. Family Property (25)
This time, you are supposed to help us collect the data for family-owned property. Given each person's family members, and the estate£¨·¿²ú£©info under his/her own name, we need to know the size of each family, and the average area and number of sets of their real estate.
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<=1000). Then N lines follow, each gives the infomation of a person who owns estate in the format:
ID Father Mother k Child1 ... Childk M_estate Area 
where ID is a unique 4-digit identification number for each person; Father and Mother are the ID's of this person's parents (if a parent has passed away, -1 will be given instead); k (0<=k<=5) is the number of children of this person; Childi's are the ID's of his/her children; M_estate is the total number of sets of the real estate under his/her name; and Area is the total area of his/her estate. 
Output Specification: 
For each case, first print in a line the number of families (all the people that are related directly or indirectly are considered in the same family). Then output the family info in the format: 
ID M AVG_sets AVG_area 
where ID is the smallest ID in the family; M is the total number of family members; AVG_sets is the average number of sets of their real estate; and AVG_area is the average area. The average numbers must be accurate up to 3 decimal places. The families must be given in descending order of their average areas, and in ascending order of the ID's if there is a tie. 
Sample Input:
10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100
Sample Output:
3
8888 1 1.000 1000.000
0001 15 0.600 100.000
5551 4 0.750 100.000
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
struct node{
	int minid;
	int members;
	double avgset;
	double avgareas;
};
int numset[100005];
double area[100005];
vector<int> v[100005],vid;
vector<node> families;
bool vis[100005]={false};
int minid,memb,sumset;
double sumareas;
void DFS(int x)
{
	vis[x]=true;
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
		{
			if(v[x][i]<minid)
			{
				minid=v[x][i];
			}
			memb++;
			sumset+=numset[v[x][i]];
			sumareas+=area[v[x][i]];
			DFS(v[x][i]);
		}
	}
}
bool cmp(node a,node b)
{
	if(abs(a.avgareas-b.avgareas)<1e-8)
	{
		return a.minid<b.minid;
	}
	else
		return a.avgareas>b.avgareas;
}
int main()
{
	memset(numset,0,sizeof(numset));
	memset(area,0,sizeof(area));
	int n,id,fid,mid,k,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&id,&fid,&mid);
		vid.push_back(id);
		scanf("%d",&k);
		for(int i=0;i<k;i++)
		{
			scanf("%d",&x);
			v[id].push_back(x);
			v[x].push_back(id);
		}
		scanf("%d %lf",&numset[id],&area[id]);
		if(fid!=-1)
		{
			v[id].push_back(fid);
			v[fid].push_back(id);
		}
		if(mid!=-1)
		{
			v[id].push_back(mid);
			v[mid].push_back(id);
		}
	}
	for(int i=0;i<vid.size();i++)
	{
		if(!vis[vid[i]])
		{
			minid=vid[i];
			memb=1;
			sumset=numset[vid[i]];
			sumareas=area[vid[i]];
			DFS(vid[i]);
			node temp;
			temp.minid=minid;
			temp.members=memb;
			temp.avgset=sumset*1.0/memb;
			temp.avgareas=sumareas/memb;
			families.push_back(temp);
		}
	}
	sort(families.begin(),families.end(),cmp);
	printf("%d\n",families.size());
	for(int i=0;i<families.size();i++)
	{
		printf("%04d %d %.3f %.3f\n",families[i].minid,families[i].members,families[i].avgset,families[i].avgareas);
	}
	return 0;
 } 
