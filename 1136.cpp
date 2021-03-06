/*1136. A Delayed Palindrome (20)
Consider a positive integer N written in standard notation with k+1 digits ai as ak...a1a0 with 0 <= ai < 10 for all i and ak > 0. Then N is palindromic if and only if ai = ak-i for all i. Zero is written 0 and is also palindromic by definition. 
Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. Such number is called a delayed palindrome. (Quoted from https://en.wikipedia.org/wiki/Palindromic_number) 
Given any positive integer, you are supposed to find its paired palindromic number. 
Input Specification: 
Each input file contains one test case which gives a positive integer no more than 1000 digits.
Output Specification: 
For each test case, print line by line the process of finding the palindromic number. The format of each line is the following:
A + B = C
where A is the original number, B is the reversed A, and C is their sum. A starts being the input number, and this process ends until C becomes a palindromic number -- in this case we print in the last line "C is a palindromic number."; or if a palindromic number cannot be found in 10 iterations, print "Not found in 10 iterations." instead. 
Sample Input 1:
97152
Sample Output 1:
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.
Sample Input 2:
196
Sample Output 2:
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string Add(string s1,string s2)
{
	int a=s1.length();
	string ss="";
	int flag=0;
	for(int i=s1.length()-1;i>=0;i--)
	{
		int sum=s1[i]-'0'+s2[i]-'0'+flag;
		if(sum<10)
		{
			flag=0;
			char c='0'+sum;
			ss=c+ss;
		}
		else
		{
			sum-=10;
			char c='0'+sum;
			ss=c+ss;
			flag=1;
		}
	}
	if(flag)
		ss="1"+ss;
	return ss;
}
int main()
{
	string s1,s3,s4;
	cin>>s1;
	string s2=s1;
	reverse(s2.begin(),s2.end());
	if(s1==s2)
	{
		cout<<s1<<" is a palindromic number.";
	}
	else
	{
		bool flag=false;
		for(int i=0;i<10;i++)
		{
			s3=Add(s1,s2);
			cout<<s1<<" + "<<s2<<" = "<<s3<<"\n";
			s4=s3;
			reverse(s4.begin(),s4.end());
			if(s3==s4)
			{
				flag=true;
				cout<<s3<<" is a palindromic number.";
				return 0;
			}
			else
			{
				s1=s3;
				s2=s4;
			}
		}
		if(!flag)
		{
			cout<<"Not found in 10 iterations.";
		}
	}
	return 0;
 } 
