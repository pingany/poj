#include<iostream>
#include<cstdio>
using namespace std;
#define maxv 100001
int root[maxv];
int index=0;
inline int getroot(int i){
	if(i==root[i])return root[i];
	return getroot(root[i]);
}
int g[maxv];
char *ans[]={"Not sure yet.",
"In different gangs.",
"In the same gang."
};
void solve()
{
	int ncase,m,n,i,j,k,kroot,jroot;
	bool bad=false;
	scanf("%d",&ncase);
	char op;
	while(ncase--)
	{
		
		bad=false;
		scanf("%d%d\n",&m,&n);
		memset(g,-1,sizeof(int)*(m+1));
		for(i=1;i<=m;i++)root[i]=i;
		for(i=0;i<n;i++)
		{
			scanf("%s",&op);
			scanf("%d%d\n",&k,&j);
			kroot=getroot(k);
			jroot=getroot(j);
			if(op=='D')
			{
				if(g[k]==-1)g[k]=j;
				else 
				{
					root[jroot]=root[getroot(g[k])];
				}
				if(g[j]==-1)g[j]=k;
				else 
				{
					root[kroot]=root[getroot(g[j])];
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
						if(kroot==getroot(g[j]))puts(ans[1]);
						else puts(ans[0]);
					}
				}
				else// g[k]!=-1
				{
					if(g[j]==-1)
					{
					   if(jroot==getroot(g[k]))puts(ans[1]);
					   else puts(ans[0]);
					}
					else puts(ans[ jroot==getroot(g[k])||kroot==getroot(g[j]) ]);
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