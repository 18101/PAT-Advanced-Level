/*1015. Reversible Primes (20)
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime. 
Now given any two positive integers N (< 105) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D. 
Input Specification: 
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.
Output Specification: 
For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.
Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

bool isPrime(int a)
{
	if(a==1||a==0)
		return false;
	for(int i=2;i<=sqrt(a);i++)
	{
		if(!(a%i))
			return false;
	}
	return true;
}
int main()
{
	int a,b;
	int c[50];
	while(true)
	{
		memset(c,0,sizeof(c));
		scanf("%d",&a);
		if(a<0)
			return 0;
		scanf("%d",&b);
		if(!isPrime(a))
		{
			printf("No\n");
			continue;
		}
		int j=0;
		for(j=0;a;j++)
		{
			c[j]=a%b;
			a=a/b;
		}
		for(int i=0;i<j;i++)
		{
			a=a*b+c[i];
		}
		if(!isPrime(a))
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
