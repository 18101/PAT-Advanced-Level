/*1116. Come on! Let's C (20)
"Let's C" is a popular and fun programming contest hosted by the College of Computer Science and Technology, Zhejiang University. Since the idea of the contest is for fun, the award rules are funny as the following:
0. The Champion will receive a "Mystery Award" (such as a BIG collection of students' research papers...).
1. Those who ranked as a prime number will receive the best award -- the Minions (–°ª∆»À)!
2. Everyone else will receive chocolates. 
Given the final ranklist and a sequence of contestant ID's, you are supposed to tell the corresponding awards. 
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<=10000), the total number of contestants. Then N lines of the ranklist follow, each in order gives a contestant's ID (a 4-digit number). After the ranklist, there is a positive integer K followed by K query ID's.
Output Specification: 
For each query, print in a line "ID: award" where the award is "Mystery Award", or "Minion", or "Chocolate". If the ID is not in the ranklist, print "Are you kidding?" instead. If the ID has been checked before, print "ID: Checked". 
Sample Input:
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222
Sample Output:
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int ank[10005];
bool primes[10005]={false};
void isPrime()
{
	primes[1]=true;
	for(int i=2;i<10005;i++)
	{
		if(primes[i]==false)
		{
			for(int j=i*2;j<10005;j+=i)
			{
				primes[j]=true;
			}
		}
	}
}
int main()
{
	memset(ank,-1,sizeof(ank));
	int n,x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		ank[x]=i;
	}
	isPrime();
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&x);
		if(ank[x]==-1)
		{
			printf("%04d: Are you kidding?\n",x);
		}
		else if(!ank[x])
		{
			printf("%04d: Checked\n",x);
		}
		else if(ank[x]==1)
		{
			printf("%04d: Mystery Award\n",x);
			ank[x]=0;
		}
		else
		{
			if(!primes[ank[x]])
				printf("%04d: Minion\n",x);
			else
				printf("%04d: Chocolate\n",x);
			ank[x]=0;
		}
	}
	return 0;
 } 
