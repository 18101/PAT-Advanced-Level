/*1069. The Black Hole of Numbers (20)
For any 4-digit integer except the ones with all the digits being the same, if we sort the digits in non-increasing order first, and then in non-decreasing order, a new number can be obtained by taking the second number from the first one. Repeat in this manner we will soon end up at the number 6174 -- the "black hole" of 4-digit numbers. This number is named Kaprekar Constant.
For example, start from 6767, we'll get:
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...
Given any 4-digit number, you are supposed to illustrate the way it gets into the black hole.
Input Specification: 
Each input file contains one test case which gives a positive integer N in the range (0, 10000).
Output Specification: 
If all the 4 digits of N are the same, print in one line the equation "N - N = 0000". Else print each step of calculation in a line until 6174 comes out as the difference. All the numbers must be printed as 4-digit numbers.
Sample Input 1:
6767
Sample Output 1:
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
Sample Input 2:
2222
Sample Output 2:
2222 - 2222 = 0000
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	char a[5];
	memset(a,0,sizeof(a));
	int begin,first,second,third;
	scanf("%d",&begin);
	sprintf(a,"%04d",begin);
	sort(a,a+4);
	sscanf(a,"%d",&second);
	sort(a,a+4,cmp);
	sscanf(a,"%d",&first);
	third=first-second;
	while(third!=6174&&third!=0)
	{
	printf("%04d - %04d = %04d\n",first,second,third);
	begin=third;
	sprintf(a,"%04d",third);
	sort(a,a+4);
	sscanf(a,"%d",&second);
	sort(a,a+4,cmp);
	sscanf(a,"%d",&first);
	third=first-second;	
	}
	printf("%04d - %04d = %04d\n",first,second,third);
	return 0;
 } 
