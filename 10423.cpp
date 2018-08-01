#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void P(int num)
{
	if(num<=13)
		printf("S%d",num);
	else if(num<=26)
		printf("H%d",num-13);
	else if(num<=39)
		printf("C%d",num-26);
	else if(num<=52)
		printf("D%d",num-39);
	else
		printf("J%d",num-52);
	
}
int main()
{
	int a[56],b[56],c[56];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int i=1;i<=54;i++)
	{
		a[i]=i;
	}
	int n;
	scanf("%d",&n);
	for(int i=1;i<=54;i++)
	{
		scanf("%d",&b[i]);
	}
	for(int i=0;i<n;i++)
	{
		memset(c,0,sizeof(c));
		for(int j=1;j<=54;j++)
		{
			c[b[j]]=a[j];
		}
		for(int j=1;j<=54;j++)
		{
			a[j]=c[j];
		}
	}
	for(int i=1;i<54;i++)
	{
		P(a[i]);
		printf(" ");
	}
	P(a[54]);
	return 0;
 } 
