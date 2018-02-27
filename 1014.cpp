/*1014. Waiting in Line (30)
Suppose a bank has N windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. The rules for the customers to wait in line are: 
The space inside the yellow line in front of each window is enough to contain a line with M customers. Hence when all the N lines are full, all the customers after (and including) the (NM+1)st one will have to wait in a line behind the yellow line. 
Each customer will choose the shortest line to wait in when crossing the yellow line. If there are two or more lines with the same length, the customer will always choose the window with the smallest number. 
Customer[i] will take T[i] minutes to have his/her transaction processed. 
The first N customers are assumed to be served at 8:00am. 
Now given the processing time of each customer, you are supposed to tell the exact time at which a customer has his/her business done.
For example, suppose that a bank has 2 windows and each window may have 2 custmers waiting inside the yellow line. There are 5 customers waiting with transactions taking 1, 2, 6, 4 and 3 minutes, respectively. At 08:00 in the morning, customer1 is served at window1 while customer2 is served at window2. Customer3 will wait in front of window1 and customer4 will wait in front of window2. Customer5 will wait behind the yellow line.
At 08:01, customer1 is done and customer5 enters the line in front of window1 since that line seems shorter now. Customer2 will leave at 08:02, customer4 at 08:06, customer3 at 08:07, and finally customer5 at 08:10.
Input
Each input file contains one test case. Each case starts with a line containing 4 positive integers: N (<=20, number of windows), M (<=10, the maximum capacity of each line inside the yellow line), K (<=1000, number of customers), and Q (<=1000, number of customer queries).
The next line contains K positive integers, which are the processing time of the K customers.
The last line contains Q positive integers, which represent the customers who are asking about the time they can have their transactions done. The customers are numbered from 1 to K.
Output
For each of the Q customers, print in one line the time at which his/her transaction is finished, in the format HH:MM where HH is in [08, 17] and MM is in [00, 59]. Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, you must output "Sorry" instead.
Sample Input
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
Sample Output
08:07
08:06
08:10
17:00
Sorry
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector> 
#include <queue>
#include <utility>
using namespace std;
struct node{
	int time;
	int number;
	friend bool operator < (node a,node b)
	{
		if(a.time==b.time)
			return a.number>b.number;
		return a.time>b.time;
	}
};
pair<int,int> process[1000];
vector<int> windows[20];
priority_queue<node> pq;

void Get(int x)
{
	if(process[x].second>=540)
		printf("Sorry\n");
	else
	{
		int a=process[x].first/60+8;
		int b=process[x].first%60;
		printf("%02d:%02d\n",a,b);
	}
}
int main()
{
	int n,m,k,q,people=0;
	node tempnode;
	scanf("%d %d %d %d",&n,&m,&k,&q);
	for(int i=0;i<m;i++)
	{
		if(people>=k)
			break;
		for(int j=0;j<n;j++)
		{
			if(people>=k)
				break;
			people++;
			tempnode.number=j;
			scanf("%d",&tempnode.time);
			process[people].second=0;
			if(!windows[tempnode.number].empty())	
			{
				process[people].second=*(windows[tempnode.number].end()-1);
				tempnode.time+=*(windows[tempnode.number].end()-1);
			}
			windows[tempnode.number].push_back(tempnode.time);
			process[people].first=tempnode.time;
			pq.push(tempnode);
		}
	}
	while(people<k)
	{
		node tnode=pq.top();
		pq.pop();
		people++;
		scanf("%d",&tempnode.time);
		tempnode.number=tnode.number;
		process[people].second=*(windows[tempnode.number].end()-1);
		tempnode.time+=*(windows[tempnode.number].end()-1);
		windows[tempnode.number].push_back(tempnode.time);
		process[people].first=tempnode.time;
		pq.push(tempnode);			
	}
	int x;
	for(int i=0;i<q;i++)
	{
		scanf("%d",&x);
		Get(x);
	}
	return 0;
}
