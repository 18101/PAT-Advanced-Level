/*1017. Queueing at Bank (25)
Suppose a bank has K windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. All the customers have to wait in line behind the yellow line, until it is his/her turn to be served and there is a window available. It is assumed that no window can be occupied by a single customer for more than 1 hour.
Now given the arriving time T and the processing time P of each customer, you are supposed to tell the average waiting time of all the customers.
Input Specification: 
Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=10000) - the total number of customers, and K (<=100) - the number of windows. Then N lines follow, each contains 2 times: HH:MM:SS - the arriving time, and P - the processing time in minutes of a customer. Here HH is in the range [00, 23], MM and SS are both in [00, 59]. It is assumed that no two customers arrives at the same time.
Notice that the bank opens from 08:00 to 17:00. Anyone arrives early will have to wait in line till 08:00, and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.
Output Specification: 
For each test case, print in one line the average waiting time of all the customers, in minutes and accurate up to 1 decimal place.
Sample Input:
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
Sample Output:
8.2
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct node{
	int time;
	int wait;
}nod;
bool cmp(node a,node b)
{
	return a.time<b.time;
}
int main()
{
	int n,k,a,b,c,d;
	long long ans=0;
	priority_queue<int,vector<int>,greater<int> > q;
	scanf("%d %d",&n,&k);
	vector<node> v;
	for(int i=0;i<k;i++)
	{
		q.push(28800);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d:%d:%d %d",&a,&b,&c,&d);
		a=a*3600+b*60+c;
		if(a>61200)
			continue;
		nod.wait=d*60;
		nod.time=a;
		v.push_back(nod);
	}
	sort(v.begin(),v.end(),cmp);
	if(!v.size())
	{
		printf("0.0");
		return 0;
	}
	int size=v.size();
	int ttop;
	for(int i=0;i<size;i++)
	{
		ttop=q.top();
		if(v[i].time>ttop)
		{
			q.pop();
			q.push(v[i].time+v[i].wait);
		}
		else
		{
			ans+=(ttop-v[i].time);
			q.pop();
			q.push(ttop+v[i].wait);
		}
	}
	printf("%.1f",ans*1.0/size/60);
	return 0;
}
