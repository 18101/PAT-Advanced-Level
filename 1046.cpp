/*1046. Shortest Distance (20)
The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.
Input Specification: 
Each input file contains one test case. For each case, the first line contains an integer N (in [3, 105]), followed by N integer distances D1 D2 ... DN, where Di is the distance between the i-th and the (i+1)-st exits, and DN is between the N-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer M (<=104), with M lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than 107.
Output Specification: 
For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.
Sample Input:
5 1 2 4 14 9
3
1 3
2 5
4 1
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int td,n1,n2,s,d[100005],dis,mindis,x1,x2;
	scanf("%d",&n1);
	scanf("%d",&d[0]);
	td=d[0];
	for(int i=1;i<n1;i++)
	{
		scanf("%d",&s);
		td+=s;
		d[i]=d[i-1]+s;
	}
	scanf("%d",&n2);
	for(int i=0;i<n2;i++)
	{
		scanf("%d %d",&x1,&x2);
		if(x1==1)
			dis=d[x2-2];
		else if(x2==1)
			dis=d[x1-2];
		else if(x1>x2)
			dis=d[x1-2]-d[x2-2];
		else
			dis=d[x2-2]-d[x1-2];
		mindis=td-dis;
		if(dis<mindis)
			printf("%d\n",dis);
		else
			printf("%d\n",mindis);
	}
	return 0;
 } 
