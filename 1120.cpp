/*
1120. Friend Numbers (20)
Two integers are called "friend numbers" if they share the same sum of their digits, and the sum is their "friend ID". For example, 123 and 51 are friend numbers since 1+2+3 = 5+1 = 6, and 6 is their friend ID. Given some numbers, you are supposed to count the number of different friend ID's among them. Note: a number is considered a friend of itself.
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N. Then N positive integers are given in the next line, separated by spaces. All the numbers are less than 104.
Output Specification: 
For each case, print in the first line the number of different frind ID's among the given integers. Then in the second line, output the friend ID's in increasing order. The numbers must be separated by exactly one space and there must be no extra space at the end of the line. 
Sample Input:
8
123 899 51 998 27 33 36 12
Sample Output:
4
3 6 9 26
*/
#include <iostream>
#include <cstdio> 
using namespace std;

bool sumdigits[37]={false}; 

int GetID(int a)
{
	int sumd;
	for(int i=1;i<=4;i++)
	{
		sumd+=a%10;
		a=a/10;
	}
	return sumd;
}
int main(){
	int N,a,count,k;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&a);
		sumdigits[GetID(a)]=true;
	}
	for(int i=0;i<37;i++)
	{
		if(sumdigits[i])
			count++;
	}
	printf("%d\n",count);
	for(int i=0;i<37;i++)
	{
		if(sumdigits[i])
		{
			printf("%d",i);
			k=i;
			break;
		}
	}
	for(int i=k+1;i<37;i++)
	{
		if(sumdigits[i])
			printf(" %d",i);
	}
	return 0;
}
