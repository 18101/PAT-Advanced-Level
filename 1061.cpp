/*1061. Dating (20)
Sherlock Holmes received a note with some strange strings: "Let's date! 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm". It took him only a minute to figure out that those strange strings are actually referring to the coded time "Thursday 14:04" -- since the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter 'D', representing the 4th day in a week; the second common character is the 5th capital letter 'E', representing the 14th hour (hence the hours from 0 to 23 in a day are represented by the numbers from 0 to 9 and the capital letters from A to N, respectively); and the English letter shared by the last two strings is 's' at the 4th position, representing the 4th minute. Now given two pairs of strings, you are supposed to help Sherlock decode the dating time.
Input Specification: 
Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 characters without white space in 4 lines.
Output Specification: 
For each test case, print the decoded time in one line, in the format "DAY HH:MM", where "DAY" is a 3-character abbreviation for the days in a week -- that is, "MON" for Monday, "TUE" for Tuesday, "WED" for Wednesday, "THU" for Thursday, "FRI" for Friday, "SAT" for Saturday, and "SUN" for Sunday. It is guaranteed that the result is unique for each case.
Sample Input:
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
Sample Output:
THU 14:04
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
map<char,int> mp;
int main()
{
	map<char,string> mp;
	mp['A']="MON";
	mp['B']="TUE";
	mp['C']="WED";
	mp['D']="THU";
	mp['E']="FRI";
	mp['F']="SAT";
	mp['G']="SUN";
	char a[62],b[62],c[62],d[62];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	cin>>a>>b>>c>>d;
	bool judge1=false;
	int i=0;
	for(;i<strlen(a);i++)
	{
		if(a[i]==b[i]&&a[i]>='A'&&a[i]<='G')
		{
			cout<<mp[a[i]]<<' ';
			break;
		}
	}
	for(i++;i<strlen(a);i++)
	{
		if(a[i]==b[i])
		{
			if(a[i]>='0'&&a[i]<='9')
			{
				cout<<'0'<<a[i]<<':';
				break;
			}
			else if(a[i]>='A'&&a[i]<='N')
			{
				cout<<a[i]-'A'+10<<':';
				break;
			}
		}
	}
	for(i=0;i<strlen(c);i++)
	{
		if(c[i]==d[i]&&isalpha(c[i]))
		{
			if(i<10)
				cout<<'0'<<i;
			else
				cout<<i;
			break;
		}
	}
	return 0;
 } 
