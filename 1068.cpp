/*1068. Find More Coins (30)
Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she must pay the exact amount. Since she has as many as 104 coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find some coins to pay for it.
Input Specification: 
Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (<=104, the total number of coins) and M(<=102, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers. All the numbers in a line are separated by a space.
Output Specification: 
For each test case, print in one line the face values V1 <= V2 <= ... <= Vk such that V1 + V2 + ... + Vk = M. All the numbers must be separated by a space, and there must be no extra space at the end of the line. If such a solution is not unique, output the smallest sequence. If there is no solution, output "No Solution" instead.
Note: sequence {A[1], A[2], ...} is said to be "smaller" than sequence {B[1], B[2], ...} if there exists k >= 1 such that A[i]=B[i] for all i < k, and A[k] < B[k].
Sample Input 1:
8 9
5 9 8 7 2 3 4 1
Sample Output 1:
1 3 5
Sample Input 2:
4 8
7 2 4 3
Sample Output 2:
No Solution
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,m,num;
	int c[10005];
	int d[10005];
	bool collect[10005][105];
	bool flag[10005]={false};
	memset(d,0,sizeof(d));
	memset(c,0,sizeof(c));
	memset(collect,0,sizeof(collect));
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=c[i];j--)
		{
			if(d[j]<=d[j-c[i]]+c[i])
			{
				collect[i][j]=true;
				d[j]=d[j-c[i]]+c[i];
			}
			else
			{
				collect[i][j]=false;
			}
		}
	}
	if(d[m]!=m)
	{
		printf("No Solution");
	}
	else
	{
		int k=n,cap=m;
		num=0;
		while(k>=0)
		{
			if(collect[k][cap])
			{
				flag[k]=true;
				cap-=c[k];
				num++;
			}
			k--;
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(flag[i])
		{
			printf("%d",c[i]);
			num--;
			if(num)
				printf(" ");
		}
	}
	return 0;
 } 
