/*1056. Mice and Rice (25)
Mice and Rice is the name of a programming contest in which each programmer must write a piece of code to control the movements of a mouse in a given map. The goal of each mouse is to eat as much rice as possible in order to become a FatMouse.
First the playing order is randomly decided for NP programmers. Then every NG programmers are grouped in a match. The fattest mouse in a group wins and enters the next turn. All the losers in this turn are ranked the same. Every NG winners are then grouped in the next match until a final winner is determined.
For the sake of simplicity, assume that the weight of each mouse is fixed once the programmer submits his/her code. Given the weights of all the mice and the initial playing order, you are supposed to output the ranks for the programmers.
Input Specification: 
Each input file contains one test case. For each case, the first line contains 2 positive integers: NP and NG (<= 1000), the number of programmers and the maximum number of mice in a group, respectively. If there are less than NG mice at the end of the player's list, then all the mice left will be put into the last group. The second line contains NP distinct non-negative numbers Wi (i=0,...NP-1) where each Wi is the weight of the i-th mouse respectively. The third line gives the initial playing order which is a permutation of 0,...NP-1 (assume that the programmers are numbered from 0 to NP-1). All the numbers in a line are separated by a space.
Output Specification: 
For each test case, print the final ranks in a line. The i-th number is the rank of the i-th programmer, and all the numbers must be separated by a space, with no extra space at the end of the line. 
Sample Input:
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3
Sample Output:
5 5 5 2 5 5 5 3 1 3 5
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct mice{
	int m;
	int first;
}mac[1001],miceandrice[1001];
int ranks[1001];
mice GetFatest(mice mm[],int n,int rank)
{
	int maxm=-1;
	int j;
	for(int i=0;i<n;i++)
	{
		if(mm[i].m>maxm)
		{
			maxm=mm[i].m;
			j=i;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i!=j)
			ranks[mm[i].first]=rank;
	}
	return mm[j];
}
int main()
{
	memset(ranks,0,sizeof(ranks));
	memset(mac,0,sizeof(mac));
	memset(miceandrice,0,sizeof(miceandrice));
	int np,ng,order;
	scanf("%d %d",&np,&ng);
	int np2=np;
	for(int i=0;i<np;i++)
	{
		scanf("%d",&mac[i].m);
		mac[i].first=i;
	}
	for(int i=0;i<np;i++)
	{
		scanf("%d",&order);
		miceandrice[i]=mac[order];
	}
	int rank;
	while(np>1)
	{
		int count=0;
		int leftn=np%ng;
		np=np/ng;
		rank=np+1;
		if(leftn)
		{
			rank++;
		}
		for(int i=0;i<np;i++)
		{
			miceandrice[count++]=GetFatest(miceandrice+i*ng,ng,rank);
		}
		if(leftn)
		{
			miceandrice[count]=GetFatest(miceandrice+np*ng,leftn,rank);
			np++;
		}
	}
	for(int i=0;i<np2;i++)
	{
		if(i)
			printf(" ");
		if(ranks[i])
			printf("%d",ranks[i]);
		else
			printf("1");
	}
	return 0;
}

