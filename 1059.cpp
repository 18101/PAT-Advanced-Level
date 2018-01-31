/*1059. Prime Factors (25)
Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p1^k1 * p2^k2 *бн*pm^km.
Input Specification: 
Each input file contains one test case which gives a positive integer N in the range of long int.
Output Specification: 
Factor N in the format N = p1^k1 * p2^k2 *бн*pm^km, where pi's are prime factors of N in increasing order, and the exponent ki is the number of pi -- hence when there is only one pi, ki is 1 and must NOT be printed out.
Sample Input:
97532468
Sample Output:
97532468=2^2*11*17*101*1291
*/
#include <cstdio>
#include <cstring>
#include <cmath>
int prime[10000];
struct temp{
	int a;
	int index;
};
temp t[11];
void Prime(int n)
{
	bool p[1000000]={false};
	int i=2,j=0;
	while(i<=n)
	{
		if(!p[i])
		{
			prime[j++]=i;
			for(int k=2*i;k<=n;k+=i)
			{
				p[k]=true;
			}
		}
		i++;
	}
}
int main()
{
	memset(prime,0,sizeof(prime));
	int n,n2,j=0;
	scanf("%d",&n);
	n2=n;
	if(n==1)
	{
		printf("1=1");
		return 0;
	}
	int sqr=sqrt(n);
	Prime(sqr);
	for(int i=0;prime[i]&&(prime[i]<=sqr);i++)
	{
		if(!(n%prime[i]))
		{
			t[j].a=prime[i];
			t[j].index=1;
			n/=prime[i];
			while(!(n%prime[i]))
			{
				t[j].index++;
				n/=prime[i];	
			}
			j++;
		}
	}
	if(n!=1)
	{
		t[j].a=n;
		t[j].index=1;
		j++;
	}
	printf("%d=",n2);
	for(int i=0;i<j;i++)
	{
		if(i)
			printf("*"); 
		printf("%d",t[i].a);
		if(t[i].index!=1)
			printf("^%d",t[i].index);
	}
	return 0;
}
