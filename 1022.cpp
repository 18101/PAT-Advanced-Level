/*1022. Digital Library (30)
A Digital Library contains millions of books, stored according to their titles, authors, key words of their abstracts, publishers, and published years. Each book is assigned an unique 7-digit number as its ID. Given any query from a reader, you are supposed to output the resulting books, sorted in increasing order of their ID's.
Input Specification: 
Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the total number of books. Then N blocks follow, each contains the information of a book in 6 lines:
Line #1: the 7-digit ID number; 
Line #2: the book title -- a string of no more than 80 characters; 
Line #3: the author -- a string of no more than 80 characters; 
Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by exactly one space; 
Line #5: the publisher -- a string of no more than 80 characters; 
Line #6: the published year -- a 4-digit number which is in the range [1000, 3000]. 
It is assumed that each book belongs to one author only, and contains no more than 5 key words; there are no more than 1000 distinct key words in total; and there are no more than 1000 distinct publishers.
After the book information, there is a line containing a positive integer M (<=1000) which is the number of user's search queries. Then M lines follow, each in one of the formats shown below:
1: a book title 
2: name of an author 
3: a key word 
4: name of a publisher 
5: a 4-digit number representing the year 
Output Specification: 
For each query, first print the original query in a line, then output the resulting book ID's in increasing order, each occupying a line. If no book is found, print "Not Found" instead.
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
	map<string,set<int> > mp[6];
	int n,number,m,no;
	string s,ms;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>number;
		cin.get();
		for(int j=1;j<=2;j++)
		{
			getline(cin,s);
			mp[j][s].insert(number);
		}
		getline(cin,ms);
		string s;
		for(int j=0;j<ms.length();j++)
		{
			if(ms[j]!=' ')
			{
				s+=ms[j];
				if(j==ms.length()-1)
				{
					mp[3][s].insert(number);
				}
			}
			else
			{
				mp[3][s].insert(number);
				s="";
			}
		}
		for(int j=4;j<=5;j++)
		{
			getline(cin,s);
			mp[j][s].insert(number);
		}
	}
	cin>>m;
	cin.get();
	for(int i=0;i<m;i++)
	{
		cin>>no;
		cin.get();
		cin.get();
		getline(cin,s);
		cout<<no<<": "<<s<<endl;
		if(mp[no].find(s)==mp[no].end())
			cout<<"Not Found\n";
		else
		{
			for(set<int>::iterator it=mp[no][s].begin();it!=mp[no][s].end();it++)
			{
				cout.fill('0');
				cout.width(7);
				cout<<*it<<endl;
			}
		}
	}
	return 0;
 } 
