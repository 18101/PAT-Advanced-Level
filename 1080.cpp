/*1080. Graduate Admission (30)
It is said that in 2013, there were about 100 graduate schools ready to proceed over 40,000 applications in Zhejiang Province. It would help a lot if you could write a program to automate the admission procedure.
Each applicant will have to provide two grades: the national entrance exam grade GE, and the interview grade GI. The final grade of an applicant is (GE + GI) / 2. The admission rules are:
The applicants are ranked according to their final grades, and will be admitted one by one from the top of the rank list. 
If there is a tied final grade, the applicants will be ranked according to their national entrance exam grade GE. If still tied, their ranks must be the same. 
Each applicant may have K choices and the admission will be done according to his/her choices: if according to the rank list, it is one's turn to be admitted; and if the quota of one's most preferred shcool is not exceeded, then one will be admitted to this school, or one's other choices will be considered one by one in order. If one gets rejected by all of preferred schools, then this unfortunate applicant will be rejected. 
If there is a tied rank, and if the corresponding applicants are applying to the same school, then that school must admit all the applicants with the same rank, even if its quota will be exceeded. 
Input Specification: 
Each input file contains one test case. Each case starts with a line containing three positive integers: N (<=40,000), the total number of applicants; M (<=100), the total number of graduate schools; and K (<=5), the number of choices an applicant may have.
In the next line, separated by a space, there are M positive integers. The i-th integer is the quota of the i-th graduate school respectively.
Then N lines follow, each contains 2+K integers separated by a space. The first 2 integers are the applicant's GE and GI, respectively. The next K integers represent the preferred schools. For the sake of simplicity, we assume that the schools are numbered from 0 to M-1, and the applicants are numbered from 0 to N-1.
Output Specification: 
For each test case you should output the admission results for all the graduate schools. The results of each school must occupy a line, which contains the applicants' numbers that school admits. The numbers must be in increasing order and be separated by a space. There must be no extra space at the end of each line. If no applicant is admitted by a school, you must output an empty line correspondingly.
Sample Input:
11 6 3
2 1 2 2 2 3
100 100 0 1 2
60 60 2 3 5
100 90 0 3 4
90 100 1 2 0
90 90 5 1 3
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4
Sample Output:
0 10
3
5 6 7
2 8

1 4
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int quota[100];
struct node{
  int id;
  int ge;
  int gi;
  int total;
  int choice[5];
  int rank;
}st[40000];
bool cmp(node a,node b)
{
  if(a.total==b.total)
    return a.ge>b.ge;
  return a.total>b.total;
}
bool cmp2(int a,int b)
{
	return st[a].id<st[b].id;
}
int main()
{
  int n,m,k;
  vector<int> v[100];
  scanf("%d %d %d",&n,&m,&k);
  for(int i=0;i<m;i++)
  {
    scanf("%d",&quota[i]);
  }
  for(int i=0;i<n;i++)
  {
    st[i].id=i;
    scanf("%d %d",&st[i].ge,&st[i].gi);
    st[i].total=st[i].ge+st[i].gi;
    for(int j=0;j<k;j++)
    {
      scanf("%d",&st[i].choice[j]);
    }
  }
  sort(st,st+n,cmp);
  st[0].rank=1;
  for(int i=1;i<n;i++)
  {
    if(st[i].total==st[i-1].total&&st[i].ge==st[i-1].ge)
      st[i].rank=st[i-1].rank;
    else
      st[i].rank=i+1;
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<k;j++)
    {
      if(quota[st[i].choice[j]]>0||st[i].rank==st[v[st[i].choice[j]][v[st[i].choice[j]].size()-1]].rank)
      {
        v[st[i].choice[j]].push_back(i);
        quota[st[i].choice[j]]--;
        break;
      }
    }
  }
  for(int i=0;i<m;i++)
  {
    if(!v[i].size())
      printf("\n");
    else
    {
      sort(v[i].begin(),v[i].end(),cmp2);
      printf("%d",st[v[i][0]].id);
      for(int j=1;j<v[i].size();j++)
      {
        printf(" %d",st[v[i][j]].id);
      }
      printf("\n");
    }
  }
  return 0;
 } 
