#include<iostream>
#include<cstdio>
using namespace std;
#define M 100
const int INF=256*256*3;
int targets[16][3];
int n=16;
int c[3],t[3];
void input()
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&targets[i][0],&targets[i][1],&targets[i][2]);
	}
}
inline void print(int a[],int b[])
{
	printf("(%d,%d,%d) maps to (%d,%d,%d)\n",a[0],a[1],a[2],b[0],b[1],b[2]);
}
inline int dist2(int a[],int b[])
{
	int x=a[0]-b[0],y=a[1]-b[1],z=a[2]-b[2];
	return x*x+y*y+z*z;
}
void solve()
{
	input();
	int maxf,i,d;
	while(scanf("%d%d%d",c,c+1,c+2),c[0]!=-1)
	{
		maxf=INF;
		for(i=0;i<n;i++)
		{
		     d=dist2(targets[i],c);
			 if(d<maxf)
			{
				 maxf=d;
				 memcpy(t,targets[i],sizeof(t));
			}
		}
		print(c,t);
	}
}
int main()
{
	//freopen("c:/acm/color_less.txt","r",stdin);
	solve();
   return 0;
}