#include<iostream>
#include<cstdio>
using namespace std;
#define M 100
int a[M][M];
int dist[M][M];
int ii,jj,r,c;
void input()
{
	int i,j,maxh=-1;
		scanf("%d%d",&r,&c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
				scanf("%d",&a[i][j]);
				if(a[i][j]>maxh)
			{
					maxh=a[i][j];
					ii=i;
					jj=j;
			}
		memset(dist[i],-1,sizeof(int)*c);
		}
	}
}
int height(int i,int j)
{
   if(dist[i][j]!=-1)return dist[i][j];
   int maxh=1,h;
   if(i>0 &&a[i][j]>a[i-1][j])
	{
	   h=height(i-1,j)+1;
	   if(h>maxh)maxh=h;
	}
	if(i<r-1 &&a[i][j]>a[i+1][j])
	{
		h=height(i+1,j)+1;
		if(h>maxh)maxh=h;
	}
	if(j>0 &&a[i][j]>a[i][j-1])
	{
		h=height(i,j-1)+1;
		if(h>maxh)maxh=h;
	}
	if(j<c-1&&a[i][j]>a[i][j+1])
	{
		h=height(i,j+1)+1;
		if(h>maxh)maxh=h;
	}
	return  dist[i][j]=maxh;
}
void solve()
{
	input();
	printf("%d",height(ii,jj));
}
int main()
{
	freopen("c:/acm/skating.txt","r",stdin);
	solve();
   return 0;
}