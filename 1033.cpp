/*1033. To Fill or Not to Fill (25)
With highways available, driving a car from Hangzhou to any other city is easy. But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time. Different gas station may give different price. You are asked to carefully design the cheapest route to go.
Input Specification: 
Each input file contains one test case. For each case, the first line contains 4 positive numbers: Cmax (<= 100), the maximum capacity of the tank; D (<=30000), the distance between Hangzhou and the destination city; Davg (<=20), the average distance per unit gas that the car can run; and N (<= 500), the total number of gas stations. Then N lines follow, each contains a pair of non-negative numbers: Pi, the unit gas price, and Di (<=D), the distance between this station and Hangzhou, for i=1,...N. All the numbers in a line are separated by a space.
Output Specification: 
For each test case, print the cheapest price in a line, accurate up to 2 decimal places. It is assumed that the tank is empty at the beginning. If it is impossible to reach the destination, print "The maximum travel distance = X" where X is the maximum possible distance the car can run, accurate up to 2 decimal places.
Sample Input 1:
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
Sample Output 1:
749.17
Sample Input 2:
50 1300 12 2
7.10 0
7.00 600
Sample Output 2:
The maximum travel distance = 1200.00
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
	double pi;
	double di;
}ns[500];
bool cmp(node a,node b)
{
	return a.di<b.di;
}
int main()
{
	double c,d,da;
	int n;
	scanf("%lf %lf %lf %d",&c,&d,&da,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf %lf",&ns[i].pi,&ns[i].di);
	}
	sort(ns,ns+n,cmp);
	if(ns[0].di)
	{
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	double maxd=c*da,minp,mip;
	double ans=0,capital=0;
	int k=0,pos=0;
	while(pos<n)
	{
		minp=ns[pos].pi;
		mip=100000;
		bool flag=false;
		for(int i=pos+1;i<n;i++)
		{
			if((ns[i].di-ns[pos].di)>maxd)
			{
				break;
			}
			if(ns[i].pi<minp)
			{
				flag=true;
				k=i;
				break;
			}
			if(ns[i].pi<mip)
			{
				mip=ns[i].pi;
				k=i;
			}
		}
		if(flag)
		{
			ans=ans+((ns[k].di-ns[pos].di)/da-capital)*ns[pos].pi;
			capital=0;
			pos=k;
		}
		else
		{
			if((d-ns[pos].di)<=maxd)
			{
				ans=((d-ns[pos].di)/da-capital)*minp+ans;
				break;
			}
			else
			{
				if(mip!=100000)
				{
					ans=(c-capital)*minp+ans;
					capital=c-(ns[k].di-ns[pos].di)/da;
					pos=k;
				}
				else
				{
					printf("The maximum travel distance = %.2f",ns[pos].di+maxd);
					return 0;
				}
			}
		}	
	}
	printf("%.2f",ans);
	return 0;
 } 
