/*1007. Maximum Subsequence Sum (25)
Given a sequence of K integers { N1, N2, ..., NK }. A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.
Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence. 
Input Specification: 
Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space. 
Output Specification: 
For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence. 
Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int k[100001];
int main()
{
	int n;
	bool flag=false;
	int left=0,maxleft,maxright;
	long long ans=0,ansf=0,maxans=-1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k[i]);
		if(k[i]>=0)
			flag=true;
	}
	if(!flag)
	{
		printf("0 %d %d",k[0],k[n-1]);
		return 0; 
	}
	while(left<n)
	{
		ans=0;
		while(left<n&&k[left]<0)
		{
			left++;
		}
		for(int i=left;i<n;i++)
		{
			ans+=k[i];
			if(ans<0)
			{
				left=i+1;
				break;
			}
			if(ans>maxans)
			{
				maxans=ans;
				maxleft=left;
				maxright=i;
			}
			if(i==n-1)
			{
				left=n;
			}
		}
	}
	printf("%d %d %d",maxans,k[maxleft],k[maxright]);
	return 0;
 } 
