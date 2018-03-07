/*1105. Spiral Matrix (25)
This time your job is to fill a sequence of N positive integers into a spiral matrix in non-increasing order. A spiral matrix is filled in from the first element at the upper-left corner, then move in a clockwise spiral. The matrix has m rows and n columns, where m and n satisfy the following: m*n must be equal to N; m>=n; and m-n is the minimum of all the possible values.
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N. Then the next line contains N positive integers to be filled into the spiral matrix. All the numbers are no more than 104. The numbers in a line are separated by spaces.
Output Specification: 
For each test case, output the resulting matrix in m lines, each contains n numbers. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line. 
Sample Input:
12
37 76 20 98 76 42 53 95 60 81 58 93
Sample Output:
98 95 93
42 37 81
53 20 76
58 60 76
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
int data[10005];
int final[10002][102];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	memset(final,0,sizeof(final));
	int N,m,n;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&data[i]);
	}
	sort(data,data+N,cmp);
	m=(int)sqrt(N);
	if(m*m==N)
	{
		n=m;
	}
	else
	{
		m++;
		while(N%m)
		{
			m++;
		}
	n=N/m;
	}
//	printf("%d %d",m,n);
	int ii=1,jj=0,ff=0,count=0;
	for(int i=0;i<n+2;i++)
	{
		final[0][i]=1;
		final[m+1][i]=1;
	}
	for(int i=0;i<m+2;i++)
	{
		final[i][0]=1;
		final[i][n+1]=1;
	}
	while(true)
	{
		if(!(ff%4))
		{
		//	printf("\n%d %d\n",ii,jj);
			if(final[ii][jj+1])
			{
				break;
			}
			else
			{
				jj++;
				while(!final[ii][jj])
				{
					final[ii][jj++]=data[count++];
			//		printf("%d ",data[0]);
				}
				jj--;
			}
		}
		else if(ff%4==3)
		{
			if(final[ii-1][jj])
			{
				break;
			}
			else
			{
				ii--;
				while(!final[ii][jj])
				{
					final[ii--][jj]=data[count++];
				}
				ii++;
			}
		//	printf("\n%d %d\n",ii,jj);
		}
		else if(ff%4==2)
		{
			if(final[ii][jj-1])
			{
			//	printf("\n%d %d",ii,jj);
				break;
			}
			else
			{
				jj--;
				while(!final[ii][jj])
				{
					final[ii][jj--]=data[count++];
				}
				jj++;
			}
		}
		else
		{
			if(final[ii+1][jj])
			{
				break;
			}
			else
			{
				ii++;
				while(!final[ii][jj])
				{
					final[ii++][jj]=data[count++];
				}
				ii--;
			}
		}
		ff++;
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d",final[i][1]);
		for(int j=2;j<=n;j++)
		{
			printf(" %d",final[i][j]);
		}
		printf("\n");
	}
	return 0;
 } 
