#include<iostream>
#include<cstdio>
using namespace std;
#define M 5
int root[M];
char buffer[100];
int index=0;
void solve()
{
	int ncase,m,n,i,j,k;
	bool bad=false;
	scanf("%d",&ncase);
	while(ncase--)
	{
		bad=false;
		scanf("%d%d",&m,&n);
		for(i=1;i<=m;i++)root[i]=-1;
		for(i=0;i<n;i++)
		{
			if(!bad)
			{
			scanf("%d%d\n",&k,&j);
			if(root[k]==-1 )
			{
				if(root[j]==-1){root[j]=0;root[k]=1;}
				else {root[k]=1-root[j];}
			}
			else 
			{
				if(root[j]==-1){root[j]=1-root[k];}
				else if(root[j]==root[k]){ bad=true;break;}
			}
			}
			else gets(buffer);//废弃
		}
		if(bad){printf("Scenario #%d:\nSuspicious bugs found!\n",++index);}
		else printf("Scenario #%d:\nNo suspicious bugs found!\n",++index);
		if(ncase!=0)printf("\n");
	}
}
int main()
{
	//freopen("c:/acm/pku_2492.txt","r",stdin);
	//freopen("out1","w",stdout);
	solve();
   return 0;
}