/*1037. Magic Coupon (25)
The magic shop in Mars is offering some magic coupons. Each coupon has an integer N printed on it, meaning that when you use this coupon with a product, you may get N times the value of that product back! What is more, the shop also offers some bonus product for free. However, if you apply a coupon with a positive N to this bonus product, you will have to pay the shop N times the value of the bonus product... but hey, magically, they have some coupons with negative N's! 
For example, given a set of coupons {1 2 4 -1}, and a set of product values {7 6 -2 -3} (in Mars dollars M$) where a negative value corresponds to a bonus product. You can apply coupon 3 (with N being 4) to product 1 (with value M$7) to get M$28 back; coupon 2 to product 2 to get M$12 back; and coupon 4 to product 4 to get M$3 back. On the other hand, if you apply coupon 3 to product 4, you will have to pay M$12 to the shop.
Each coupon and each product may be selected at most once. Your task is to get as much money back as possible.
Input Specification: 
Each input file contains one test case. For each case, the first line contains the number of coupons NC, followed by a line with NC coupon integers. Then the next line contains the number of products NP, followed by a line with NP product values. Here 1<= NC, NP <= 105, and it is guaranteed that all the numbers will not exceed 230. 
Output Specification: 
For each test case, simply print in a line the maximum amount of money you can get back.
Sample Input:
4
1 2 4 -1
4
7 6 -2 -3
Sample Output:
43
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int nc[100005],np[100005];
bool cmp1(int a,int b)
{
	return a>b;
}
int main()
{
	memset(nc,0,sizeof(nc));
	memset(np,0,sizeof(np));
	long long ans=0;
	int c,p;
	scanf("%d",&c);
	for(int i=0;i<c;i++)
		scanf("%d",&nc[i]);
	scanf("%d",&p);
	for(int i=0;i<p;i++)
		scanf("%d",&np[i]);
	sort(nc,nc+c,cmp1);
	sort(np,np+p,cmp1);
	for(int i=0;(i<c)&&(i<p);i++)
	{
		if(nc[i]<=0)
			break;
		if(np[i]<=0)
			break;
		ans+=(nc[i]*np[i]);
	}
	int i=c-1;
	int j=p-1;
	while((i>=0)&&(j>=0))
	{
		if(nc[i]>=0)
			break;
		if(np[j]>=0)
			break;
		ans+=(nc[i]*np[j]);
		i--;
		j--;
	}
	printf("%lld",ans);
	return 0;
}
