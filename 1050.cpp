/*1050. String Subtraction (20)
Given two strings S1 and S2, S = S1 - S2 is defined to be the remaining string after taking all the characters in S2 from S1. Your task is simply to calculate S1 - S2 for any given strings. However, it might not be that simple to do it fast.
Input Specification: 
Each input file contains one test case. Each case consists of two lines which gives S1 and S2, respectively. The string lengths of both strings are no more than 104. It is guaranteed that all the characters are visible ASCII codes and white space, and a new line character signals the end of a string.
Output Specification: 
For each test case, print S1 - S2 in one line. 
Sample Input:
They are students.
aeiou
Sample Output:
Thy r stdnts.
*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	bool flag;
	string a;
	char b[10005];
	string ascii;
	int k=0;
	getline(cin,a);
	getline(cin,ascii);
	for(int i=0;i<a.length();i++)
	{
		flag=true;
		for(int j=0;j<ascii.length();j++)
		{
			if(a[i]==ascii[j])
			{
				flag=false;
				break;
			}
		}
		if(flag)
			b[k++]=a[i];
	}
	b[k]='\0';
	cout<<b;
	return 0;
 } 
