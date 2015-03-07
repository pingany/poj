#include <iostream>
using namespace std;
#define MAX 100001


int n,m;


struct gao
{
	int a,b;
}c[MAX];


void build()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++)
	{
		c[i].a=i;
		c[i].b=0;
	}
}


void getroot(int x,gao &root)
{
	if(c[x].a==x)
	{
		root.b=0;
		root.a=x;
		return;
	}
	getroot(c[x].a,root);
	c[x].a=root.a;
	root.b+=c[x].b;
	c[x].b=root.b;
}


void solve()
{
	int p,q;
	gao x,y;
	char cc[2];
	while(m--)
	{
		scanf("%s",cc);
		scanf("%d%d",&p,&q);
		getroot(p,x);
		getroot(q,y);
		if(cc[0]=='D')
		{
			if(x.a!=y.a)
			{

					c[y.a].a=x.a;
					c[y.a].b=(x.b-y.b+1);

			}
		}
		else
		{
			if(x.a!=y.a)
				printf("Not sure yet.\n");
			else if((x.b-y.b)%2==0)
				printf("In the same gang.\n");
			else
				printf("In different gangs.\n");
		}
	}
}


int main()
{
	int k;
	scanf("%d",&k);
	while(k--)
	{
		build();
		solve();
	}
	return 0;
}
