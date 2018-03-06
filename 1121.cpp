/*1121. Damn Single (25)
"Damn Single (µ•…Ìπ∑)" is the Chinese nickname for someone who is being single. You are supposed to find those who are alone in a big party, so they can be taken care of.
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<=50000), the total number of couples. Then N lines of the couples follow, each gives a couple of ID's which are 5-digit numbers (i.e. from 00000 to 99999). After the list of couples, there is a positive integer M (<=10000) followed by M ID's of the party guests. The numbers are separated by spaces. It is guaranteed that nobody is having bigamous marriage (÷ÿªÈ) or dangling with more than one companion.
Output Specification: 
First print in a line the total number of lonely guests. Then in the next line, print their ID's in increasing order. The numbers must be separated by exactly 1 space, and there must be no extra space at the end of the line. 
Sample Input:
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
Sample Output:
5
10000 23333 44444 55555 88888
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct{
	bool f;
	int lover;
}p[100005];
int main()
{
//	freopen("C:\\Users\\asus\\Desktop\\a.txt","r",stdin);
	memset(p,0,sizeof(p));
	int n,x,y;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		p[x].lover=y;
		p[y].lover=x;
	}
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&x);
		p[x].f=true;
	}
	vector<int> v;
	for(int i=0;i<100000;i++)
	{
		if(p[i].f)
		{
			if(p[i].lover==-1)
			{
				v.push_back(i);
			}
			else if(!p[p[i].lover].f)
			{
				v.push_back(i);
			}
		}
	}
	printf("%d\n",v.size());
	if(!v.empty())
	{
		printf("%05d",v[0]);
		for(int i=1;i<v.size();i++)
		{
			printf(" %05d",v[i]);
		}
	}
	return 0;
 } 
