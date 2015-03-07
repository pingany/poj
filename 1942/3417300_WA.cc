#include<iostream>
using namespace std;
typedef long long uint;

uint com2(uint  m,uint  n)
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

int  main()
{
	uint t,m,n;
	while(cin>>m>>n && m&&n)
	{
		if(m>n) t=n;
		else t=m;
		cout<<com(m+n,t)<<"\n";
	}
   return 0;
}