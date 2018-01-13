/*1073. Scientific Notation (20)
Scientific notation is the way that scientists easily handle very large numbers or very small numbers. The notation matches the regular expression [+-][1-9]"."[0-9]+E[+-][0-9]+ which means that the integer portion has exactly one digit, there is at least one digit in the fractional portion, and the number and its exponent's signs are always provided even when they are positive.
Now given a real number A in scientific notation, you are supposed to print A in the conventional notation while keeping all the significant figures.
Input Specification: 
Each input file contains one test case. For each case, there is one line containing the real number A in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999. 
Output Specification: 
For each test case, print in one line the input number A in the conventional notation, with all the significant figures kept, including trailing zeros,
Sample Input 1:
+1.23400E-03
Sample Output 1:
0.00123400
Sample Input 2:
-1.2E+10
Sample Output 2:
-12000000000
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int Getn(int e,string s1)
{
	int n=0,j;
	char s3[6];
	memset(s3,0,sizeof(s3));
	for(int i=e+1;s1[i]!='\0';i++)
	{
		s3[i-e-1]=s1[i];
		j=i;
	}
	s3[j-e]='\0';
	sscanf(s3,"%d",&n);
	return n;
}
int main()
{
	string s1;
	char s2[1000005];
	memset(s2,0,sizeof(s2));
	int k=0,e=0,n=0,l=0;
	cin>>s1;
	if(s1[0]=='-')
	{
		cout<<'-';
		k++;
	}
	for(int i=1;i<s1.length();i++)
	{
		if(s1[i]=='E')
		{
			e=i;
			break;
		}
	}
	n=Getn(e,s1);
	if(n==0)
	{
		for(int i=1;i<e;i++)
			cout<<s1[i];
	}
	else if(n<0)
	{
		n*=-1;
		cout<<"0.";
		for(int i=1;i<n;i++)
		{
			cout<<'0';
		}
		k+=n+1;
		cout<<s1[1];
		for(int i=3;i<e;i++)
			cout<<s1[i];
	}
	else
	{
		cout<<s1[1];
		l=e-3;
		if(n<=l)
		{
			for(int i=3;i<n+3;i++)
			{
				cout<<s1[i];
			}
			if(n!=l)
				cout<<'.';
			for(int i=n+2;i<l+2;i++)
			{
				cout<<s1[i+1];
			}
		}
		else
		{
			for(int i=3;i<l+3;i++)
			{
				cout<<s1[i];
			}
			for(int i=0;i<n-l;i++)
				cout<<'0';
		}
		
	}
	return 0;
}
