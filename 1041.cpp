
/*1041. Be Unique (20)
Being unique is so important to people on Mars that even their lottery is designed in a unique way. The rule of winning is simple: one bets on a number chosen from [1, 104]. The first one who bets on a unique number wins. For example, if there are 7 people betting on 5 31 5 88 67 88 17, then the second one who bets on 31 wins.
Input Specification: 
Each input file contains one test case. Each case contains a line which begins with a positive integer N (<=105) and then followed by N bets. The numbers are separated by a space.
Output Specification: 
For each test case, print the winning number in a line. If there is no winner, print "None" instead. 
Sample Input 1:
7 5 31 5 88 67 88 17
Sample Output 1:
31
Sample Input 2:
5 888 666 666 888 888
Sample Output 2:
None
*/
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	bool flag=true;
	int a[100005],count[10001];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
 	{
 		scanf("%d",&a[i]);
	 	count[a[i]]++;
	 }
	 for(int i=0;i<n;i++)
	 {
	 	if(count[a[i]]==1)
	 	{
	 		printf("%d",a[i]);
	 		flag=false;
	 		break;
		 }
	 }
	 if(flag)
	 	printf("None");
	return 0;
 } 
