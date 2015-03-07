#include<iostream>
#include<cstdio>
using namespace std;
int  p(int m,int n)
{
	if(n==1)return 1;
	if(m<n)return p(m,m);
	if(m==n)return p(m,m-1)+1;
	return p(m,n-1)+p(m-n,n);
}
int main()
{
	int m,n, ncase,i;
	scanf("%d",&ncase);
	for(i=0;i<ncase;i++)
	{
		scanf("%d %d",&m,&n);
		printf("%d\n",p(m,n));
	}
   return 0;
}