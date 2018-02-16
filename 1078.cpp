/*1078. Hashing (25)
The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers. The hash function is defined to be "H(key) = key % TSize" where TSize is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.
Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.
Input Specification: 
Each input file contains one test case. For each case, the first line contains two positive numbers: MSize (<=104) and N (<=MSize) which are the user-defined table size and the number of input numbers, respectively. Then N distinct positive integers are given in the next line. All the numbers in a line are separated by a space.
Output Specification: 
For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. All the numbers in a line are separated by a space, and there must be no extra space at the end of the line. In case it is impossible to insert the number, print "-" instead. 
Sample Input:
4 4
10 6 4 15
Sample Output:
0 1 4 -
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int num[100000];
bool po[100000]={false};
int GetPrime(int a)
{
	if(a==1||a==2)
		return 2;
	if(a==3) 
		return 3;
	while(true)
	{
		for(int i=2;i<=sqrt(a);i++)
		{
			if(!(a%i))
			{
				a++;
				break;
			}
			if(i==(int)sqrt(a))
			{
				return a;
			}
		}
	}
	return a;
}
int main()
{
	memset(num,0,sizeof(num));
	int m,n,l,k;
	scanf("%d %d",&m,&n);
	int prime=GetPrime(m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&l);
		if(i)
			printf(" ");
		k=l%prime;
		for(int j=1;;j++)
		{
			if(!po[k])
			{
				po[k]=true;
				printf("%d",k);
				break;
			}
			else
			{
				k=(l+j*j)%prime;
				if(j>=prime)
				{
					printf("-");
					break;
				}
			}
		}
	}
	return 0;
 } 
