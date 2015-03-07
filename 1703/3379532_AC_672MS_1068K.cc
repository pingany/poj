#include<stdio.h>
#include<memory.h>
#define maxv 100001
char *ans[]={"Not sure yet.",
"In different gangs.",
"In the same gang."
};
struct gao
{
	int a,b;//b=  c[a]与c[c[a].a]，即c[a]与其上层的距离
};
gao c[maxv];
inline void build(int first,int end)
{
	int i;
	for(i=first;i<=end;i++)
	{
		c[i].a=i;
		c[i].b=0;
	}
}
inline int getroot(int k)//得到各自的root的编号
{
	int i=k;
	while(i!=c[i].a)
	{
		i=c[i].a;
		c[k].b+=c[i].b;//路径压缩
	}
	c[k].a=i;//路径压缩
	return i;
}
inline void uni(int k,int j,int kroot=0,int jroot=0)
{
            if(!kroot) kroot=getroot(k);
			if(!jroot) jroot=getroot(j);
			if(kroot!=jroot)//不是已经属于同一个集合
			{
					c[jroot].a=c[kroot].a;
					c[jroot].b=c[k].b-c[j].b+1;
			}
}
void solve()
{
	int ncase,m,n,i,j,k,kroot,jroot;
	char op;
	scanf("%d\n",&ncase);
	while(ncase--)
	{
		scanf("%d %d\n",&m,&n);
		build(1,m);
		for(i=0;i<n;i++)
		{
			scanf("%s %d %d\n",&op,&k,&j);
		//	if(k>j)swap(k,j);
			kroot=getroot(k);
			jroot=getroot(j);
			if(op=='D')
			{
				uni(k,j,kroot,jroot);
			}
			else 
			{				
				if(kroot!=jroot)puts(ans[0]);
				else if((c[k].b-c[j].b) & 1)puts(ans[1]);
				else puts(ans[2]);
			}
		}

	}
}
int main()
{
	
	//freopen("c:/acm/pku_1703.txt","r",stdin);
	//freopen("out1","w",stdout);

	solve();
	return 0;
}