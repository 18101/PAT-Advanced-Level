/*1052. Linked List Sorting (25)
A linked list consists of a series of structures, which are not necessarily adjacent in memory. We assume that each structure contains an integer key and a Next pointer to the next structure. Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.
Input Specification: 
Each input file contains one test case. For each case, the first line contains a positive N (< 105) and an address of the head node, where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Key Next
where Address is the address of the node in memory, Key is an integer in [-105, 105], and Next is the address of the next node. It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.
Output Specification: 
For each test case, the output format is the same as that of the input, where N is the total number of nodes in the list and all the nodes must be sorted order.
Sample Input:
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
Sample Output:
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=1000005;
struct Node{
	int address;
	int data;
	int next;
	bool flag;
}node[maxn];
bool cmp(Node a,Node b)
{
	if(a.flag==b.flag)
		return a.data<b.data;
	else
		return a.flag;
}
int main()
{
	memset(node,0,sizeof(node));
	int n,head,a;
	scanf("%d %d",&n,&head);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		node[a].address=a;
		scanf("%d %d",&node[a].data,&node[a].next);
	}
	int j=head,count=0;
	if(head==-1)
	{
		printf("0 -1");
		return 0;
	}
	while(j!=-1)
	{
		count++;
		node[j].flag=true;
		j=node[j].next;
	};
	sort(node,node+maxn,cmp);
	printf("%d %05d\n",count,node[0].address);
	for(int i=0;i<count-1;i++)
	{
		printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
	}
	printf("%05d %d -1",node[count-1].address,node[count-1].data);
	return 0;
 } 
