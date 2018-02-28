/*1034. Head of a Gang (30)
One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threshold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.
Input Specification: 
Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 1000), the number of phone calls and the weight threshold, respectively. Then N lines follow, each in the following format:
Name1 Name2 Time
where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.
Output Specification: 
For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the alphabetical order of the names of the heads.
Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3
Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
struct node{
	int number;
	int time;
};
vector<node> v[17580];
vector<node> vga;
bool flag[17580]={false};
node ga;
int Getint(char a[])
{
	int ans=a[0]-'A';
	for(int i=1;i<=2;i++)
	{
		ans=ans*26+(a[i]-'A');
	}
	return ans;
}
int times[17580];
int totaltime;
void DFS(int a)//
{
	flag[a]=true;
	for(int i=0;i<v[a].size();i++)
	{
		int uu=v[a][i].number;
		if(!flag[uu])
		{
			ga.time++;
			totaltime+=times[uu];
			if(times[uu]>times[ga.number])
				ga.number=uu;
			DFS(uu);
		}
	}
}
bool cmp(node a,node b)
{
	return a.number<b.number;
}
void GetChar(int a)
{
	printf("%c",a/26/26+'A');
	printf("%c",a/26%26+'A');
	printf("%c",a%26+'A');
}
int main()
{
	memset(times,0,sizeof(times));
	int n,k;
	char namea[4],nameb[4];
	int na,nb;
	node tempnode;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%s %s %d",namea,nameb,&tempnode.time);
		na=Getint(namea);
		nb=Getint(nameb);
		tempnode.number=nb;
		v[na].push_back(tempnode);
		tempnode.number=na;
		v[nb].push_back(tempnode);
		times[na]+=tempnode.time;
		times[nb]+=tempnode.time;
	}
	for(int i=0;i<17580;i++)
	{
		if(!v[i].empty()&&!flag[i])
		{
			ga.number=i;
			ga.time=1;
			totaltime=times[i];
			DFS(i);
			totaltime/=2;
			if(totaltime>k&&ga.time>2)
			vga.push_back(ga);
		}
	}
	if(vga.empty())
		printf("0");
	else
	{
		sort(vga.begin(),vga.end(),cmp);
		printf("%d\n",vga.size());
		for(int i=0;i<vga.size();i++)
		{
			GetChar(vga[i].number);
			printf(" %d\n",vga[i].time);
		}
	}
	return 0;
} 
