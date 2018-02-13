/*1067. Sort with Swap(0,*) (25)
Given any permutation of the numbers {0, 1, 2,..., N-1}, it is easy to sort them in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:
Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4} 
Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers. 
Input Specification: 
Each input file contains one test case, which gives a positive N (<=105) followed by a permutation sequence of {0, 1, ..., N-1}. All the numbers in a line are separated by a space.
Output Specification: 
For each case, simply print in a line the minimum number of swaps need to sort the given permutation.
Sample Input:
10 3 5 7 2 6 4 9 0 8 1
Sample Output:
9
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[100000];
bool f[100000];
int main()
{
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
	int n,count=0,k=0,step,j;
	bool flag=false;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(!f[i]&&a[i]!=i)
		{
			count++;
			j=i;
			while(a[j]!=j)
		{
			k++;
			f[j]=true;
			j=a[j];
			if(f[j])
			{
				break;
			}
		}
		}	
	}
	step=k+count;
	if(a[0])
	{
		step-=2;
	}
	printf("%d",step);
	return 0;
 } 
