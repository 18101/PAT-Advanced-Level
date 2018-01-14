/*
1077. Kuchiguse (20)
The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker's personality. Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:
Itai nyan~ (It hurts, nyan~)
Ninjin wa iyada nyan~ (I hate carrots, nyan~)
Now given a few lines spoken by the same character, can you find her Kuchiguse?
Input Specification: 
Each input file contains one test case. For each case, the first line is an integer N (2<=N<=100). Following are N file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.
Output Specification: 
For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all N lines. If there is no such suffix, write "nai".
Sample Input 1:
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~
Sample Output 1:
nyan~
Sample Input 2:
3
Itai!
Ninjinnwaiyada T_T
T_T
Sample Output 2:
nai
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
	int n,l,minl=256;
	bool flag=true;
	char c;
	cin>>n;
	vector<string> sv;
	getchar();
	for(int i=0;i<n;i++)
	{
		string s,u;
		getline(cin,s);
		l=s.length();
		if(l<minl)
			minl=l;
		sv.push_back(s);
	}
	int k=1;
	l=sv[0].size();
	while(flag)
	{
		c=sv[0][l-k];
		for(int i=1;i<n;i++)
		{
			if(sv[i][sv[i].size()-k]!=c)
			{
				flag=false;
				break;	
			}
		}
		k++;
		if(k==minl+2)
			break;
	}
	k--;
	if(k==1)
		cout<<"nai";
	else
	{
		for(int i=k-1;i>=1;i--)
		{
			cout<<sv[0][l-i];
		}
	}
	return 0;
 } 
