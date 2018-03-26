/*1144. The Missing Number (20)
Given N integers, you are supposed to find the smallest positive integer that is NOT in the given list. 
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<= 105). Then N integers are given in the next line, separated by spaces. All the numbers are in the range of int. 
Output Specification: 
Print in a line the smallest positive integer that is missing from the input list.
Sample Input:
10
5 -25 9 6 1 3 4 2 5 17
Sample Output:
7
*/
#include <iostream>
#include <cstdio>
using namespace std;
bool a[100005]={false};
int main()
{
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(x<100005&&x>0)
		{
			a[x]=true;
		}
	}
	for(int i=1;i<100005;i++)
	{
		if(!a[i])
		{
			printf("%d",i);
			break;
		}
	}
	return 0;
}
