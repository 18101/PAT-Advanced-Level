/*1016. Phone Bills (25)
A long-distance telephone company charges its customers by the following rules:
Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.
Input Specification: 
Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.
The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day. 
The next line contains a positive number N (<= 1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word "on-line" or "off-line".
For each test case, all dates will be within a single month. Each "on-line" record is paired with the chronologically next record for the same customer provided it is an "off-line" record. Any "on-line" records that are not paired with an "off-line" record are ignored, as are "off-line" records not paired with an "on-line" record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.
Output Specification: 
For each test case, you must print a phone bill for each customer. 
Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.
Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct call{
  char name[21];
  int time[3];
  int ttime;
  bool line;
}ncall[1005];
int times[25]; 
bool cmp(call a,call b)
{
  if(!strcmp(a.name,b.name))
  {
    if(a.ttime==b.ttime)
      return b.line;
    return (a.ttime<b.ttime);
  }
  else
    return (strcmp(a.name,b.name)<0);
}
int Getmm(int a,int oneday)
{
  int money,m1,m2;
  m1=times[ncall[a].time[1]]*ncall[a].time[2]+oneday*ncall[a].time[0];
  for(int i=0;i<ncall[a].time[1];i++)
  {
    m1+=times[i]*60;
  }
  m2=times[ncall[a+1].time[1]]*ncall[a+1].time[2]+oneday*ncall[a+1].time[0];
  for(int i=0;i<ncall[a+1].time[1];i++)
  {
    m2+=times[i]*60;
  }
  return m2-m1;
}
int main()
{
  int n,month,oneday=0;
  for(int i=0;i<24;i++)
  {
    scanf("%d",&times[i]);
    oneday+=times[i];
  }
  char online[8]="on-line";
  char whichline[9];
  oneday*=60;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%s %d:%d:%d:%d %s",ncall[i].name,&month,&ncall[i].time[0],&ncall[i].time[1],&ncall[i].time[2],whichline);
    ncall[i].ttime=ncall[i].time[0]*1440+ncall[i].time[1]*60+ncall[i].time[2];
    if(strcmp(whichline,online))
    {
      ncall[i].line=false;
    }
    else
      ncall[i].line=true;
  }
  sort(ncall,ncall+n,cmp);
  int u=0,mm=0,tam=0;
  bool ff=false;
  for(int i=0;i<n;i++)
  {
    if((strcmp(ncall[i].name,ncall[i+1].name)))
    {
      if(ff)
      {
        printf("Total amount: $%.2f\n",tam/100.0);
        tam=0;
        ff=false;
      }
      continue;
    }
    if(ncall[i].line&&(!ncall[i+1].line))
    {
      if(!ff)
      {
        ff=true;
        printf("%s %02d\n",ncall[i].name,month);
      }
      printf("%02d:%02d:%02d %02d:%02d:%02d %d ",ncall[i].time[0],ncall[i].time[1],ncall[i].time[2],ncall[i+1].time[0],ncall[i+1].time[1],ncall[i+1].time[2],ncall[i+1].ttime-ncall[i].ttime);
      mm=Getmm(i,oneday);
      printf("$%.2f\n",mm/100.0);
      tam+=mm;
    }
  }
  return 0;
}
