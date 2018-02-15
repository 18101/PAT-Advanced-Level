/*1049. Counting Ones (30)
The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.
Input Specification: 
Each input file contains one test case which gives the positive N (<=230).
Output Specification: 
For each test case, print the number of 1's in one line.
Sample Input:
12
Sample Output:
5
*/
#include <iostream>
#include <cstring>
using namespace std;
int Get(int n,int k)
{
	int u=(n/k)%10;
	if(!u)
		return 0;
	else if(u>1)
		return k;
	else
		return n%k+1;
}
int main()
{
	int n;
	scanf("%d",&n);
	int a=n,k=1,c=10,ans=0,q;
	while(a)
	{
		a=a/10;
		q=n/c;
		ans+=q*k;
		ans+=Get(n,k);
		c*=10;
		k*=10;
	}
	printf("%d",ans);
	return 0;
 } 
