/*1097. Deduplication on a Linked List (25)
Given a singly linked list L with integer keys, you are supposed to remove the nodes with duplicated absolute values of the keys. That is, for each value K, only the first node of which the value or absolute value of its key equals K will be kept. At the mean time, all the removed nodes must be kept in a separate list. For example, given L being 21¡ú-15¡ú-15¡ú-7¡ú15, you must output 21¡ú-15¡ú-7, and the removed list -15¡ú15.
Input Specification: 
Each input file contains one test case. For each case, the first line contains the address of the first node, and a positive N (<= 105) which is the total number of nodes. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Key Next
where Address is the position of the node, Key is an integer of which absolute value is no more than 104, and Next is the position of the next node.
Output Specification: 
For each case, output the resulting linked list first, then the removed list. Each node occupies a line, and is printed in the same format as in the input. 
Sample Input:
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
Sample Output:
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
	int data;
	int next;
}link[100005];
struct outnode{
	int pos;
	int data;
}onode;
vector<outnode> llist,rlist;
bool value[10001]={false};

void output(vector<outnode> l)
{
	if(l.size())
	{
	for(int i=0;i<l.size()-1;i++)
	{
		printf("%05d %d %05d\n",l[i].pos,l[i].data,l[i+1].pos);		
	}
	}
	if(l.size())
		printf("%05d %d -1\n",l[l.size()-1].pos,l[l.size()-1].data);
}
int main()
{
	int h,n,a,b,c,count=0;
	scanf("%d %d",&h,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		link[a].data=b;
		link[a].next=c;
	}
	while(h!=-1&&count<n)
	{
		count++;
		int u=(int)abs(link[h].data);
		onode.data=link[h].data;
		onode.pos=h;
		if(!value[u])
		{
			value[u]=true;
			llist.push_back(onode);
		}
		else
		{
			rlist.push_back(onode);
		}
		h=link[h].next;
	}
	output(llist);
	output(rlist);
	return 0;
 } 
