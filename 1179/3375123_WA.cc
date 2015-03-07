#include<iostream>
#include<cstdio>
using namespace std;
#define M 51
const int IINF =1<<31;//最小负数
int ver[M],edge[M],a[M],op[M];
int n;
int f[M][M];
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
int  maxs()
{
	int i,j,k,maxf,t;
	for(i=0;i<n;i++)f[i][i]=a[i];
	for(i=n-1;i>=0;i--)
		for(j=i+1;j<n;j++)
		{
			maxf=IINF;
			for(k=i;k<j;k++)
			{
				if((t=oper(f[i][k],f[k+1][j],op[k]))>maxf)
				{
					maxf=t;
				}
			}
			f[i][j]=maxf;
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