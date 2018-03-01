/*1013. Battle Over Cities (25)
It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.
For example, if we have 3 cities and 2 highways connecting city1-city2 and city1-city3. Then if city1 is occupied by the enemy, we must have 1 highway repaired, that is the highway city2-city3.
Input
Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.
Output
For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.
Sample Input
3 2 3
1 2
1 3
1 2 3
Sample Output
1
0
0
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int n,m,k;
vector<int> v[1001];
bool go[1001];
void BFS(int k)
{
  queue<int> q;
  q.push(k);
  while(!q.empty())
  {
    int temp=q.front();
    q.pop();
    for(int i=0;i<v[temp].size();i++)
    {
      if(!go[v[temp][i]])
      {
        q.push(v[temp][i]);
        go[v[temp][i]]=true;
      }
    }
  }
}
int main()
{
  //freopen("C:\\Users\\asus\\Desktop\\a.txt","r",stdin);
  int x,y,d;
  scanf("%d %d %d",&n,&m,&k);
  for(int i=0;i<m;i++)
  {
    scanf("%d %d",&x,&y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for(int i=0;i<k;i++)
  {
    int count=0;
    memset(go,0,sizeof(go));
    scanf("%d",&d);
    go[d]=true;
    for(int j=1;j<=n;j++)
    {
      if(!go[j])
      {
        count++;
        BFS(j);
      }
    }
    printf("%d\n",count-1);
  }
  return 0;
 } 
