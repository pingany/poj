#include<iostream>
#include<cstdio>
using namespace std;
#define M 500000
int a[M];
bool solve()
{
	int x=0,n,i,j;
	scanf("%d",&n);
	if(n==0)return false;
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	for(i=0;i<n;i++)
		for(j=n-1;j>i;j--)
	{
		if(a[j-1]>a[j])
		{
			swap(a[j],a[j-1]);
			x++;
		}
	}
	printf("%d\n",x);
	return true;
}
int main()
{
	//freopen("c:/acm//pku_2299.txt","r",stdin);
	while(solve());
   return 0;
}