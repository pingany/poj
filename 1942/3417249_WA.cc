#include<iostream>
#include<cstdio>
using namespace std;
typedef unsigned int uint;

uint com2(int m,int n)
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

uint com(uint m,uint n)
{
	if(!m || !n)return 1;
	return com(m-1,n-1)*m/n;
}

int main()
{
	int t,m,n;
	while(cin>>m>>n && m&&n)
	{
		if(m>n) t=n;
		else t=m;
		printf("%u\n",com(m+n,t));
	}
   return 0;
}