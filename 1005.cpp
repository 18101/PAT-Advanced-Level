/*
1005. Spell It Right (20)
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English. 
Input Specification: 
Each input file contains one test case. Each case occupies one line which contains an N (<= 10100). 
Output Specification: 
For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line. 
Sample Input:
12345
Sample Output:
one five
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std; 

int main(int argc, char** argv) {
	string answer[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	string a;
	string s;
	vector<int> v;
	int sum=0;
	cin>>a;
	for(int i=0;i<a.length();i++)
	{
		sum+=(a[i]-'0');
	}
	while(sum!=0)
	{
		v.push_back(sum%10);
		sum/=10;
	}
	int len=v.size();
	if(len==0)
		cout<<"zero";
	else
	{
		s=answer[v[len-1]];
		cout<<s;
		for(int i=len-2;i>=0;i--)
		{
			s=answer[v[i]];
			cout<<" "<<s;
		}
	 } 
	return 0;
}

