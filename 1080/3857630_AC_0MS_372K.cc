#include<stdio.h>
#include<string.h>
#define MAX 150
int t[][5]=
{
	{5,-1,-2,-1,-3},
	{-1,5,-3,-2,-4},
	{-2,-3,5,-2,-2},
	{-1,-2,-2,5,-1},
	{-3,-4,-2,-1,0}
};
int gene[128];
void init()
{
	gene['A']=0;
	gene['C']=1;
	gene['G']=2;
	gene['T']=3;
	gene['-']=4;
}
void deal(char *s,int n)
{
	int i;
	for(i=0;i<n;i++) s[i]=gene[s[i]];
}
int f[MAX][MAX];
int fun(char *s,char *d,int ns,int nd)
{
	int i,j,m1,m2,m3;
	f[0][0]=0;
	for(i=1;i<=nd;i++)f[0][i]=f[0][i-1]+t[4][ d[i-1] ];
	for(i=1;i<=ns;i++)f[i][0]=f[i-1][0]+t[ s[i-1] ][4];
	for(i=1;i<=ns;i++)
		for(j=1;j<=nd;j++)
	{
		if(s[i-1]==d[j-1])f[i][j]=f[i-1][j-1]+5;
		else 
		{
			 m1=f[i-1][j-1]+t[s[i-1]][d[j-1]];
			 m2=f[i-1][j]+t[s[i-1]][4];
			 m3=f[i][j-1]+t[4][d[j-1]];
			 if(m2>m1) m1=m2;
			 if(m3>m1) m1=m3;
			 f[i][j]=m1;			 
		}
	}
	return f[ns][nd];
}
void solve()
{
   char s[MAX],d[MAX];
   int ns,nd,m,ncase;
   scanf("%d",&ncase);
   while(ncase--)
	{
	   scanf("%d%s",&ns,s);
	   scanf("%d%s",&nd,d);
	   deal(s,ns);
	   deal(d,nd);
	   m=fun(s,d,ns,nd);
	   printf("%d\n",m);
	}
}
int main()
{
	init();
	//freopen("c:/acm/1080.txt","r",stdin);
		solve();
		//while(1);
		return 0;
}
