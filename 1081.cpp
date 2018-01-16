/*1081. Rational Sum (20)
Given N rational numbers in the form "numerator/denominator", you are supposed to calculate their sum.
Input Specification: 
Each input file contains one test case. Each case starts with a positive integer N (<=100), followed in the next line N rational numbers "a1/b1 a2/b2 ..." where all the numerators and denominators are in the range of "long int". If there is a negative number, then the sign must appear in front of the numerator.
Output Specification: 
For each test case, output the sum in the simplest form "integer numerator/denominator" where "integer" is the integer part of the sum, "numerator" < "denominator", and the numerator and the denominator have no common factor. You must output only the fractional part if the integer part is 0.
Sample Input 1:
5
2/5 4/15 1/30 -2/60 8/3
Sample Output 1:
3 1/3
Sample Input 2:
2
4/3 2/3
Sample Output 2:
2
Sample Input 3:
3
1/3 -1/6 1/8
Sample Output 3:
7/24
*/
#include <iostream>
#include <cstdio> 
#include <cstring>
#include <cmath>
using namespace std;

struct re
{
	long long re1;
	long long re2;
};
long long gcd(long long a,long long b)
{
	return (!b)?a:gcd(b,a%b);
}
int main()
{
	int n;
	long long a0,b0,a,b;
	scanf("%d",&n);
	scanf("%lld/%lld",&a0,&b0);
	for(int i=1;i<n;i++)
	{
		scanf("%lld/%lld",&a,&b);
		if(!a0)
		{
			a0=a;
			b0=b;
		}
		else if(a&&a0)
		{
			a0=a0*b+a*b0;
			b0=b0*b;
			long long e=gcd(a0,b0);
			a0/=e;
			b0/=e;
		}
	}
	long long s1,s2;
	s1=a0/b0;
	s2=a0%b0;
	if(!a0)
		printf("0");
	else if(!s1)
		printf("%lld/%lld",a0,b0);
	else if(!s2)
		printf("%lld",s1);
	else
		printf("%lld %lld/%lld",s1,s2,b0);
	return 0;
}
