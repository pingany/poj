#include<iostream>
#include<cstdio>
using namespace std;
#define M 26
inline int hash(char c){return c-'A';}
int g[M][M];
int m,n;
char s[4];
int showed[M];
int deg[M];
int insdeg[M];

typedef enum{GRAY,BLACK,WHITE} Color;
Color color[M];
bool nohuan=true;
bool dfs(int i);
bool  no_huan()
{
	int i;
	nohuan=true;;
	for(i=0;i<n;i++)color[i]=WHITE;
	for(i=0;i<n;i++)
	{
		if(color[i]==WHITE)
		{ if( !dfs(i))return false;}
	}
	return true;
}
bool dfs(int i)
{
	int j;
	if(!nohuan)return false;
	color[i]=GRAY;
	for(j=0;j<n;j++)
		if(g[i][j])
		{
			if(color[j]==WHITE) dfs(j);
			else if(color[j]==GRAY) return nohuan=false;
		}
		color[i]=BLACK;
		return true;
}


int vis[M];
char orders[M];
int osp=-1;
//typedef enum{CT,OK,UN}Status;
bool issorted()
{
	int c=0;
	int k=0;
	int i;
	for(i=0;i<0;i++)
	{
		if(deg[i]==0)
		{
			if(c==0)
			{
				c=1;
				k=i;
			}
			else 
			{
				return false;
			}
		}
	}
	memcpy(insdeg,deg,sizeof(deg));
	memset(vis,0,sizeof(vis));
	osp=-1;
	orders[0]=0;
	vis[k]=1;
	int nc=n,j=-1;
	while(nc--)
	{
		orders[++osp]=k+'A';
		c=0;
		for(i=0;i<n;i++)
		{
			if(g[k][i])
			{
				deg[i]--;
				if(deg[i]==0)
				{
					if(c==0)
					{
						c=1;
						j=i;
					}
					else return false;
				}
			}
		}
		k=j;
	}
	orders[++osp]=0;
	//if(j==-1) return 
	return true;
}
bool solve()
{
	int i,j,c=0;
	int index;
	scanf("%d %d\n",&n,&m);
	if(n==0)return false;
	memset(g,0,sizeof(g));
	memset(showed,0,sizeof(int)*n);
	memset(deg,0,sizeof(int)*n);
	bool ok=false;
	for(index=0;index<m;index++)
	{
		gets(s);
		if(ok)continue;
		i=hash(s[0]);
		j=hash(s[2]);
		if(g[i][j]!=1)
		{
			deg[j]++;
			g[i][j]=1;
			if(!showed[i]){showed[i]=1;c++;}
			if(!showed[j]){c++;showed[j]=1;}
			//判断有没有环
			if(!no_huan())
			{
				ok=true;
				printf("Inconsistency found after %d relations.\n",index+1);
			}
			if(c==n)
			{//判断是不是sorted了
				if(issorted())
				{
					printf("Sorted sequence determined after %d relations: %s.\n",index+1,orders);
					ok=true;
				}
			}			
		}
	}
	if(!ok)printf("Sorted sequence cannot be determined.\n");
	return true;
}
int main()
{
	//freopen("c:/acm/pku_1094.txt","r",stdin);
	while(solve());
	return 0;
}