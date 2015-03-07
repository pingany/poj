#include<iostream>
#include<cstdio>
using namespace std;
#define maxv 100001
int index=0;
//inline int getroot(int i){
//	while(i!=root[i])
//	{
//		i=root[i];
//	}
//	return i;
//}
int gr[maxv];
int g[maxv];
char *ans[]={"Not sure yet.",
"In different gangs.",
"In the same gang."
};
void solve()
{
	int ncase,m,n,i,j,k,kroot,jroot;
	scanf("%d",&ncase);
	char op;
	while(ncase--)
	{
		scanf("%d%d\n",&m,&n);
		memset(g,-1,sizeof(int)*(m+1));
		for(i=1;i<=m;i++){gr[i]=i;}
		for(i=0;i<n;i++)
		{
			scanf("%s%d%d\n",&op,&k,&j);
			kroot=gr[k];
			jroot=gr[j];
			if(op=='D')
			{
				if(g[k]==-1)g[k]=j;
				else 
				{
					gr[j]=gr[g[k]];
				}
				if(g[j]==-1)g[j]=k;
				else 
				{
					gr[k]=gr[g[j]];
				}
			}
			else 
			{
				
				if(kroot==jroot)puts(ans[2]);
				else if(g[k]==-1)
				{
					if(g[j]==-1)puts(ans[0]);
					else 
					{
						if(kroot==gr[g[j]])puts(ans[1]);
						else puts(ans[0]);
					}
				}
				else// g[k]!=-1
				{
					if(g[j]==-1)
					{
					   if(jroot==gr[g[k]])puts(ans[1]);
					   else puts(ans[0]);
					}
					else puts(ans[ jroot==gr[g[k]]||kroot==gr[g[j]] ]);
				}
			}
		}
	}
}
int main()
{
	//freopen("c:/acm/pku_1703.txt","r",stdin);
	//freopen("out1","w",stdout);
	solve();
	return 0;
}