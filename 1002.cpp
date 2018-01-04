/*
1002. A+B for Polynomials (25)
This time, you are supposed to find A+B where A and B are two polynomials.
Input
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000. 

Output
For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place. 
Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 2 1.5 1 2.9 0 3.2
*/
#include <iostream>
#include <cstdio> 
using namespace std;

double f[1001];
int main(int argc, char** argv) {
	int K1,K2,a,count;
	double b;
	scanf("%d",&K1);
	for(int i=0;i<K1;i++)
	{
		scanf("%d",&a);
		scanf("%lf",&b);
		f[a]+=b;
	}
	scanf("%d",&K2);
	for(int i=0;i<K2;i++)
	{
		scanf("%d",&a);
		scanf("%lf",&b);
		f[a]+=b;
	}
	for(int i=0;i<=1000;i++)
	{
		if(f[i])
			count++;
	}
	printf("%d",count);
	for(int i=1000;i>=0;i--)
	{
		if(f[i])
		{
			printf(" %d %.1f",i,f[i]);//Please be accurate to 1 decimal place指精确到小数点后一位，直接".1f" 
		}
	}
	return 0;
}
