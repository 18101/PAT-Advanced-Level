/*1101. Quick Sort (25)
There is a classical process named partition in the famous quick sort algorithm. In this process we typically choose one element as the pivot. Then the elements less than the pivot are moved to its left and those larger than the pivot to its right. Given N distinct positive integers after a run of partition, could you tell how many elements could be the selected pivot for this partition?
For example, given N = 5 and the numbers 1, 3, 2, 4, and 5. We have:

1 could be the pivot since there is no element to its left and all the elements to its right are larger than it;
3 must not be the pivot since although all the elements to its left are smaller, the number 2 to its right is less than it as well;
2 must not be the pivot since although all the elements to its right are larger, the number 3 to its left is larger than it as well;
and for the similar reason, 4 and 5 could also be the pivot.
Hence in total there are 3 pivot candidates.
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<= 105). Then the next line contains N distinct positive integers no larger than 109. The numbers in a line are separated by spaces.
Output Specification: 
For each test case, output in the first line the number of pivot candidates. Then in the next line print these candidates in increasing order. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.
Sample Input: 
5
1 3 2 4 5
Sample Output:
3
1 4 5
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int a[100005],b[100005],c[100005],n;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	c[0]=a[0];
	for(int i=1;i<n;i++)
	{
		c[i]=max(c[i-1],a[i]);
	}
	sort(b,b+n);
	int count=0;
	vector<int> v;
	if(a[0]==b[0])
	{
		count++;
		v.push_back(a[0]);
	}
	if(n>1)
	{
		for(int i=1;i<n;i++)
		{
			if(a[i]==b[i]&&c[i]>c[i-1])
			{
				count++;
				v.push_back(a[i]);
			}
		}
	}
	printf("%d\n",count);
	if(v.size())
	{
		printf("%d",v[0]);
		if(v.size()>1)
		{
			for(int i=1;i<v.size();i++)
			{
				printf(" %d",v[i]);
			}
		}
	}
	printf("\n");
	return 0;
 } 
