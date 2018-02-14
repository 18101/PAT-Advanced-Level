/*1009. Product of Polynomials (25)
This time, you are supposed to find A*B where A and B are two polynomials.
Input Specification: 
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000. 

Output Specification: 
For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place. 
Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 3 3.6 2 6.0 1 1.6
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
double exponents[2001];
struct node{
	int e;
	double c;
}po1[11],po2[11];
int main()
{
	int k1,k2,e,ee,count;
	double c,cc;
	vector<int> v;
	memset(exponents,0,sizeof(exponents));
	scanf("%d",&k1);
	for(int i=0;i<k1;i++)
	{
		scanf("%d %lf",&po1[i].e,&po1[i].c);
	}
	scanf("%d",&k2);
	for(int i=0;i<k2;i++)
	{
		scanf("%d %lf",&e,&c);
		for(int i=0;i<k1;i++)
		{
			ee=e+po1[i].e;
			cc=c*po1[i].c;
			exponents[ee]+=cc;
		}
	}
	for(int i=2000;i>=0;i--)
	{
		if(exponents[i])
		{
			count++;
			v.push_back(i);
		}
	}
	printf("%d",count);
	for(int i=0;i<v.size();i++)
	{
		printf(" %d %.1f",v[i],exponents[v[i]]);
	}
	return 0;
 } 
