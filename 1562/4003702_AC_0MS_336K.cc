#include<stdio.h>
#include<memory.h>
#define M 100
#define N 100
char  a[M+1][N+1];
bool vis[M+1][N+1];
int n,m;
#define W  '@'
inline bool ok(int i,int j)
{
	return 
	   i>=0 && i<n
		&& j>=0 && j<m
		&& a[i][j]==W && !vis[i][j];
}
void dfs(int i,int j)
{
	 vis[i][j]=true;
	 if(ok(i-1,j))		dfs(i-1,j);
	 if(ok(i-1,j-1))	dfs(i-1,j-1);
	 if(ok(i-1,j+1))	dfs(i-1,j+1);
	 if(ok(i,j-1))		dfs(i,j-1);
	 if(ok(i,j+1))		dfs(i,j+1);
	 if(ok(i+1,j-1))	dfs(i+1,j-1);
	 if(ok(i+1,j))		dfs(i+1,j);
	 if(ok(i+1,j+1))	dfs(i+1,j+1);
}

int main()
{
	int  cnt=0;
	int i,j;
	//freopen("c:/acm/pku_1562.txt","r",stdin);
	while(scanf("%d%d\n",&n,&m),n)
	{
		cnt=0;
	for(i=0;i<n;i++)gets(a[i]);
	memset(vis,0,sizeof(vis));
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
	{
		if(a[i][j]==W && !vis[i][j])
		{dfs(i,j);
		cnt++;
		}
	}
	printf("%d\n",cnt);
	}
	return 0;

}