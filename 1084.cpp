/*
1084. Broken Keyboard (20)
On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters corresponding to those keys will not appear on screen.
Now given a string that you are supposed to type, and the string that you actually type out, please list those keys which are for sure worn out. 
Input Specification: 
Each input file contains one test case. For each case, the 1st line contains the original string, and the 2nd line contains the typed-out string. Each string contains no more than 80 characters which are either English letters [A-Z] (case insensitive), digital numbers [0-9], or "_" (representing the space). It is guaranteed that both strings are non-empty. 
Output Specification: 
For each test case, print in one line the keys that are worn out, in the order of being detected. The English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed that there is at least one worn out key. 
Sample Input:
7_This_is_a_test
_hs_s_a_es
Sample Output:
7TI
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void strupr1(char* ptr)
{
  for(int i=0;ptr[i]!='\0';i++)
  {
    if(ptr[i]<='z'&&ptr[i]>='a')
      ptr[i]=ptr[i]+'A'-'a';
  }
}
int main()
{
  char s1[85],s2[85],s3[85];
  memset(s1,0,sizeof(s1));
  memset(s2,0,sizeof(s2));
  memset(s3,0,sizeof(s3));
  bool flag;
  cin>>s1;
  cin>>s2;
  strupr1(s1);
  strupr1(s2);
  int i=0,j=0,k=0;
  while(j<strlen(s2))
  {
    if(s1[i]!=s2[j])
    {
      flag=true;
      for(int x=0;x<k;x++)
      {
        if(s3[x]==s1[i])
        {
          flag=false;
          break;
        }
      }
      if(flag)
      {
        s3[k]=s1[i];
        k++;
      }
      i++;
      continue;
    }
    i++;
    j++;
  }
  for(;i<strlen(s1);i++)
  {
    flag=true;
    for(int x=0;x<k;x++)
    {
      if(s3[x]==s1[i])
      {
        flag=false;
        break;
      }
    }
    if(flag)
    {
      s3[k]=s1[i];
      k++;
    }
  }
  cout<<s3;
  return 0;
 } 
