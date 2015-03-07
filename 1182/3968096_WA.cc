#include<iostream>
using namespace std;
struct gao
{
	gao*root;
	int rank;
};
#define M 50001
gao  as[M];
int  n;
void init()
{
	int i;
	for(i=0;i<M;i++) 
	{
		as[i].root=as+i;
		as[i].rank=0;
	}
}
inline gao  * getroot(gao  *p)
{
	gao *q=p;
	while(p->root!=p)
	{
		p=p->root;
	}
	q->root=p;
	return p;
}
bool eat(int x,int y)
{
	if(x>n || y>n ) return false;
	if(x==y)return false;
	gao *p=getroot(&as[x]);
	gao *q=getroot(&as[y]);
	if(p==q)
	{
		int k=as[x].rank-as[y].rank;
		k=k%3;
		if(k<0)k+=3;
		return k==2;
	}
	else 
	{
		p->root=q;
		as[y].rank=as[x].rank+1;
		return true;
	}
}
bool same(int x,int y)
{
	if(x>n || y>n ) return false;
	gao *p=getroot(&as[x]);
	gao *q=getroot(&as[y]);
	if(p==q)
	{
		int k=as[x].rank-as[y].rank;
		k=k%3;
		return k==0;
	}
	else 
	{
		p->root=q;
		as[y].rank=as[x].rank;
		return true;
	}
}
void solve()
{
	int k,d,x,y;
	int jia=0;
	init();
	scanf("%d%d",&n,&k);
	while(k--)
	{
		scanf("%d%d%d",&d,&x,&y);
		if(d==1)
		{
			if(!same(x,y))  jia++;
		}
		else 
		{
			if(!eat(x,y)) jia++;
		}
	}
	printf("%d",jia);
}
int main()
{
	//freopen("c:/acm/pku_1182.txt","r",stdin);
    solve();
    return 0;
}