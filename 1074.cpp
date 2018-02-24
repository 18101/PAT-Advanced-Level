/*1074. Reversing Linked List (25)
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1¡ú2¡ú3¡ú4¡ú5¡ú6, if K = 3, then you must output 3¡ú2¡ú1¡ú6¡ú5¡ú4; if K = 4, you must output 4¡ú3¡ú2¡ú1¡ú5¡ú6.
Input Specification: 
Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 105) which is the total number of nodes, and a positive K (<=N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Data Next
where Address is the position of the node, Data is an integer, and Next is the position of the next node.
Output Specification: 
For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input. 
Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/
#include <iostream>
#include <cstdio>
using namespace std;
struct node{
	int data;
	int next;
}link[100005];
int main()
{
	int h,n,k,a,b,c,pre,pos,temp;
	scanf("%d %d %d",&h,&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		link[a].data=b;
		link[a].next=c;
	}
	pre=h;
	temp=h;
	pos=h;
	int hh=h;
	int lastend;
	int p=h;
	n=0;
	while(p!=-1)
	{
		n++;
		p=link[p].next;
	}
	for(int j=0;j<n/k;j++)
	{
		for(int i=0;i<k;i++)
		{
			pre=link[pre].next;
		}
		lastend=pos;
		for(int i=0;i<k;i++)
		{
			temp=link[pos].next;
			link[pos].next=pre;
			pre=pos;
			pos=temp;
			if(!j)
				hh=pre;			
		}
		if(j!=n/k-1)
		{
			for(int i=0;i<k-1;i++)
			{
				link[lastend].next=link[link[lastend].next].next;
			}
		}
		pre=pos;
	}
	pre=hh;
	for(int i=0;i<n;i++)
	{
		if(link[pre].next==-1)
			break;
		printf("%05d %d %05d\n",pre,link[pre].data,link[pre].next);
		pre=link[pre].next;
	}
	printf("%05d %d %d\n",pre,link[pre].data,link[pre].next);
	return 0;
 } 
 //also can use another array to save data
 
