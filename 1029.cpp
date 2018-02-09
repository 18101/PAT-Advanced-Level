/*1029. Median (25)
Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1={11, 12, 13, 14} is 12, and the median of S2={9, 10, 15, 16, 17} is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.
Given two increasing sequences of integers, you are asked to find their median.
Input
Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (<=1000000) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.
Output
For each test case you should output the median of the two given sequences in a line.
Sample Input
4 11 12 13 14
5 9 10 15 16 17
Sample Output
13
*/
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	vector<int> v1,v2,v3;
	int n1,n2,x,n;
	scanf("%d",&n1);
	for(int i=0;i<n1;i++)
	{
		scanf("%d",&x);
		v1.push_back(x);
	}
	scanf("%d",&n2);
	for(int i=0;i<n2;i++)
	{
		scanf("%d",&x);
		v2.push_back(x);
	}
	n=(n1+n2+1)/2;
	int k=0,kn1=0,kn2=0;
	while(k<n&&kn1<n1&&kn2<n2)
	{
		if(v1[kn1]<v2[kn2])
		{
			v3.push_back(v1[kn1]);
			kn1++;
		}
		else
		{
			v3.push_back(v2[kn2]);
			kn2++;
		}
		k++;
	}
	if(kn1==n1)
	{
		while(kn2<n2&&k<n)
		{
			v3.push_back(v2[kn2]);
			kn2++;
			k++;
		}
	}
	else if(kn2==n2)
	{
		while(kn1<n1&&k<n)
		{
			v3.push_back(v1[kn1]);
			kn1++;
			k++;
		}
	}
	printf("%d",v3[n-1]);
	return 0;
}
