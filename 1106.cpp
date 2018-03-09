/*1106. Lowest Price in Supply Chain (25)
A supply chain is a network of retailers�������̣�, distributors�������̣�, and suppliers����Ӧ�̣�-- everyone involved in moving a product from supplier to customer.
Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.
Now given a supply chain, you are supposed to tell the lowest price a customer can expect from some retailers.
Input Specification: 
Each input file contains one test case. For each case, The first line contains three positive numbers: N (<=105), the total number of the members in the supply chain (and hence their ID's are numbered from 0 to N-1, and the root supplier's ID is 0); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each describes a distributor or retailer in the following format:
Ki ID[1] ID[2] ... ID[Ki]
where in the i-th line, Ki is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID's of these distributors or retailers. Kj being 0 means that the j-th member is a retailer. All the numbers in a line are separated by a space.
Output Specification: 
For each test case, print in one line the lowest price we can expect from some retailers, accurate up to 4 decimal places, and the number of retailers that sell at the lowest price. There must be one space between the two numbers. It is guaranteed that the all the prices will not exceed 1010.
Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0
*/
#include<iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
int father[100005];
int level[100005];
int root[100005];
vector<int> retail;
int GetLevel(int i)
{
	if(!i)
	{
		return 0;
	}
	if(level[i])
		return level[i];
	else
	{
		level[i]=GetLevel(father[i])+1;
		return level[i];
	}
}
int main()
{
	memset(level,0,sizeof(level));
	int n,x,y,count=1;
	double p,r,sum=10000000050.0;
	scanf("%d %lf %lf",&n,&p,&r);
	for(int i=0;i<n;i++)
	{
		root[i]=i;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		for(int j=0;j<x;j++)
		{
			scanf("%d",&y);
			father[y]=i;
		}
		if(!x)
			retail.push_back(i);
	}
	for(int i=0;i<retail.size();i++)
	{
	//	printf(" %d",retail[i]);
		level[retail[i]]=GetLevel(retail[i]);
	}
/*	for(int i=0;i<n;i++)
	{
		printf(" %d",level[i]);
	}*/
	double ss=0;
	r=1+r/100.0;
	for(int i=0;i<retail.size();i++)
	{
		ss=pow(r,level[retail[i]]);
		if(ss<sum)
		{
			sum=ss;
			count=1;
		}
		else if(ss==sum)
		{
			count++;
		}
	}
	printf("%.4f %d",p*sum,count);
	return 0;
 } 