#include<iostream>
#include<cstdio>
using namespace std;
typedef unsigned int uint;

uint com(int m,int n)
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
	int t,m,n;
	while(cin>>m>>n && m)
	{
		if(m>n) t=n;
		else t=m;
		printf("%u\n",com(m+n,t));
	}
   return 0;
}