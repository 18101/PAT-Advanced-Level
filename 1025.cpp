/*1025. PAT Ranking (25)
Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.
Input Specification: 
Each input file contains one test case. For each case, the first line contains a positive number N (<=100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.
Output Specification: 
For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:
registration_number final_rank location_number local_rank
The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.
Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
using namespace std;
struct student{
	char id[14];
	int score;
	int local;
	int rank;
	int tr;
}st[30005];
int nn[101];

bool cmp1(student a,student b)
{
	return a.score>b.score;
}
bool cmp2(student a,student b)
{
	if(a.score==b.score)
		return strcmp(a.id,b.id)<0;
	return a.score>b.score;
}
void Get(int a,int b)
{
	sort(st+a,st+a+b,cmp1);
	st[a].rank=1;
	for(int i=a+1;i<a+b;i++)
	{
		if(st[i].score==st[i-1].score)
			st[i].rank=st[i-1].rank;
		else
			st[i].rank=i-a+1;
	}
}
int main()
{
	memset(st,0,sizeof(st));
	int n,a=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&nn[i]);
		for(int j=0;j<nn[i];j++)
		{
			scanf("%s %d",st[a+j].id,&st[a+j].score);
			st[a+j].local=i;
		}
		Get(a,nn[i]);
		a+=nn[i];
	}
	sort(st,st+a,cmp2);
	st[0].tr=1;
	printf("%d\n",a);
	if(a)
		printf("%s %d %d %d\n",st[0].id,st[0].tr,st[0].local,st[0].rank);
	for(int i=1;i<a;i++)
	{
		if(st[i].score==st[i-1].score)
			st[i].tr=st[i-1].tr;
		else
			st[i].tr=i+1;
		printf("%s %d %d %d\n",st[i].id,st[i].tr,st[i].local,st[i].rank);
	}
	return 0;
 } 
