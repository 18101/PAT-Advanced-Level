/*1109. Group Photo (25)
Formation is very important when taking a group photo. Given the rules of forming K rows with N people as the following:
The number of people in each row must be N/K (round down to the nearest integer), with all the extra people (if any) standing in the last row; 
All the people in the rear row must be no shorter than anyone standing in the front rows; 
In each row, the tallest one stands at the central position (which is defined to be the position (m/2+1), where m is the total number of people in that row, and the division result must be rounded down to the nearest integer); 
In each row, other people must enter the row in non-increasing order of their heights, alternately taking their positions first to the right and then to the left of the tallest one (For example, given five people with their heights 190, 188, 186, 175, and 170, the final formation would be 175, 188, 190, 186, and 170. Here we assume that you are facing the group so your left-hand side is the right-hand side of the one at the central position.); 
When there are many people having the same height, they must be ordered in alphabetical (increasing) order of their names, and it is guaranteed that there is no duplication of names. 
Now given the information of a group of people, you are supposed to write a program to output their formation.
Input Specification: 
Each input file contains one test case. For each test case, the first line contains two positive integers N (<=10000), the total number of people, and K (<=10), the total number of rows. Then N lines follow, each gives the name of a person (no more than 8 English letters without space) and his/her height (an integer in [30, 300]).
Output Specification: 
For each case, print the formation -- that is, print the names of people in K lines. The names must be separated by exactly one space, but there must be no extra space at the end of each line. Note: since you are facing the group, people in the rear rows must be printed above the people in the front rows. 
Sample Input:
10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159
Sample Output:
Bob Tom Joe Nick
Ann Mike Eva
Tim Amy John
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
struct pp{
	char name[12];
	int height;
}people[10005];
bool cmp(pp a,pp b)
{
	if(a.height==b.height)
		return strcmp(a.name,b.name)<0;
	return a.height>b.height;
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%s %d",people[i].name,&people[i].height);
	}
	sort(people,people+n,cmp);
	int each=n/k;
	int last=n/k+n%k;
	int head=0;
	int kk;
	for(int i=0;i<k;i++)
	{
		bool flag=false;
		if(!i)
		{
			kk=last/2-1;
		}
		else
			kk=each/2-1;
		for(int j=kk;j>=0;j--)
		{
			if(flag)
				printf(" ");
			else
				flag=true;
			printf("%s",people[head+1+2*j].name);
		}
		if(flag)
			printf(" ");
		else
			flag=true;
		printf("%s",people[head].name);
		if(i==0&&!(last%2))
		{
			kk--;
		}
		else if(i!=0&&!(each%2))
		{
			kk--;
		}
		for(int j=1;j<=kk+1;j++)
		{
			if(flag)
				printf(" ");
			else
				flag=true;
			printf("%s",people[head+2*j].name);
		}
		printf("\n");
		if(i==0)
			head+=last;
		else
			head+=each;
	}
	return 0;
}
