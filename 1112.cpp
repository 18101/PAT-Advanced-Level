/*1112. Stucked Keyboard (20)
On a broken keyboard, some of the keys are always stucked. So when you type some sentences, the characters corresponding to those keys will appear repeatedly on screen for k times.
Now given a resulting string on screen, you are supposed to list all the possible stucked keys, and the original string. 
Notice that there might be some characters that are typed repeatedly. The stucked key will always repeat output for a fixed k times whenever it is pressed. For example, when k=3, from the string "thiiis iiisss a teeeeeest" we know that the keys "i" and "e" might be stucked, but "s" is not even though it appears repeatedly sometimes. The original string could be "this isss a teest". 
Input Specification: 
Each input file contains one test case. For each case, the 1st line gives a positive integer k ( 1<k<=100 ) which is the output repeating times of a stucked key. The 2nd line contains the resulting string on screen, which consists of no more than 1000 characters from {a-z}, {0-9} and "_". It is guaranteed that the string is non-empty.
Output Specification: 
For each test case, print in one line the possible stucked keys, in the order of being detected. Make sure that each key is printed once only. Then in the next line print the original string. It is guaranteed that there is at least one stucked key. 
Sample Input:
3
caseee1__thiiis_iiisss_a_teeeeeest
Sample Output:
ei
case1__this_isss_a_teest
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
struct node{
	char x;
	int pos;
};
bool single[300]={false};
bool dis[300]={false};
bool flags[300]={false};
vector<node> cs; 
int main()
{
	int k;
	string s;
	cin>>k>>s;
	for(int i=0;i<s.length();)
	{
		bool flag1=false;
		int j=i+1;
		for(;j<i+k&&j<s.length();j++)
		{
			if(s[i]!=s[j])
			{
				single[(int)s[i]]=true;
				flag1=true;
				i=j;
				break;
			}
		}
		if(!flag1&&(j==i+k))
		{
			node temp;
			temp.pos=i;
			temp.x=s[i];
			dis[(int)s[i]]=true;
			cs.push_back(temp);
			i+=k;
		}
		else if(!flag1)
		{
			single[(int)s[i]]=true;
			break;
		}
	}
	vector<char> v2;
	vector<int> v3;
	for(int i=0;i<cs.size();i++)
	{
		if(dis[(int)cs[i].x]&&!single[(int)cs[i].x]&&!flags[(int)cs[i].x])
		{
			flags[(int)cs[i].x]=true;
			v2.push_back(cs[i].x);
			v3.push_back(cs[i].pos);
		}
		else if(dis[(int)cs[i].x]&&!single[(int)cs[i].x])
		{
			v3.push_back(cs[i].pos);
		}
	}
	string u;
	int pp=0;
	for(int i=0;i<s.size();)
	{
		u+=s[i];
		if(pp<v3.size()&&i==v3[pp])
		{
			i+=k;
			pp++;
		}
		else
		{
			i++;
		}
	}
	for(int i=0;i<v2.size();i++)
	{
		cout<<v2[i];
	}
	cout<<'\n';
	for(int i=0;i<u.size();i++)
	{
		cout<<u[i];
	}
	return 0;
 } 
