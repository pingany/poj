#include<stdio.h>
#include<string.h>
int n,m,cnt;
bool found;
char qi[20][21];
bool vis[20][21];
int si,sj;
void dfs(int i,int j)// i行j列
{
	vis[i][j]=true;
	++cnt;
	if(i-1>=0 && qi[i-1][j]=='.' && !vis[i-1][j])  dfs(i-1,j);
	if(i+1<n  && qi[i+1][j]=='.' && !vis[i+1][j])  dfs(i+1,j);
	if(j-1>=0 && qi[i][j-1]=='.' && !vis[i][j-1])  dfs(i,j-1);
	if(j+1<m  && qi[i][j+1]=='.' && !vis[i][j+1])  dfs(i,j+1); 
}
int main()
{
	//freopen("c:/acm/pku_1979.txt","r",stdin);
	int i;
	char *p;
   while(scanf("%d%d\n",&m,&n),m)
   {
	   found=false;
       for(i=0;i<n;i++)
       {
           gets(qi[i]);
			if(!found && 0!=(p=strchr(qi[i],'@') ) )
		   {
			    found=true;
				si=i;
				sj=p-qi[i];
		   }
       }
	   cnt=0;
	   memset(vis,0,sizeof(vis));
	   dfs(si,sj);
	   printf("%d\n",cnt);
   }
   return 0;
   }