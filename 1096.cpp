/*1096. Consecutive Factors (20)
Among all the factors of a positive integer N, there may exist several consecutive numbers. For example, 630 can be factored as 3*5*6*7, where 5, 6, and 7 are the three consecutive numbers. Now given any positive N, you are supposed to find the maximum number of consecutive factors, and list the smallest sequence of the consecutive factors. 
Input Specification: 
Each input file contains one test case, which gives the integer N (1<N<231).
Output Specification: 
For each test case, print in the first line the maximum number of consecutive factors. Then in the second line, print the smallest sequence of the consecutive factors in the format "factor[1]*factor[2]*...*factor[k]", where the factors are listed in increasing order, and 1 is NOT included. 
Sample Input:
630
Sample Output:
3
5*6*7
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
	int count[32];
	memset(count,0,sizeof(count));
	int n;
	scanf("%d",&n);
	for(int i=sqrt(n);i>=2;i--)
	{
		int j=i;
		int c=0;
		int n2=n;
		for(;!(n2%j);j++)
		{
			n2/=j;
			c++;
		}
		count[c]=i;
	}
	int max=0,begin;
	for(int i=31;i>0;i--)
	{
		if(count[i])
		{
			begin=count[i];
			max=i;
			break;
		}
	}
	if(max==0)
		printf("1\n%d",n);
	else
	{
		printf("%d\n%d",max,begin);
		for(int i=1;i<max;i++)
		{
			printf("*%d",begin+i);
		}
	}
	return 0;
 } 
