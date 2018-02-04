/*1079. Total Sales of Supply Chain (25)
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.
Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.
Now given a supply chain, you are supposed to tell the total sales from all the retailers.
Input Specification: 
Each input file contains one test case. For each case, the first line contains three positive numbers: N (<=105), the total number of the members in the supply chain (and hence their ID's are numbered from 0 to N-1, and the root supplier's ID is 0); P, the unit price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each describes a distributor or retailer in the following format:
Ki ID[1] ID[2] ... ID[Ki]
where in the i-th line, Ki is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID's of these distributors or retailers. Kj being 0 means that the j-th member is a retailer, then instead the total amount of the product will be given after Kj. All the numbers in a line are separated by a space.
Output Specification: 
For each test case, print in one line the total sales we can expect from all the retailers, accurate up to 1 decimal place. It is guaranteed that the number will not exceed 1010.
Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3
Sample Output:
42.4
*/
#include <iostream>
#include <cstdio> 
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int list[100000],list2[100000];
vector <pair<int,int> > v;
int Get(int a)
{
	if(list2[a])
		return list2[a];
	else if(list[a]==-1)
		list2[a]=0;
	else
	{
		list2[a]=Get(list[a])+1;
	}
	return list2[a];
}
int main()
{
	memset(list,-1,sizeof(list));
	double ans=0,p,r;
	pair<int,int> pa;
	int n,k,u,nv=0;
	scanf("%d %lf %lf",&n,&p,&r);
	r=r/100.0+1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);
		if(k)
		{
			for(int j=0;j<k;j++)
			{
				scanf("%d",&u);
				list[u]=i;
			}
		}
		else
		{
			nv++;
			scanf("%d",&pa.second);
			pa.first=i;
			v.push_back(pa);
		}
	}
	for(int i=0;i<nv;i++)
	{
		ans=ans+v[i].second*pow(r,Get(v[i].first));
	}
	ans*=p;
	printf("%.1f",ans);
}
