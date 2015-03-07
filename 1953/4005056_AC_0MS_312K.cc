#include<stdio.h>
#include<math.h>
typedef long long LONG ;
int index=0;
void solve33(int n)
{
	
	LONG  s=0;
	if(n==1) s=2;
	else
	{
	int k=1,i;
	for(i=n-1;i>0;--i)
	{
		s=(s+k)*2*i;
		k=-k;
	}
	s>>=1;
	s=(LONG)pow(2.0,n)-s;
	}
	printf("Scenario #%d:\n%lld\n\n",++index,s);
}
int a[45];
void  init()
{
	int i;
	a[1]=2;
	a[2]=3;
	for(i=3;i<45;++i)a[i]=a[i-1]+a[i-2];
}
int main()
{ 
	init();
	//freopen("c:/acm/pku_1953.txt","r",stdin);
	int ncase,n;
	scanf("%d",&ncase);
	while(ncase--)
	{
		scanf("%d",&n);
		printf("Scenario #%d:\n%d\n\n",++index,a[n]);
	}
	return 0;

}