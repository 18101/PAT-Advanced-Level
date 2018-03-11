/*1125. Chain the Ropes (25)
Given some segments of rope, you are supposed to chain them into one rope. Each time you may only fold two segments into loops and chain them into one piece, as shown by the figure. The resulting chain will be treated as another segment of rope and can be folded again. After each chaining, the lengths of the original two segments will be halved. 

Your job is to make the longest possible rope out of N given segments. 
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (2 <= N <= 104). Then N positive integer lengths of the segments are given in the next line, separated by spaces. All the integers are no more than 104. 
Output Specification: 
For each case, print in a line the length of the longest possible rope that can be made by the given segments. The result must be rounded to the nearest integer that is no greater than the maximum length. 
Sample Input:
8
10 15 12 3 4 13 1 15
Sample Output:
14
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,data[10005];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
	}
	sort(data,data+n);
	double sum=(data[0]+data[1])/2;
	for(int i=2;i<n;i++)
	{
		sum=(data[i]+sum)*1.0/2;
	}
	printf("%d",(int)sum);
	return 0;
 } 