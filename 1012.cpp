/*1012. The Best Rank (25)
To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algebra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.
For example, The grades of C, M, E and A - Average of 4 students are given as the following:
StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.
Input
Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (<=2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.
Output
For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.
The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.
If a student is not on the grading list, simply output "N/A".
Sample Input
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output
1 C
1 M
1 E
1 A
3 A
N/A
*/
#include <iostream>
#include <cstdio>
#include <cstring> 
#include <algorithm>
using namespace std;
struct student{
	int id;
	int score[4];
	int rank[4];
	int bestrank;
}st[2000];
int pos[1000000];
int ss=-1;//
bool cmp(student a,student b)
{
	return a.score[ss]>b.score[ss];
}
int main()
{
	char ch[4]={'A','C','M','E'};
	memset(pos,-1,sizeof(pos));
	memset(st,0,sizeof(st));
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&st[i].id,&st[i].score[1],&st[i].score[2],&st[i].score[3]);
		st[i].score[0]=(int)((st[i].score[1]+st[i].score[2]+st[i].score[3])/3.0+0.5);
	} 
	for(int i=0;i<4;i++)
	{
		ss=i;
		sort(st,st+n,cmp);
		st[0].rank[i]=1;
		for(int j=1;j<n;j++)
		{
			if(st[j].score[i]==st[j-1].score[i])
				st[j].rank[i]=st[j-1].rank[i];
			else
				st[j].rank[i]=j+1;
		}
	}
	for(int i=0;i<n;i++)
	{
		pos[st[i].id]=i;
		int br=0;
		for(int j=1;j<4;j++)
		{
			if(st[i].rank[j]<st[i].rank[br])
			{
				br=j;
			}
		}
		st[i].bestrank=br;
	}
	for(int i=0;i<m;i++)
	{
		int x;
		scanf("%d",&x);
		if(pos[x]==-1)
		{
			printf("N/A\n");
		}
		else
		{
			printf("%d %c\n",st[pos[x]].rank[st[pos[x]].bestrank],ch[st[pos[x]].bestrank]);
		}
	}
} 
