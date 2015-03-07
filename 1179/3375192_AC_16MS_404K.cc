#include<iostream>
#include<cstdio>
using namespace std;
#define M 51
const int IINF =1<<31;//最小负数
const int INF=0x7fffffff;
int ver[M],edge[M],a[M],op[M];
int n;
int f[M][M];
int mf[M][M];
int result[M];
int oper(int a,int b,int op)
{
	switch(op)
	{
	case 'x':return a*b;
	case 't':return a+b;
	}
}
void input()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s%d",&edge[i],&ver[i]);
	}
}
int qujianx(int a,int b,int c,int d, int &maxx,int &minx)
{
	int x[4];
	x[0]=a*c;
	x[1]=a*d;
	x[2]=b*c;
	x[3]=b*d;
	maxx=max(max(x[0],x[1]),max(x[2],x[3]));
	minx=min(min(x[0],x[1]),min(x[2],x[3]));
}
int  maxs()
{
	int i,j,k,maxf,maxt,mint,minf;
	for(i=0;i<n;i++)f[i][i]=mf[i][i]=a[i];
	for(i=n-1;i>=0;i--)
		for(j=i+1;j<n;j++)
		{
			maxf=IINF;
			minf=INF;
			for(k=i;k<j;k++)
			{
				if(op[k]=='x')
				{
					qujianx( mf[i][k],f[i][k],mf[k+1][j],f[k+1][j],maxt,mint);
				}
				else 
				{
					maxt=oper(f[i][k],f[k+1][j],op[k]);
					mint=oper(mf[i][k],mf[k+1][j],op[k]);
				}
				if(maxt>maxf)maxf=maxt;
				if(mint<minf)minf=mint;
			}
			f[i][j]=maxf;
			mf[i][j]=minf;
		}
		return f[0][n-1];
}
inline int pre(int i)
{
	if(i==0)return n-1;
	return i-1;
}
int  go(int k)
{
	int i,j=0;
	for(i=pre(k);i!=k;i=pre(i))
	{
		a[j]=ver[i];
		op[j]=edge[i];
		j++;
	}
	a[j]=ver[k];
	return maxs();
}
void solve()
{
	input();
	int maxf=IINF,i;
	bool first=true;
	for(i=0;i<n;i++)
	{
		result[i]=go(i);
		if(result[i]>maxf)maxf=result[i];
	}
	printf("%d\n",maxf);
	for(i=0;i<n;i++)
	{
		if(result[i]==maxf)
		{
			if(first){first=false;printf("%d",i+1);}
			else {printf(" %d",i+1);}
		}
	}
	printf("\n");	
}
int main()
{
	//freopen("c:/acm/pku_1179.txt","r",stdin);
	solve();
	return 0;
}