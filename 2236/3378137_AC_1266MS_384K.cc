#include<iostream>
#include<cstdio>
using namespace std;
#define M 1002
int root[M];
char *flag[]={"FAIL","SUCCESS"};
struct Point 
{
	int x,y;
};
Point p[M];
int status[M];
int n,d,d2;
inline int dis2(Point &p,Point &q ){
	int x=p.x-q.x,y=p.y-q.y;
	return x*x+y*y;
}
inline int getroot(int i){
	if(i==root[i])return root[i];
	return getroot(root[i]);
}
void solve()
{
	int i,j,k,iroot,jroot;
	char op;
	scanf("%d%d",&n,&d);
	d2=d*d;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		root[i]=i;
		status[i]=0;
	}
	while(scanf("%s",&op)!=EOF)
	{
		if(op=='O')
		{
			scanf("%d",&i);
			status[i]=1;
			for(j=1;j<=n;j++)
			{
				iroot=getroot(i);
				jroot=getroot(j);
				if(iroot==jroot)continue;
				if(status[j]==1 && dis2(p[i],p[j])<=d2)
				{
					root[iroot]=root[jroot];
				}
			}
		}
		else 
		{
			scanf("%d%d",&i,&k);
			printf("%s\n",flag[getroot(i)==getroot(k)]);
		}
	}
}
int main()
{
	//freopen("c:/acm/bingcha.txt","r",stdin);
	solve();
	return 0;
}