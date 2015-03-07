#include<iostream>
#include<queue>
using namespace std;
const int M =100001;
int vis[M];
int  n,k;
bool found;
int floor[M];
queue<int> que;
inline bool ok(int i)
{
	return i>=0 && i<M;
}
void bfs(int x)
{
	memset(vis,0,sizeof(vis));
    que.push(x);
	vis[x]=1;
	floor[x]=0;
	while(!que.empty())
	{
		x=que.front();
		que.pop();
		if(x==k)
		{
			found=true;
			printf("%d",floor[x]);
			return ;
		}
		if(ok(x-1) && !vis[x-1])
		{
			vis[x-1]=1;
			floor[x-1]=floor[x]+1;
			que.push(x-1);
		}
		if(ok(x+1) && !vis[x+1])
		{
			vis[x+1]=1;
			floor[x+1]=floor[x]+1;
			que.push(x+1);
		}
		if(ok(x*2) && !vis[x*2])
		{
			vis[x*2]=1;
			floor[x*2]=floor[x]+1;
			que.push(x*2);
		}
	}

}
void solve()
{
	found=false;
	scanf("%d%d",&n,&k);
	bfs(n);
}
int main()
{
	//freopen("c:/acm/pku_3278.txt","r",stdin);
	solve();
	return 0;
}