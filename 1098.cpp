/*1098. Insertion or Heap Sort (25)
According to Wikipedia:
Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.
Heap sort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element and moving that to the sorted region. it involves the use of a heap data structure rather than a linear-time search to find the maximum.
Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<=100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.
Output Specification: 
For each test case, print in the first line either "Insertion Sort" or "Heap Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resuling sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.
Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:
10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
Sample Output 2:
Heap Sort
5 4 3 1 0 2 6 7 8 9
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[105];
int b[105];
void downAdjust(int i,int high)
{
	int j=2*i+1;
	if(j<=high)
	{
		if(j+1<=high)
		{
			if(b[j]<b[j+1])
				j++;
		}
		if(b[j]>b[i])
		{
			swap(b[j],b[i]);
			i=j;
			downAdjust(i,high);
		}
	}
}
int main()
{
	int n,p=0;
	scanf("%d",&n);
	int q;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	for(int i=0;i<n-1;i++)
	{
		if(b[i]>b[i+1])
		{
			p=i;
			break;
		}
	}
	for(int i=p+1;i<n;i++)
	{
		q=i;
		if(a[i]!=b[i])
		{
			break;
		}
	}
	if(q==n-1)
	{
		printf("Insertion Sort\n");
		sort(b,b+p+2);
	}
	else
	{
		printf("Heap Sort\n");
		sort(a,a+n);
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]!=b[i])
			{
				q=i;
				break;
			}
		}
		swap(b[q],b[0]);
		downAdjust(0,q-1);
	}
	printf("%d",b[0]);
	for(int i=1;i<n;i++)
		printf(" %d",b[i]);
	return 0;
 } 
