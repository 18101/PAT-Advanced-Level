/*
1088. Rational Arithmetic (20)
For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference, product and quotient.
Input Specification: 
Each input file contains one test case, which gives in one line the two rational numbers in the format "a1/b1 a2/b2". The numerators and the denominators are all in the range of long int. If there is a negative sign, it must appear only in front of the numerator. The denominators are guaranteed to be non-zero numbers.
Output Specification: 
For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. The format of each line is "number1 operator number2 = result". Notice that all the rational numbers must be in their simplest form "k a/b", where k is the integer part, and a/b is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. If the denominator in the division is zero, output "Inf" as the result. It is guaranteed that all the output integers are in the range of long int.
Sample Input 1:
2/3 -4/2
Sample Output 1:
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
Sample Input 2:
5/3 0/6
Sample Output 2:
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/
#include <iostream>
#include <cstdio> 
#include <cstring>
#include <cmath>
using namespace std;
long long gcd(long long a,long long b)
{
	return (!b)?a:gcd(b,a%b);
}
void Get(long long a,long long b)
{
	if(a==0)
	{
		printf("0");
		return;
	}
	else
	{
		long long c,d,e;
		e=gcd(abs(a),b);
		a=a/e;
		b=b/e;
		c=a/b;
		d=a%b;
		if(d==0)
		{
			if(c>0)
				printf("%lld",c);
			else
				printf("(%lld)",c);
		}
		else if(c==0)
		{
			if(d>0)
				printf("%lld/%lld",a,b);
			else
				printf("(%lld/%lld)",a,b);
		}
		else if(c>0)
		{
			printf("%lld %lld/%lld",c,d,b);
		}
		else
		{
			printf("(%lld %lld/%lld)",c,d*-1,b);
		}
	}
}
int main()
{
	long long a,b,c,d,a2,b2,c2,d2;
	scanf("%lld/%lld %lld/%lld",&a,&b,&c,&d);
	a2=d*a;
	c2=b*c;
	b2=d2=b*d;
	Get(a,b);
	printf(" + ");
	Get(c,d);
	printf(" = ");
	Get(a2+c2,b2);
	printf("\n");
	Get(a,b);
	printf(" - ");
	Get(c,d);
	printf(" = ");
	Get(a2-c2,b2);
	printf("\n");
	Get(a,b);
	printf(" * ");
	Get(c,d);
	printf(" = ");
	Get(a*c,b*d);
	printf("\n");
	Get(a,b);
	printf(" / ");
	Get(c,d);
	printf(" = ");
	if(c==0)
		printf("Inf");
	else
	{
		if(b*c<0)
			Get(a*-1*d,b*-1*c);
		else
			Get(a*d,b*c);
	}	
		
	return 0;
}
