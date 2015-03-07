#include<stdio.h>
#include<stdlib.h>
#define MAX 200
inline void swap(int &x,int &y)
{
	int t=x;
	x=y;
	y=t;
}
int gcd(int x,int y)
{
	if(x<y) swap(x,y);
	if(y==0)return x;
	return gcd(y,x%y);
}
int solve()
{
	int m,n,l,x,y;
	int t,mn,xy,c;
	scanf("%d%d%d%d%d",&x,&y,&m,&n,&l);
	mn=m-n;
	xy=y-x;
	c=gcd(abs(mn),abs(l));
	if(xy%c!=0)return -1;
	for(t=0;;t+=1)
	{
		if((mn*t-xy)%l==0)break;
	}
	return t;
}

int main()
{
	int r;
	//freopen("c:/acm/pku_1061.txt","r",stdin);
		r=solve();
		if(-1==r)printf("Impossible");
		else printf("%d",r);
		while(1);
		return 0;
}
