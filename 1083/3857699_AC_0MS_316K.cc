#include<stdio.h>
#include<string.h>
#define MAX 200
#define swap(x,y)  {int t=(x); (x)=(y);(y)=t;}
struct Move
{
	int s,e;
};
int cs[201];
void solve()
{
	int ncase,i,s,e,m,n;
	scanf("%d",&ncase);
	while(ncase--)
	{
		memset(cs,0,sizeof(cs));
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d%d",&s,&e);
			if(s>e)swap(s,e);
			s=(s+1)/2;
			e=(e+1)/2;
			for(i=s;i<=e;++i)
				cs[i]++;
		}
		m=cs[1];
		for(i=2;i<=200;++i)if(cs[i]>m) m=cs[i];
		printf("%d\n",m*10);		
	}
}
int main()
{
	//init();
	//freopen("c:/acm/pku_1083.txt","r",stdin);
		solve();
		//while(1);
		return 0;
}