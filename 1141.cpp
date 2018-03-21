/*1141. PAT Ranking of Institutions (25)
After each PAT, the PAT Center will announce the ranking of institutions based on their students' performances. Now you are asked to generate the ranklist. 
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<=105), which is the number of testees. Then N lines follow, each gives the information of a testee in the following format:
ID Score School 
where "ID" is a string of 6 characters with the first one representing the test level: "B" stands for the basic level, "A" the advanced level and "T" the top level; "Score" is an integer in [0, 100]; and "School" is the institution code which is a string of no more than 6 English letters (case insensitive). Note: it is guaranteed that "ID" is unique for each testee. 
Output Specification: 
For each case, first print in a line the total number of institutions. Then output the ranklist of institutions in nondecreasing order of their ranks in the following format:
Rank School TWS Ns 
where "Rank" is the rank (start from 1) of the institution; "School" is the institution code (all in lower case); "TWS" is the total weighted score which is defined to be the integer part of "ScoreB/1.5 + ScoreA + ScoreT*1.5", where "ScoreX" is the total score of the testees belong to this institution on level X; and "Ns" is the total number of testees who belong to this institution. 
The institutions are ranked according to their TWS. If there is a tie, the institutions are supposed to have the same rank, and they shall be printed in ascending order of Ns. If there is still a tie, they shall be printed in alphabetical order of their codes. 
Sample Input:
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu
Sample Output:
5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstring>
#include <string>
using namespace std;
struct node{
	char sch[8];
	int tws;
	int ss[3];
	int ns;
	int rank;
}S[100005];
map<string,int> mp;
void GetLower(char a[8])
{
	int b=strlen(a);
	for(int i=0;i<b;i++)
	{
		if(a[i]<='Z'&&a[i]>='A')
			a[i]=a[i]-'A'+'a';
	}
}
bool cmp(node a,node b)
{
	if(a.tws==b.tws)
	{
		if(a.ns==b.ns)
		{
			return strcmp(a.sch,b.sch)<0;
		}
		return a.ns<b.ns;
	}
	return a.tws>b.tws;
}
int main()
{
	int n;
	memset(S,0,sizeof(S));
	int score;
	int count=0;
	char id[8],school[8];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s %d %s",id,&score,school);
		GetLower(school);
		if(mp.find(school)==mp.end())
		{
			for(int j=0;j<8;j++)
			{
				S[count].sch[j]=school[j];
			}
			S[count].ns=1;
			if(id[0]=='B')
			{
				S[count].ss[0]=score;
			}
			else if(id[0]=='A')
			{
				S[count].ss[1]=score;
			}
			else
			{
				S[count].ss[2]=score;
			}
			mp[school]=count;
			count++;
		}
		else
		{
			int u=mp[school];
			S[u].ns++;
			if(id[0]=='B')
			{
				S[u].ss[0]+=score;
			}
			else if(id[0]=='A')
			{
				S[u].ss[1]+=score;
			}
			else
			{
				S[u].ss[2]+=score;
			}
		}
	}
	for(int i=0;i<count;i++)
	{
		S[i].tws=(int)(S[i].ss[0]/1.5+S[i].ss[1]+S[i].ss[2]*1.5);
	}
	sort(S,S+count,cmp);
	S[0].rank=1;
	for(int i=1;i<count;i++)
	{
		if(S[i].tws==S[i-1].tws)
		{
			S[i].rank=S[i-1].rank;
		}
		else
			S[i].rank=i+1;
	}
	printf("%d\n",count);
	for(int i=0;i<count;i++)
	{
		printf("%d %s %d %d\n",S[i].rank,S[i].sch,S[i].tws,S[i].ns);
	}
	return 0;
}
