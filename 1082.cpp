/*1082. Read Number in Chinese (25)
Given an integer with no more than 9 digits, you are supposed to read it in the traditional Chinese way. Output "Fu" first if it is negative. For example, -123456789 is read as "Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu". Note: zero ("ling") must be handled correctly according to the Chinese tradition. For example, 100800 is "yi Shi Wan ling ba Bai".
Input Specification: 
Each input file contains one test case, which gives an integer with no more than 9 digits.
Output Specification: 
For each test case, print in a line the Chinese way of reading the number. The characters are separated by a space and there must be no extra space at the end of the line.
Sample Input 1:
-123456789
Sample Output 1:
Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
Sample Input 2:
100800
Sample Output 2:
yi Shi Wan ling ba Bai
*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string str[12]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string szero[5]={"z","0\0","00","000","0000"};
string sq[5]={"",""," Shi"," Bai"," Qian"};
string Get(string s,string ans)
{
	for(int i=4;i>0;i--)
	{
		if(s.length()==i)
		{
			if(s[0]=='0')
			{
				if(s==szero[i])
				{
					return ans;
				}
				else
				{
					ans+=" ling";
				}
				while(s[0]=='0')
				{
					s.erase(s.begin());
				}
			}
			else
			{
				ans+=" ";
				ans+=str[s[0]-'0'];
				ans+=sq[i];
				s.erase(s.begin());
			}
		}
	}
	return ans;
}
int main()
{
	string s,ans="",sub;
	bool flag=false;
	cin>>s;
	if(s=="0"||s=="-0")
	{
		cout<<"ling";
		return 0;
	}
	if(s[0]=='-')
	{
		s.erase(s.begin());
		flag=true;
	}
	while(s.length()>1&&s[0]==0)
	{
		s.erase(s.begin());
	}
	if(s.length()==9)
	{
		
		ans+=' ';
		ans+=str[s[0]-'0'];
		ans+=" Yi";
		s.erase(s.begin());
	}
	if(s.length()>4)
	{
		sub=s.substr(0,s.length()-4);
		ans=Get(sub,ans);
		while(s.length()>4)
		{
			s.erase(s.begin());
		}
		ans+=" Wan";
	}
	ans=Get(s,ans);
	while(ans.length()&&ans[0]==' ')
	{
		ans.erase(ans.begin());
	}
	if(flag)
	{
		ans="Fu "+ans;
	}
	cout<<ans; 
	return 0;
 } 
