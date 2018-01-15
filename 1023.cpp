/*1023. Have Fun with Numbers (20)
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again! 
Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.
Input Specification: 
Each input file contains one test case. Each case contains one positive integer with no more than 20 digits.
Output Specification: 
For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.
Sample Input:
1234567899
Sample Output:
Yes
2469135798
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
using namespace std;
int main()
{
	int mp1[10],mp2[10];
	char s1[21],s2[22];
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	memset(mp1,0,sizeof(mp1));
	memset(mp2,0,sizeof(mp2));
	bool flag=false,judge=true;
	cin>>s1;
	for(int i=0;i<strlen(s1);i++)
	{
		mp1[s1[i]-'0']++;
	}
	for(int i=strlen(s1)-1;i>=0;i--)
	{
		if(flag)
			s2[i]='1';
		else
			s2[i]='0';
		int a=(s1[i]-'0')*2;
		if(a>=10)
		{
			a=a-10;
			flag=true;
		}
		else
			flag=false;
		s2[i]+=a;
	}
	s2[strlen(s1)]='\0';
	if(flag)
		mp2[1]++;
	for(int i=0;i<strlen(s1);i++)
	{
		mp2[s2[i]-'0']++;
	}
	for(int i=0;i<10;i++)
	{
		if(mp1[i]!=mp2[i])
		{
			judge=false;
			break;
		}	
	}
	if(judge)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	if(flag)
		cout<<1;
	cout<<s2;
	return 0;
 } 
