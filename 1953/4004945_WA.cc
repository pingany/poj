#include<stdio.h>
#include<math.h>
typedef long long LONG ;
int index=0;
void solve(int n)
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
int main()
{ 
	//freopen("c:/acm/pku_1953.txt","r",stdin);
	int ncase,n;
	scanf("%d",&ncase);
	while(ncase--)
	{
		scanf("%d",&n);
		solve(n);
	}
	return 0;

}