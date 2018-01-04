/*
1001. A+B Format (20)
Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).
Input
Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format. 
Sample Input
-1000000 9
Sample Output
-999,991
*/
#include <iostream>
#include <cstring>
#include <cstdio> 
#include <cstdlib>
using namespace std;
long long a,b;
void OutPut(int k,char a[])
{
	char final[10];
	if(k==7){
		final[0]=a[0];
		final[1]=',';
		for(int i=2;i<5;i++)
		{
			final[i]=a[i-1];
		}
		final[5]=',';
		for(int i=6;i<9;i++)
		{
			final[i]=a[i-2];
		}
		final[9]='\0';
	}
	else if(k>3)
	{
		for(int i=0;i<k-3;i++)
		{
			final[i]=a[i];
		}
		final[k-3]=',';
		for(int i=k-2;i<k+1;i++)
		{
			final[i]=a[i-1];
		}
		final[k+1]='\0';
	}
	else
		strcpy(final,a);
	printf("%s",final);
}
int main(int argc, char** argv) {
	scanf("%ld %ld",&a,&b);
	long long c;
	int k;
	c=a+b;
	char answer[8];
	memset(answer,0,sizeof(answer));
	sprintf(answer,"%ld",c);
	if(answer[0]=='-')
	{
		k=strlen(answer)-1;
		char*s=answer+1;
		printf("%c",'-');
		OutPut(k,s);
	}
	else{
		k=strlen(answer);
		OutPut(k,answer);
	}
	return 0;
}
