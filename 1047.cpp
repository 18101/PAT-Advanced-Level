/*1047. Student List for Course (25)
Zhejiang University has 40000 students and provides 2500 courses. Now given the registered course list of each student, you are supposed to output the student name lists of all the courses.
Input Specification: 
Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=40000), the total number of students, and K (<=2500), the total number of courses. Then N lines follow, each contains a student's name (3 capital English letters plus a one-digit number), a positive number C (<=20) which is the number of courses that this student has registered, and then followed by C course numbers. For the sake of simplicity, the courses are numbered from 1 to K.
Output Specification: 
For each test case, print the student name lists of all the courses in increasing order of the course numbers. For each course, first print in one line the course number and the number of registered students, separated by a space. Then output the students' names in alphabetical order. Each name occupies a line.
Sample Input:
10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5
Sample Output:
1 4
ANN0
BOB5
JAY9
LOR6
2 7
ANN0
BOB5
FRA8
JAY9
JOE4
KAT3
LOR6
3 1
BOB5
4 7
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
5 9
AMY7
ANN0
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
char name[40010][5];
bool cmp(int a,int b)
{
	return strcmp(name[a],name[b])<0;
}
int main()
{
	int n,m,k,c,na=0;
	scanf("%d %d",&n,&m);
	vector<vector<int> > v(m+1);
	for(int i=0;i<n;i++)
	{
		scanf("%s %d",name[na],&k);
		for(int j=0;j<k;j++)
		{
			scanf("%d",&c);
			v[c].push_back(na);
		}
		na++;
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d %d\n",i,v[i].size());
		sort(v[i].begin(),v[i].end(),cmp);
		for(vector<int>::iterator it=v[i].begin();it!=v[i].end();it++)
		{
			printf("%s\n",name[*it]);
		}
	}
	return 0;
 } 