#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define M 1000
const double eps=1e-7;
struct E
{
	double x,y;
};
E stack[M];
int sp=-1;
int n=1,d;
const int INF=1000000000;
inline double msqrt(double x){return sqrt(x);}
bool cmpe(const E&e,const E&f)
{
	return e.x-f.x<=0;
}
int  doublecmp(double x,double y)
{
	if(fabs(x-y)<eps)return 0;
	else if(x-y>0)return 1;
	return -1;
}
void solve()
{
	sp=-1;
	static int index=0;
	index++;
	bool error=false;
	scanf("%d%d",&n,&d);
	if(n==0)return ;
	int i, x,y;
	if(d<0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
		}
		printf("Case %: %d\n",index,-1);
	}
	else 
	{
		int cnt=0;
		double t;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			if(error)continue;
			t=d*d-y*y;
			if(t<0) error=true;
			t=msqrt(t);
			sp++;
			stack[sp].x=x-t;
			stack[sp].y=x+t;
		}
		if(error){printf("Case %: %d\n",index,-1); return ;}
		sort(stack,stack+sp+1,cmpe);
		int i;
		double k=-INF;
		for(i=0;i<=sp;i++)
		{
			if(doublecmp(stack[i].x,k)>0)
			{
						cnt++;
						k=stack[i].y;
			}
			else 
			{
				if(doublecmp(stack[i].y,k)<0) k=stack[i].y;
			}
		}
		printf("Case %d: %d\n",index,cnt);
	}
}
int main()
{
	//freopen("c:/acm/radar_install.txt","r",stdin);
	while(n!=0)
	{
		solve();
	}
	return 0;
}