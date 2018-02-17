/*1095. Cars on Campus (30)
Zhejiang University has 6 campuses and a lot of gates. From each gate we can collect the in/out times and the plate numbers of the cars crossing the gate. Now with all the information available, you are supposed to tell, at any specific time point, the number of cars parking on campus, and at the end of the day find the cars that have parked for the longest time period.
Input Specification: 
Each input file contains one test case. Each case starts with two positive integers N (<= 10000), the number of records, and K (<= 80000) the number of queries. Then N lines follow, each gives a record in the format
plate_number hh:mm:ss status
where plate_number is a string of 7 English capital letters or 1-digit numbers; hh:mm:ss represents the time point in a day by hour:minute:second, with the earliest time being 00:00:00 and the latest 23:59:59; and status is either in or out.
Note that all times will be within a single day. Each "in" record is paired with the chronologically next record for the same car provided it is an "out" record. Any "in" records that are not paired with an "out" record are ignored, as are "out" records not paired with an "in" record. It is guaranteed that at least one car is well paired in the input, and no car is both "in" and "out" at the same moment. Times are recorded using a 24-hour clock. 
Then K lines of queries follow, each gives a time point in the format hh:mm:ss. Note: the queries are given in ascending order of the times.
Output Specification: 
For each query, output in a line the total number of cars parking on campus. The last line of output is supposed to give the plate number of the car that has parked for the longest time period, and the corresponding time length. If such a car is not unique, then output all of their plate numbers in a line in alphabetical order, separated by a space.
Sample Input:
16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00
Sample Output:
1
4
5
2
1
0
1
JH007BD ZD00001 07:20:09
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
struct car{
	char id[8];
	int time;
	int flag;
}cars[10000];
int cars1[10000],cars2[10000];
bool cmp(car a,car b)
{
	if(!strcmp(a.id,b.id))
		return a.time<b.time;
	return strcmp(a.id,b.id)<0;
}
bool cmp2(car a,car b)
{
	return a.time<b.time;
}
int main()
{
	int n,m,a,b,c,totaltime,maxtime=-1,x;
	char inout[4];
	vector<car> mc;
	vector<string> vv;
	map<string,int> mp;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",cars[i].id);
		scanf("%d:%d:%d",&a,&b,&c);
		cars[i].time=a*3600+b*60+c;
		scanf("%s",inout);
		if(inout[0]=='i')
			cars[i].flag=1;
		else
			cars[i].flag=-1;
	}
	sort(cars,cars+n,cmp);
	for(int i=0;i<n-1;i++)
	{
		if((!strcmp(cars[i].id,cars[i+1].id))&&cars[i].flag==1&&cars[i+1].flag==-1)
		{
			totaltime=cars[i+1].time-cars[i].time;
			mp[cars[i].id]+=totaltime;
			if(mp[cars[i].id]==maxtime)
			{
				vv.push_back(cars[i].id);
			}
			else if(mp[cars[i].id]>maxtime)
			{
				maxtime=mp[cars[i].id];
				vv.clear();
				vv.push_back(cars[i].id);
			}
			mc.push_back(cars[i]);
			mc.push_back(cars[i+1]);
			i++;
		}
	}
	sort(mc.begin(),mc.end(),cmp2);
	cars1[0]=mc[0].time;
	cars2[0]=1;
	int jj=0,pp=0;
	for(int i=1;i<mc.size();i++)
	{
		pp=cars2[jj];
		if(cars1[jj]!=mc[i].time)
			{
				cars1[++jj]=mc[i].time;
			}
		cars2[jj]=pp+mc[i].flag;
	}
	int lb;
	int inouts=0;
	for(int i=0;i<m;i++)
	{
		scanf("%d:%d:%d",&a,&b,&c);
		x=a*3600+b*60+c;
		if(x>=cars1[jj])
		{
			printf("%d\n",cars2[jj]);
			continue;
		}
		while(true)
		{
			if(cars1[inouts]>x)
			{
				printf("%d\n",cars2[inouts-1]);
				break;
			}
			inouts++;
		}
	}
	sort(vv.begin(),vv.end());
	for(int i=0;i<vv.size();i++)
		printf("%s ",vv[i].c_str());
	a=maxtime/3600;
	c=maxtime%60;
	b=maxtime%3600/60;
	printf("%02d:%02d:%02d",a,b,c);
	return 0;
 } 
