/*1132. Cut Integer (20)
Cutting an integer means to cut a K digits long integer Z into two integers of (K/2) digits long integers A and B. For example, after cutting Z = 167334, we have A = 167 and B = 334. It is interesting to see that Z can be devided by the product of A and B, as 167334 / (167 x 334) = 3. Given an integer Z, you are supposed to test if it is such an integer. 
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<= 20). Then N lines follow, each gives an integer Z (10<=Z<=231). It is guaranteed that the number of digits of Z is an even number.
Output Specification: 
For each case, print a single line "Yes" if it is such a number, or "No" if not.
Sample Input:
3
167334
2333
12345678
Sample Output:
Yes
No
No
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int n;
	char k[31],a[31],b[31];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%s",k);
		int l;
		l=strlen(k)/2;
		for(int i=0;i<l;i++)
		{
			a[i]=k[i];
		}
		for(int i=l;i<strlen(k);i++)
		{
			b[i-l]=k[i];
		}
		int kk,aa,bb;
		sscanf(k,"%d",&kk);
		sscanf(a,"%d",&aa);
		sscanf(b,"%d",&bb);
		if((aa==0)||(bb==0))
		{
			printf("No\n");
		}
		else if(kk%(aa*bb))
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
 } 
