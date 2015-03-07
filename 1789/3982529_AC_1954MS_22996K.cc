#include<stdio.h>
#include<algorithm>
using namespace std;

char a[2000][8];
struct Edge
{
	int u,v,w;
};
Edge   es[2000*1999/2];
inline int dis(char  *s,char *d)
{
	int sum=0;
	 while(*s)
	{
		if(*d!=*s)  sum++;
		++s;
		++d;
	}
	return sum;
}
int root[2000];
inline int getroot(int i)
{
	int k=i;
	while(root[i]!=i)
		i=root[i];
	root[k]=i;
	return i;
}
inline bool cmp(const Edge &e1,const Edge & e2)
{
	return e1.w <e2.w;
}
int main()
{
	//freopen ("c:/acm/pku_1789.txt","r",stdin);
	int n,i,j,sp,d,sum,ru,rv;
    while(scanf("%d\n",&n),n)
    {
          for(i=0;i<n;i++)gets(a[i]);
    
	sp=-1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			d=dis(a[i],a[j]);
			if(d!=0)
			{
				++sp;
				es[sp].u=i;
				es[sp].v=j;
				es[sp].w=d;
			}
		}
	}
	sort(es,es+sp+1,cmp);
	sum=0;
	for(i=0;i<n;i++)root[i]=i;
	for(i=0;i<=sp;i++)
		{
		      ru=getroot(es[i].u);
			  rv=getroot(es[i].v);
			  if(ru!=rv)
			{
				  root[ru]=rv;
				  sum+=es[i].w;
			}
		}
     printf("The highest possible quality is 1/%d.\n",sum);	


	}
	return 0;
}