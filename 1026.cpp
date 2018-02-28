/*1026. Table Tennis (30)
A table tennis club has N tables available to the public. The tables are numbered from 1 to N. For any pair of players, if there are some tables open when they arrive, they will be assigned to the available table with the smallest number. If all the tables are occupied, they will have to wait in a queue. It is assumed that every pair of players can play for at most 2 hours.
Your job is to count for everyone in queue their waiting time, and for each table the number of players it has served for the day.
One thing that makes this procedure a bit complicated is that the club reserves some tables for their VIP members. When a VIP table is open, the first VIP pair in the queue will have the priviledge to take it. However, if there is no VIP in the queue, the next pair of players can take it. On the other hand, if when it is the turn of a VIP pair, yet no VIP table is available, they can be assigned as any ordinary players.
Input Specification: 
Each input file contains one test case. For each case, the first line contains an integer N (<=10000) - the total number of pairs of players. Then N lines follow, each contains 2 times and a VIP tag: HH:MM:SS - the arriving time, P - the playing time in minutes of a pair of players, and tag - which is 1 if they hold a VIP card, or 0 if not. It is guaranteed that the arriving time is between 08:00:00 and 21:00:00 while the club is open. It is assumed that no two customers arrives at the same time. Following the players' info, there are 2 positive integers: K (<=100) - the number of tables, and M (< K) - the number of VIP tables. The last line contains M table numbers.
Output Specification: 
For each test case, first print the arriving time, serving time and the waiting time for each pair of players in the format shown by the sample. Then print in a line the number of players served by each table. Notice that the output must be listed in chronological order of the serving time. The waiting time must be rounded up to an integer minute(s). If one cannot get a table before the closing time, their information must NOT be printed.
Sample Input:
9
20:52:00 10 0
08:00:00 20 0
08:02:00 30 0
20:51:00 10 0
08:10:00 5 0
08:12:00 10 1
20:50:00 10 0
08:01:30 15 1
20:53:00 10 1
3 1
2
Sample Output:
08:00:00 08:00:00 0
08:01:30 08:01:30 0
08:02:00 08:02:00 0
08:12:00 08:16:30 5
08:10:00 08:20:00 10
20:50:00 20:50:00 0
20:51:00 20:51:00 0
20:52:00 20:52:00 0
3 3 2
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;
struct node{
  int atime;
  int ptime;
  int stime;
  bool bv;
  friend bool operator <(node a,node b)
  {
    return a.atime>b.atime;
  }
}waiting[10000];
struct nodetable{
  int finishtime;
  int countpeople;
  bool viptable;
}table[105];
bool cmp(node a,node b)
{
  return a.atime<b.atime;
}
bool cmp2(node a,node b)
{
  return a.stime<b.stime;
}
int main()
{
  int n,a,b,c,d,k,m;
  memset(waiting,0,sizeof(waiting));
  memset(table,0,sizeof(table));
  vector<node> vec;
  node tempnode;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%d:%d:%d %d %d",&a,&b,&c,&waiting[i].ptime,&d);
    if(waiting[i].ptime>120)
      waiting[i].ptime=7200;
    else
      waiting[i].ptime*=60;
    waiting[i].atime=a*3600+b*60+c;
    if(d)
    {
      waiting[i].bv=true;
    }
    else
    {
      waiting[i].bv=false;
    }
  }
  sort(waiting,waiting+n,cmp);
  scanf("%d %d",&k,&m);
  int vx;
  for(int i=1;i<=k;i++)
    table[i].finishtime=8*3600;
  for(int i=1;i<=m;i++)
  {
    scanf("%d",&vx);
    table[vx].viptable=true;
  }
/*  for(int i=1;i<=k;i++)
  {
    if(table[i].viptable)
    {
      printf("h%dh",i);
    }
  }*/
  int i=0,curtime=8*3600;
  priority_queue<node> qn,vipqn;
  priority_queue<int,vector<int>,greater<int> > qt,vipqt;
  while(true)
  {
    if(i>=n&&qn.empty()&&vipqn.empty())
      break;
    if(curtime>=21*3600)
      break;
    while(curtime>=waiting[i].atime&&i<n)
    {
      if(waiting[i].bv)
        vipqn.push(waiting[i]);
      else
        qn.push(waiting[i]);
      i++;
    }
    for(int j=1;j<=k;j++)
    {
      if(table[j].finishtime<=curtime)
      {
        if(table[j].viptable)
          vipqt.push(j);
        else
          qt.push(j);
      }
    }
    while(!vipqn.empty()&&!vipqt.empty())
    {
      tempnode=vipqn.top();
      vipqn.pop();
      int ta=vipqt.top();
      vipqt.pop();
      tempnode.stime=curtime;
      table[ta].countpeople++;
      //printf("h%dh",ta);
      table[ta].finishtime=curtime+tempnode.ptime;
      vec.push_back(tempnode);
    }
    while(!vipqn.empty())
    {
      qn.push(vipqn.top());
      vipqn.pop();
    }
    while(!vipqt.empty())
    {
      qt.push(vipqt.top());
      vipqt.pop();
    }
    while(!qn.empty()&&!qt.empty())
    {
      tempnode=qn.top();
      qn.pop();
      int ta=qt.top();
      qt.pop();
      tempnode.stime=curtime;
      table[ta].countpeople++;
      table[ta].finishtime=curtime+tempnode.ptime;
      vec.push_back(tempnode);
    }
    if(qn.empty())
    {
      curtime=waiting[i].atime;
      while(!qt.empty())
      {
        qt.pop();      
      }      
    }
    else
    {
      int mintime=24*3600+1;
      for(int j=1;j<=k;j++)
      {
        mintime=min(table[j].finishtime,mintime);
      }
      curtime=mintime;
      priority_queue<node> qtemp;
      while(!qn.empty())
      {
        tempnode=qn.top();
        if(tempnode.bv)
        {
          vipqn.push(tempnode);
        }
        else
          qtemp.push(tempnode);
        qn.pop();
      }
      qn=qtemp;
    }
  }
  sort(vec.begin(),vec.end(),cmp2);
  for(int i=0;i<vec.size();i++)
  {
    printf("%02d:%02d:%02d",vec[i].atime/3600,vec[i].atime/60%60,vec[i].atime%60);
    printf(" %02d:%02d:%02d",vec[i].stime/3600,vec[i].stime/60%60,vec[i].stime%60);
    printf(" %d\n",(vec[i].stime-vec[i].atime+30)/60);/////
  }
  for(int j=1;j<=k;j++)
  {
    if(j!=1)
      printf(" ");
    printf("%d",table[j].countpeople);
  }
  return 0;
}
