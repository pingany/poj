#include<stdio.h>
#define N  30001
int root[N];
int rank[N];
int subnum[N];

int getroot(int i)
{
	int k=i;
	int c=0;
	while(i!=root[i])
	{
		c+=rank[i];
		i=root[i];
	}
	rank[k]=c;
	root[k]=i;
	return i;
}
void uni(int i,int j)
{
	root[i]=j;
	rank[i]=subnum[j]+1;
	subnum[j]+=subnum[i]+1;
}

int main()
{
	//freopen("c:/acm/pku_1988.txt","r",stdin);
	int i,p;
	char c[2];
	int x,y;
	  scanf("%d",&p);
	  for(i=0;i<N;i++)
	{
		  root[i]=i;
		  rank[i]=0;
		  subnum[i]=0;
	}
	  while(p--)
	{
		  scanf("%s",c);
		  if('M'==*c)
		{
			  scanf("%d%d",&x,&y);
			  uni(getroot(y),getroot(x));
		}
		else
		{
			 scanf("%d",&x);
			 printf("%d\n",subnum[getroot(x)]-rank[x]);
		}
	}
	  return 0;
}