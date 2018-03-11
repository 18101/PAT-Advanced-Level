/*1117. Eddington Number(25)
British astronomer Eddington liked to ride a bike. It is said that in order to show off his skill, he has even defined an "Eddington number", E -- that is, the maximum integer E such that it is for E days that one rides more than E miles. Eddington's own E was 87.
Now given everyday's distances that one rides for N days, you are supposed to find the corresponding E (<=N). 
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N(<=105), the days of continuous riding. Then N non-negative integers are given in the next line, being the riding distances of everyday.
Output Specification: 
For each case, print in a line the Eddington number for these N days. 
Sample Input:
10
6 7 6 9 3 10 8 2 7 8
Sample Output:
6
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int data[100005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,x;
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&data[i]);
	}
	sort(data+1,data+n+1,cmp);
	int j=1;
	bool flag=false;
	for(int i=1;i<=n;i++)
	{
		if(data[i]<=i)
		{
			j=i;
			flag=true;
			break;
		}
	}
	if(!flag)
	{
		if(data[1]<=1)
		{
			printf("0");
		}
		else
		{
			printf("100000");
		}
	}
	else
		printf("%d",j-1);
	return 0;
 } 
