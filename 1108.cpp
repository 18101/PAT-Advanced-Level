/*1108. Finding Average (20)
The basic task is simple: given N real numbers, you are supposed to calculate their average. But what makes it complicated is that some of the input numbers might not be legal. A "legal" input is a real number in [-1000, 1000] and is accurate up to no more than 2 decimal places. When you calculate the average, those illegal numbers must not be counted in.
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<=100). Then N numbers are given in the next line, separated by one space. 
Output Specification: 
For each illegal input number, print in a line "ERROR: X is not a legal number" where X is the input. Then finally print in a line the result: "The average of K numbers is Y" where K is the number of legal inputs and Y is their average, accurate to 2 decimal places. In case the average cannot be calculated, output "Undefined" instead of Y. In case K is only 1, output "The average of 1 number is Y" instead. 
Sample Input 1:
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
Sample Output 1:
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
Sample Input 2:
2
aaa -9999
Sample Output 2:
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	int n,cnt=0;
	string s;
	double temp,sum=0,average;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		bool flag=true;
		cin>>s;
		int dot=-1;
		for(int j=0;j<s.length();j++)
		{
			if(s[j]=='.')
			{
				dot=j;
				break;
			}
		}
		if(dot==0||(dot==1)&&(s[0]=='-'))
			flag=false;
		else if(dot!=-1)
		{
			int begin=0;
			if(s[0]=='-'&&s[1]!='.')
			{
				begin=1;
			}
			for(int j=begin;j<dot;j++)
			{
				if(!isdigit(s[j]))
				{
					flag=false;
					break;
				}
			}
			if(flag)
			{
				for(int j=dot+1;j<s.length();j++)
				{
					if(!isdigit(s[j]))
					{
						flag=false;
						break;
					}
				}
			}
		}
		if(dot==-1)
		{
			int begin=0;
			if(s[0]=='-')
				begin=1;
			for(int j=begin;j<s.length();j++)
			{
				if(!isdigit(s[j]))
				{
					flag=false;
					break;
				}
			}
		}
		if(!flag)
			cout<<"ERROR: "<<s<<" is not a legal number\n";
		else
		{
			sscanf(s.c_str(),"%lf",&temp);
			if(temp<-1000||temp>1000)
			{
				flag=false;
			}
			else
			{
				if(dot!=-1)
				{
	/*				if((s[0]!='-')&&(dot+2>=s.length()-1))
					{
						flag=false;
					}
					else if(dot+2>s.length())
					{
						flag=false;
					}*/
					if(s.length()>dot+3)
						flag=false;
				}
			}
			if(!flag)
				cout<<"ERROR: "<<s<<" is not a legal number\n";
			else
			{
				cnt++;
				sum+=temp;
			}
		}
	}
	if(!cnt)
		cout<<"The average of 0 numbers is Undefined";
	else
	{
		cout<<"The average of ";
		if(cnt==1)
			cout<<"1 number is ";
		else
			cout<<cnt<<" numbers is ";
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum/cnt;
	}
	return 0;
 } 
