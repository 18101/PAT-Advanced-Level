/*1100. Mars Numbers (20)
People on Mars count their numbers with base 13:
Zero on Earth is called "tret" on Mars. 
The numbers 1 to 12 on Earch is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars, respectively. 
For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively. 
For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov" on Mars corresponds to 115 on Earth. In order to help communication between people from these two planets, you are supposed to write a program for mutual translation between Earth and Mars number systems. 
Input Specification: 
Each input file contains one test case. For each case, the first line contains a positive integer N (< 100). Then N lines follow, each contains a number in [0, 169), given either in the form of an Earth number, or that of Mars.
Output Specification: 
For each number, print in a line the corresponding number in the other language.
Sample Input:
4
29
5
elo nov
tam
Sample Output:
hel mar
may
115
13
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

string Mars1[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string Mars2[13]={"","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
map<string,int> mp1,mp2;
void EtoM(char* s)
{
	int a,a1,a2;
	a=atoi(s);
	a1=a/13;
	a2=a%13;
	cout<<Mars2[a1];
	if(!a1&&!a2)
		cout<<"tret";
	else if(a2)
	{
		if(a1)
			cout<<' ';
		cout<<Mars1[a2];
	}
}
void MtoE(char* s)
{
	int j;
	char a1[5],a2[5];
	memset(a1,0,sizeof(a1));
	memset(a2,0,sizeof(a2));
	if(strlen(s)<=4)
	{
		if(mp2[s])
			cout<<mp2[s]*13;
		else
			cout<<mp1[s];
		return;
	}
	for(int i=0;i<3;i++)
	{
		a1[i]=s[i];
	}
	for(int i=4;s[i]!='\0';i++)
	{
		a2[i-4]=s[i];
	}
	cout<<mp2[a1]*13+mp1[a2];
}
int main()
{
	int n;
	for(int i=0;i<13;i++)
	{
		mp1[Mars1[i]]=i;
		mp2[Mars2[i]]=i;
	}
	char s[10];
	cin>>n;
	getchar();
	while(n)
	{
	memset(s,0,sizeof(s));
	gets(s);
	if(s[0]>='0'&&s[0]<='9')
		EtoM(s);
	else
		MtoE(s);
	cout<<'\n';
	n--;
	}
	return 0;
 } 
