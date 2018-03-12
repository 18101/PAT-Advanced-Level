/*1129. Recommendation System (25)
Recommendation system predicts the preference that a user would give to an item. Now you are asked to program a very simple recommendation system that rates the user's preference by the number of times that an item has been accessed by this user.
Input Specification: 
Each input file contains one test case. For each test case, the first line contains two positive integers: N (<= 50000), the total number of queries, and K (<= 10), the maximum number of recommendations the system must show to the user. Then given in the second line are the indices of items that the user is accessing -- for the sake of simplicity, all the items are indexed from 1 to N. All the numbers in a line are separated by a space.
Output Specification: 
For each case, process the queries one by one. Output the recommendations for each query in a line in the format:
query: rec[1] rec[2] ... rec[K] 
where query is the item that the user is accessing, and rec[i] (i = 1, ... K) is the i-th item that the system recommends to the user. The first K items that have been accessed most frequently are supposed to be recommended in non-increasing order of their frequencies. If there is a tie, the items will be ordered by their indices in increasing order.
Note: there is no output for the first item since it is impossible to give any recommendation at the time. It is guaranteed to have the output for at least one query. 
Sample Input:
12 3
3 5 7 5 5 3 2 1 8 3 8 12
Sample Output:
5: 3
7: 3 5
5: 3 5 7
5: 5 3 7
3: 5 3 7
2: 5 3 7
1: 5 3 2
8: 5 3 1
3: 5 3 1
8: 3 5 1
12: 3 5 8
*/
#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
struct node{
	int value;
	int fre;
}temp;
struct cmp{
	bool operator()(node a,node b)
	{
		if(a.fre==b.fre)
		{
			return a.value<b.value;
		}
		return a.fre>b.fre;
	}
};
int fres[50005];
set<node,cmp> st;
int main()
{
	memset(fres,0,sizeof(fres));
	int n,k,x;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(i)
			printf("%d:",x);
		int cnt=0;
		for(set<node>::iterator it=st.begin();it!=st.end();it++)
		{
			printf(" %d",(*it).value);
			cnt++;
			if(cnt==k)
				break;
		}
		if(i)
			printf("\n");
		temp.fre=fres[x];
		fres[x]++;
		temp.value=x;
		set<node>::iterator it2=st.find(temp);
		if(it2==st.end())
		{
			temp.fre++;
			st.insert(temp);
		}
		else
		{
			st.erase(it2);
			temp.fre++;
			st.insert(temp);
		}
	 }
	return 0;
 } 
