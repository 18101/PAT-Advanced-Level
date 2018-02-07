/*1024. Palindromic Number (25)
A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers. 
Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484. 
Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it. 
Input Specification: 
Each input file contains one test case. Each case consists of two positive numbers N and K, where N (<= 1010) is the initial numer and K (<= 100) is the maximum number of steps. The numbers are separated by a space.
Output Specification: 
For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.
Sample Input 1:
67 3
Sample Output 1:
484
2
Sample Input 2:
69 3
Sample Output 2:
1353
3
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int number[150];
int number2[150];
int Double(int a)
{
	memset(number2,0,sizeof(number2));
	int up=0;
	int x;
	for(int i=149;i>=a;i--)
	{
		number2[i]=number[a+149-i];
	}
	for(int i=149;i>=a;i--)
	{
		x=number[i]+number2[i]+up;
		if(x>=10)
		{
			number[i]=x-10;
			up=1;
		}
		else
		{
			number[i]=x;
			up=0;
		}
	}
	if(up)
	{
		number[a-1]=1;
		return 151-a;
	}
	else
		return 150-a;
}
int main()
{
	long long n;
	int k;
	scanf("%lld %d",&n,&k);
	int c=0;
	bool flag1=false;
	while(n)
	{
		number[149-c]=n%10;
		n/=10;
		c++;
	}
	for(int i=0;i<=k;i++)
	{
		flag1=true;
		for(int j=150-c;j<=(299-c)/2;j++)
		{
			if(number[j]!=number[299-c-j])
			{
				flag1=false;
				break;
			}
		}
		if(flag1||(i==k))
		{
			for(int j=150-c;j<=149;j++)
			{
				printf("%d",number[j]);
			}
			printf("\n%d\n",i);
			return 0;
		}
		c=Double(150-c);
	}
	return 0;
 } 
