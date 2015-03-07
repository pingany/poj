#include<iostream>
#include<cstdio>
using namespace std;
typedef unsigned int uint;

uint com(uint m,uint n)
{
	double f=1;
	while(n)
	{
		f*=(m+0.0)/n;
		n--;
		m--;
	}
	return (uint)f;
}

int main()
{
	uint t,m,n;
	while(cin>>m>>n && m&&n)
	{
		if(m>n) t=n;
		else t=m;
		printf("%u\n",com(m+n,t));
	}
   return 0;
}