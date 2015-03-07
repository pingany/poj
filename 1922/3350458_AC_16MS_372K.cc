#include<iostream>
#include<cmath>
using namespace std;
#define M 100
int n=1;
void solve()
{
	scanf("%d",&n);
	if(n==0)return ;
	int i,f,v,t;
	int min=100000000;
	for(i=0;i<n;i++)
	{
		scanf("%d\t%d",&v,&t);
		if(t<0)continue;
		f=(int)ceil(4.5*3600/v+t);
		if(f>0 && f<min)min=f;
	}
	printf("%d\n",min);
}
int main()
{
	//freopen("c:/acm/pku_1922.txt","r",stdin);
	while(n!=0)
	{
		solve();
	}
   return 0;
}