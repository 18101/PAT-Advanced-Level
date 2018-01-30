/*1093. Count PAT's (25)
The string APPAPT contains two PAT's as substrings. The first one is formed by the 2nd, the 4th, and the 6th characters, and the second one is formed by the 3rd, the 4th, and the 6th characters. 
Now given any string, you are supposed to tell the number of PAT's contained in the string.
Input Specification: 
Each input file contains one test case. For each case, there is only one line giving a string of no more than 105 characters containing only P, A, or T. 
Output Specification: 
For each test case, print in one line the number of PAT's contained in the string. Since the result may be a huge number, you only have to output the result moded by 1000000007. 
Sample Input:
APPAPT
Sample Output:
2
*/
#include <iostream>
#include <cstdio> 
#include <cstring>
using namespace std;
int p[100005],t[100005];
int main()
{
	memset(p,0,sizeof(p));
	memset(t,0,sizeof(t));
	long long ans=0;
	string s;
	cin>>s;
	p[0]=0;
	for(int i=1;i<s.length();i++)
	{
		p[i]=p[i-1];
		if(s[i-1]=='P')
			p[i]++;	
	}
	t[s.length()-1]=0;
	for(int i=s.length()-2;i>=0;i--)
	{
		t[i]=t[i+1];
		if(s[i+1]=='T')
			t[i]++;
		if(s[i]=='A')
		{
			ans=ans+p[i]*t[i]%1000000007;
		}
	}
	printf("%lld",ans%1000000007);
	return 0;
}
