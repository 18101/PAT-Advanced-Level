/*1137. Final Grading (25)
For a student taking the online course "Data Structures" on China University MOOC (http://www.icourse163.org/), to be qualified for a certificate, he/she must first obtain no less than 200 points from the online programming assignments, and then receive a final grade no less than 60 out of 100. The final grade is calculated by G = (Gmid-termx 40% + Gfinalx 60%) if Gmid-term > Gfinal, or Gfinal will be taken as the final grade G. Here Gmid-term and Gfinal are the student's scores of the mid-term and the final exams, respectively.
The problem is that different exams have different grading sheets. Your job is to write a program to merge all the grading sheets into one. 
Input Specification: 
Each input file contains one test case. For each case, the first line gives three positive integers: P , the number of students having done the online programming assignments; M, the number of students on the mid-term list; and N, the number of students on the final exam list. All the numbers are no more than 10,000.
Then three blocks follow. The first block contains P online programming scores Gp's; the second one contains M mid-term scores Gmid-term's; and the last one contains N final exam scores Gfinal's. Each score occupies a line with the format: StudentID Score, where StudentID is a string of no more than 20 English letters and digits, and Score is a nonnegative integer (the maximum score of the online programming is 900, and that of the mid-term and final exams is 100).
Output Specification: 
For each case, print the list of students who are qualified for certificates. Each student occupies a line with the format: 
StudentID Gp Gmid-term Gfinal G 
If some score does not exist, output "-1" instead. The output must be sorted in descending order of their final grades (G must be rounded up to an integer). If there is a tie, output in ascending order of their StudentID's. It is guaranteed that the StudentID's are all distinct, and there is at least one qualified student.
Sample Input:
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
Sample Output:
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
map<string,int> mp;
struct node{
	char name[25];
	int online;
	int mid;
	int final;
	double score;
}students[10005];
bool cmp(node a,node b)
{
	if(a.score==b.score)
		return strcmp(a.name,b.name)<0;
	else
		return a.score>b.score;
}
int main()
{
	memset(students,-1,sizeof(students));
	int p,m,n,x;
	scanf("%d %d %d",&p,&m,&n);
	char s[25];
	for(int i=0;i<p;i++)
	{
		scanf("%s",s);
		scanf("%d",&x);
		if(x>=200)
		{
			mp[s]=i;
			strcpy(students[i].name,s);
			students[i].online=x;
		}
	}
	for(int i=0;i<m;i++)
	{
		scanf("%s %d",s,&x);
		if(mp.find(s)!=mp.end())
		{
			students[mp[s]].mid=x;
		}
	}
	for(int i=0;i<n;i++)
	{
		scanf("%s %d",s,&x);
		if(mp.find(s)!=mp.end())
		{
			students[mp[s]].final=x;
		}
	}
	for(int i=0;i<p;i++)
	{
		if(students[i].final>students[i].mid)
		{
			students[i].score=students[i].final;
		}
		else
		{
			students[i].score=round(students[i].mid*0.4+students[i].final*0.6);
		}
	}
	sort(students,students+p,cmp);
	for(int i=0;i<p;i++)
	{
		if(students[i].score<60)
			break;
		printf("%s %d %d %d %.0f\n",students[i].name,students[i].online,students[i].mid,students[i].final,students[i].score);
	}
	return 0;
 } 
