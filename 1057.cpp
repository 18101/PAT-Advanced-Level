/*1057. Stack (30)
Stack is one of the most fundamental data structures, which is based on the principle of Last In First Out (LIFO). The basic operations include Push (inserting an element onto the top position) and Pop (deleting the top element). Now you are supposed to implement a stack with an extra operation: PeekMedian -- return the median value of all the elements in the stack. With N elements, the median value is defined to be the (N/2)-th smallest element if N is even, or ((N+1)/2)-th if N is odd.
Input Specification: 
Each input file contains one test case. For each case, the first line contains a positive integer N (<= 105). Then N lines follow, each contains a command in one of the following 3 formats:
Push key
Pop
PeekMedian
where key is a positive integer no more than 105.
Output Specification: 
For each Push command, insert key into the stack and output nothing. For each Pop or PeekMedian command, print in a line the corresponding returned value. If the command is invalid, print "Invalid" instead. 
Sample Input:
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop
Sample Output:
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>
using namespace std;
int block[318]={0};
int table[100001]={0};
int number=0;
stack<int> st;
void GetPush(int x)
{
	block[x/316]++;
	table[x]++;
	st.push(x);
}
void GetPop(int num)
{
	if(num<=0)
	{
		printf("Invalid\n");
		return;
	}
	else
	{
		number--;
		int fd=st.top();
		printf("%d\n",fd);
		st.pop();
		table[fd]--;
		block[fd/316]--;
	}
}
void GetMedian(int num)
{
	if(num<=0)
	{
		printf("Invalid\n",num);
		return;
	}
	int x;
	if(num%2)
	{
		x=num/2+1;
	}
	else
	{
		x=num/2;
	}
	int ans=0,u=0;
	for(int i=0;i<=317;i++)
	{
		ans+=block[i];
		if(ans>=x)
		{
			u=i;
			ans-=block[i];
			break;
		}
	}
	int k=x-ans,pos=u*316;
	while(k>0)
	{
		k=k-table[pos];
		pos++;
	}
	printf("%d\n",pos-1);
}
int main()
{
	int n,x;
	char a[12];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",a);
		if(a[2]=='s')
		{
			scanf("%d",&x);
			GetPush(x);
			number++;
		}
		else if(a[2]=='p')
		{
			GetPop(number);
		}
		else
		{
			GetMedian(number);
		}
	}
	return 0;
} 
