/*1133. Splitting A Linked List (25)
Given a singly linked list, you are supposed to rearrange its elements so that all the negative values appear before all of the non-negatives, and all the values in [0, K] appear before all those greater than K. The order of the elements inside each class must not be changed. For example, given the list being 18¡ú7¡ú-4¡ú0¡ú5¡ú-6¡ú10¡ú11¡ú-2 and K being 10, you must output -4¡ú-6¡ú-2¡ú7¡ú0¡ú5¡ú10¡ú18¡ú11.
Input Specification: 
Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 105) which is the total number of nodes, and a positive K (<=1000). The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Data Next
where Address is the position of the node, Data is an integer in [-105, 105], and Next is the position of the next node. It is guaranteed that the list is not empty.
Output Specification: 
For each case, output in order (from beginning to the end of the list) the resulting linked list. Each node occupies a line, and is printed in the same format as in the input. 
Sample Input:
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
Sample Output:
33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool vis[100000]={false};
struct node{
	int value;
	int p;
}link[100000],data[100000],answer[100000];
int main()
{
	memset(data,0,sizeof(data));
	memset(answer,0,sizeof(answer));
	int head,n,k,x;
	scanf("%d %d %d",&head,&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		scanf("%d",&link[x].value);
		scanf("%d",&link[x].p);
	}
	int u=0;
	while(head!=-1)
	{
		data[u].p=head;
		data[u].value=link[head].value;
		u++;
		head=link[head].p;
	}
	int v=0;
	for(int i=0;i<u;i++)
	{
		if(data[i].value<0)
		{
			answer[v]=data[i];
			vis[i]=true;
			v++;
		}
	}
	for(int i=0;i<u;i++)
	{
		if(data[i].value<=k&&(vis[i]==false))
		{
			answer[v]=data[i];
			vis[i]=true;
			v++;
		}
	}
	for(int i=0;i<u;i++)
	{
		if(!vis[i])
		{
			answer[v]=data[i];
			vis[i]=true;
			v++;
		}
	}
	printf("%05d %d ",answer[0].p,answer[0].value);
	for(int i=1;i<v;i++)
	{
		printf("%05d\n%05d %d ",answer[i].p,answer[i].p,answer[i].value);
	}
	printf("-1");
	return 0;
 } 
