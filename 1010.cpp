/*1010. Radix (25)
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number. 
Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.
Input Specification: 
Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
N1 N2 tag radix
Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2. 
Output Specification: 
For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest possible radix. 
Sample Input 1:
6 110 1 10
Sample Output 1:
2
Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
char number[37]="0123456789abcdefghijklmnopqrstuvwxyz";
long long inf=(1LL<<63)-1; 
map<char,int> mp;
long long stoi(char s[],long long radix)
{
	long long d=0;
	for(int i=0;i<strlen(s);i++)
	{
		d*=radix;
		d+=mp[s[i]];
		if(d<0||d>inf)
			return -1;
	}
	return d;
 } 
long long binarySearch(int left,long long right,char s2[],long long decinum)
{
	while(left<=right)
	{
		long long mid=(left+right)/2;
		long long ss=stoi(s2,mid);
		if(ss==decinum)
		{
			if(left==right)
				return mid;
			return binarySearch(left,mid,s2,decinum);
		}
		else if(ss>decinum||ss==-1)
		{
			return binarySearch(left,mid-1,s2,decinum);
		}
		else
			return binarySearch(mid+1,right,s2,decinum);
	}
	return -1;
}
long long max(long long a,int b)
{
	return (a>b)?a:b;
}
void Get(char s1[],int radix,char s2[])
{
	long long decinum=0;
	decinum=stoi(s1,radix);
	char minr='0';
	for(int i=0;i<strlen(s2);i++)
	{
		if(s2[i]>minr)
			minr=s2[i];
	}
	int minradix=mp[minr]+1;
	int left=minradix;
	long long right=max(decinum,minradix);
	long long x=binarySearch(left,right,s2,decinum);
	if(x==-1)
		printf("Impossible");
	else
		printf("%lld",x);
}

int main()
{
	for(int i=0;i<36;i++)
	{
		mp[number[i]]=i;
	}
 	int tag,radix;
 	char s1[12],s2[12];
 	scanf("%s %s %d %d",s1,s2,&tag,&radix);
 	if(tag==1)
 		Get(s1,radix,s2);
 	else
 		Get(s2,radix,s1);
	return 0;
}
