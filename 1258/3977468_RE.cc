#include<iostream>
#include<algorithm>
using namespace std;
#define MAXV 101
#define MAXE 10001
struct Edge
{
	int u,v,w;
};
Edge ss[MAXE],*es[MAXE];
int  a[MAXV][MAXV];
int  root[MAXV];
int getroot(int i)
{
	int k=i;
	while(root[i]!=i)
	{
		i=root[i];
	}
	root[k]=i;

	return i;
}
inline bool cmp(const Edge * e1, const Edge *e2)
{
	return e1->w <=e2->w;
}
void solve()
{

	int n,i,j,ri,rj,sp,x;
	
	for(i=0;i<MAXE;i++) es[i]=&ss[i];
	while(scanf("%d",&n)!=EOF)
	{
		int sum=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
		root[i]=i;
	sp=-1;
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
	{
		++sp;
		  es[sp]->u=i;
		  es[sp]->v=j;
		  es[sp]->w=a[i][j];
	}
	sort(es,es+sp+1,cmp);
	x=0;
	for(i=0;i<=sp;++i)
	{
		ri=getroot(es[i]->u);
		rj=getroot(es[i]->v);
		if(ri==rj)continue;
		else
		{
			root[ri]=rj;
			sum+=es[i]->w;
			x++;
			if(x==n-1) break;
		}
	}
	printf("%d\n",sum);
	}
}

int main()
{
	//freopen("c:/acm/pku_1258.txt","r",stdin);
   solve();
   return 0;
  }