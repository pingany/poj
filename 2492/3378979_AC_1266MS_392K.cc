#include<iostream>
#include<cstdio>
using namespace std;
#define maxv 2002
int root[maxv];
char buffer[100];
int index=0;
inline int getroot(int i){
	if(i==root[i])return root[i];
	return getroot(root[i]);
}
int g[maxv];
void solve()
{
	int ncase,m,n,i,j,k,kroot,jroot;
	bool bad=false;
	scanf("%d",&ncase);
	while(ncase--)
	{
		
		bad=false;
		scanf("%d%d\n",&m,&n);
		memset(g,-1,sizeof(int)*(m+1));
		for(i=1;i<=m;i++)root[i]=i;
		for(i=0;i<n;i++)
		{
			
			if(!bad)
			{		
				scanf("%d%d\n",&k,&j);
				kroot=getroot(k);
				jroot=getroot(j);
				if(kroot==jroot){bad=true;}
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
			else scanf("%d%d\n",&k,&j);
			
		}
		if(bad){printf("Scenario #%d:\nSuspicious bugs found!\n",++index);}
		else printf("Scenario #%d:\nNo suspicious bugs found!\n",++index);
		//if(ncase!=0)
			printf("\n");
	}
}
int main()
{
	//freopen("c:/acm/pku_2492.txt","r",stdin);
	//freopen("out1","w",stdout);
	solve();
	return 0;
}