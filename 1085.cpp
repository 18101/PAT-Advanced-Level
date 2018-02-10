/*1085. Perfect Sequence (25)
Given a sequence of positive integers and another positive integer p. The sequence is said to be a "perfect sequence" if M <= m * p where M and m are the maximum and minimum numbers in the sequence, respectively. 
Now given a sequence and a parameter p, you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence. 
Input Specification: 
Each input file contains one test case. For each case, the first line contains two positive integers N and p, where N (<= 105) is the number of integers in the sequence, and p (<= 109) is the parameter. In the second line there are N positive integers, each is no greater than 109.
Output Specification: 
For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.
Sample Input:
10 8
2 3 20 4 5 1 6 7 8 9
Sample Output:
8
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	long long p;
	int nu[100000];
	scanf("%d %d",&n,&p);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&nu[i]);
	}
	sort(nu,nu+n);
	int k=1,ans=1;
	for(int i=0;i<=n-2;i++)
	{
		for(int j=i+k;j<n;j++)
		{
			if(nu[j]<=nu[i]*p)
			{
				k=j-i+1;
				if(k>ans)
				{
					ans=k;
				}
			}
			else
				break;
		}
	}
	printf("%d",ans);
	return 0;
 } 
