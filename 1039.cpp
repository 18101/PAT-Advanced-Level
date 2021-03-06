/*1039. Course List for Student (25)
Zhejiang University has 40000 students and provides 2500 courses. Now given the student name lists of all the courses, you are supposed to output the registered course list for each student who comes for a query.
Input Specification: 
Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=40000), the number of students who look for their course lists, and K (<=2500), the total number of courses. Then the student name lists are given for the courses (numbered from 1 to K) in the following format: for each course i, first the course index i and the number of registered students Ni (<= 200) are given in a line. Then in the next line, Ni student names are given. A student name consists of 3 capital English letters plus a one-digit number. Finally the last line contains the N names of students who come for a query. All the names and numbers in a line are separated by a space.
Output Specification: 
For each test case, print your results in N lines. Each line corresponds to one student, in the following format: first print the student's name, then the total number of registered courses of that student, and finally the indices of the courses in increasing order. The query results must be printed in the same order as input. All the data in a line must be separated by a space, with no extra space at the end of the line. 
Sample Input:
11 5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9
*/
#include <iostream>
#include <cstdio> 
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[180000];
int Get(char a[])
{
	return (a[0]-'A')*6760+(a[1]-'A')*260+(a[2]-'A')*10+(a[3]-'0');
}
int main()
{
	int n,k,a,b;
	char name[5];
	scanf("%d %d",&n,&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d %d",&a,&b);
		for(int i=0;i<b;i++)
		{
			scanf("%s",name);
			v[Get(name)].push_back(a);
		}
	}
	int u;
	for(int i=0;i<n;i++)
	{
		scanf("%s",name);
		u=Get(name);
		printf("%s %d",name,v[u].size()); 
		sort(v[u].begin(),v[u].end());
		for(int j=0;j<v[u].size();j++)
		{
			printf(" %d",v[u][j]);
		}
		printf("\n");
	}
	return 0;
}
