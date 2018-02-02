/*1040. Longest Symmetric String (25)
Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given "Is PAT&TAP symmetric?", the longest symmetric sub-string is "s PAT&TAP s", hence you must output 11.
Input Specification: 
Each input file contains one test case which gives a non-empty string of length no more than 1000.
Output Specification: 
For each test case, simply print the maximum length in a line.
Sample Input:
Is PAT&TAP symmetric?
Sample Output:
11
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int maxl=0,maxn;
	int a=s.length()-1-maxl;
	for(int i=1;i<a;i++)
	{
		int k=1;
		while(i>=k&&(i<=s.length()-k-1)&&s[i+k]==s[i-k])
		{
			if(k>maxl)
			{
				maxl=k;
				a=s.length()-1-maxl;
			}
			k++;
		}
	}
	maxn=maxl*2+1;
	maxl=0;
	for(int i=0;i<a;i++)
	{
		int k =0;
		while(i>=k&&i+k+2<=s.length()&&s[i-k]==s[i+k+1])
		{
			k++;
			if(k>maxl)
			{
				maxl=k;
				a=s.length()-1-maxl;
			}
		}
	}
	int maxn2=maxl*2;
	if(maxn2>maxn)
		maxn=maxn2;
	printf("%d",maxn);
	return 0;
 } 
