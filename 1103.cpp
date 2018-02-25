/*1103. Integer Factorization (30)
The K-P factorization of a positive integer N is to write N as the sum of the P-th power of K positive integers. You are supposed to write a program to find the K-P factorization of N for any positive integers N, K and P.
Input Specification: 
Each input file contains one test case which gives in a line the three positive integers N (<=400), K (<=N) and P (1<P<=7). The numbers in a line are separated by a space.
Output Specification: 
For each case, if the solution exists, output in the format:
N = n1^P + ... nK^P 
where ni (i=1, ... K) is the i-th factor. All the factors must be printed in non-increasing order.
Note: the solution may not be unique. For example, the 5-2 factorization of 169 has 9 solutions, such as 122 + 42 + 22 + 22 + 12, or 112 + 62 + 22 + 22 + 22, or more. You must output the one with the maximum sum of the factors. If there is a tie, the largest factor sequence must be chosen -- sequence { a1, a2, ... aK } is said to be larger than { b1, b2, ... bK } if there exists 1<=L<=K such that ai=bi for i<L and aL>bL 
If there is no solution, simple output "Impossible". 
Sample Input 1:
169 5 2
Sample Output 1:
169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
Sample Input 2:
169 167 3
Sample Output 2:
Impossible
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > v;
vector<int> tempv;
int data[25],n,k,p;
void DFS(int a,int sum,int number)
{
	if(a<1||sum<0)
		return;
	if(!number&&sum)
		return;
	if(!number&&!sum)
	{
		v.push_back(tempv);
		return;
	}
	tempv.push_back(a);
	DFS(a,sum-data[a],number-1);
	tempv.pop_back();
	DFS(a-1,sum,number);
}
bool cmp(vector<int>v1,vector<int> v2)
{
	if(v1[k]!=v2[k])
		return(v1[k]>v2[k]);
	else
	{
		for(int i=0;i<k;i++)
		{
			if(v1[i]!=v2[i])
				return v1[i]>v2[i];
		}
	}
}
int main()
{
	scanf("%d %d %d",&n,&k,&p);
	int maxnu=(int)pow(n,(1.0/p));
	for(int i=1;i<=maxnu;i++)
	{
		data[i]=pow(i,p);
	}
		DFS(maxnu,n,k);
	if(v.empty())
	{
		printf("Impossible");
		return 0;
	}
	for(int i=0;i<v.size();i++)
	{
		int vsum=0;
		for(int j=0;j<v[i].size();j++)
		{
			vsum+=v[i][j];
		}
		v[i].push_back(vsum);
	}
	sort(v.begin(),v.end(),cmp);
	printf("%d = %d^%d",n,v[0][0],p);
	for(int i=1;i<v[0].size()-1;i++)
	{
		printf(" + %d^%d",v[0][i],p);
	}
	return 0;
 } 
