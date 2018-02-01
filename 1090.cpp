/*1090. Highest Price in Supply Chain (25)
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.
Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.
Now given a supply chain, you are supposed to tell the highest price we can expect from some retailers.
Input Specification: 
Each input file contains one test case. For each case, The first line contains three positive numbers: N (<=105), the total number of the members in the supply chain (and hence they are numbered from 0 to N-1); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then the next line contains N numbers, each number Si is the index of the supplier for the i-th member. Sroot for the root supplier is defined to be -1. All the numbers in a line are separated by a space.
Output Specification: 
For each test case, print in one line the highest price we can expect from some retailers, accurate up to 2 decimal places, and the number of retailers that sell at the highest price. There must be one space between the two numbers. It is guaranteed that the price will not exceed 1010.
Sample Input:
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
Sample Output:
1.85 2
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int l[100005];
int father[100005];
int Find(int i)
{
	if(l[i]==-1)
	{
		father[i]=0;
		return 0;
	}
	if(!father[i])
		father[i]=Find(l[i])+1;
	return father[i];
}
int main()
{
	memset(l,0,sizeof(l));
	memset(father,0,sizeof(father));
	int n,maxi=-1,maxn,d;
	double p1,r;
	scanf("%d %lf %lf",&n,&p1,&r);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&l[i]);
	}
	for(int i=0;i<n;i++)
	{
		d=Find(i);
		if(d==maxi)
			maxn++;
		else if(d>maxi)
		{
			maxi=d;
			maxn=1;			
		}
	}
	r=r/100.0+1;
	while(maxi)
	{
		p1*=r;
		maxi--;
	}
	printf("%.2f %d",p1,maxn);
 } 
