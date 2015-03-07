#include<stdio.h>
#include<memory.h>
struct Order
{
	int s,e,np,prof;
};
#define MAXO 22
Order orders[MAXO],*pos[MAXO];
int  maxprof;
int  ncap,nst,norder;
int  stnum[10];
int  totalprof;
int  leftprof;
int  curprof;
inline bool canplace(int k)
{
	int  s=pos[k]->s, e=pos[k]->e ,i , np=pos[k]->np;
	for(i=s;i<e;i++)
	{
			if(stnum[i]+np >ncap) return false;
	}
	return true;
}
inline void place(int k)
{
	int  s=pos[k]->s, e=pos[k]->e ,i , np=pos[k]->np;
	for(i=s;i<e;i++)
	{
		stnum[i]+=np;
	}
	curprof+=pos[k]->prof;
}
inline void unplace(int k)
{
	int  s=pos[k]->s, e=pos[k]->e ,i , np=pos[k]->np;
	for(i=s;i<e;i++)
	{
		stnum[i]-=np;
	}
	curprof-=pos[k]->prof;
}
void  backt(int k)
{
	
	if(k==norder)
	{
		if(curprof>maxprof) maxprof=curprof;
		return ;
	}
	int t=leftprof;
	leftprof=t- pos[k]->prof;
	if(curprof+leftprof > maxprof) //否则 利润赚不够了
	{ 
		backt(k+1);
	}
	leftprof=t- pos[k]->prof;
	if(canplace(k))
	{
		place(k);
		backt(k+1);
		unplace(k);
	}
	leftprof=t;
}
int main()
{
	//freopen("c:/acm/pku_1040.txt","r",stdin);
	//freopen("c:/out.txt","w",stdout);
	int i,t;
	int in,k;
	for(i=0;i<MAXO;i++)pos[i]=&orders[i];
    while(scanf("%d%d%d",&ncap,&nst,&in), ncap||nst||in )
    {
		maxprof=0;
		totalprof=0;
		norder=in;
		k=0;
		for(i=0;i<in;i++)
		{
			scanf("%d%d%d",&pos[k]->s,&pos[k]->e,&pos[k]->np);
			pos[k]->prof=t=(pos[k]->e - pos[k]->s) * pos[k]->np;
			if(pos[k]->np > ncap)
			continue;
			++k;
			if(maxprof<t) maxprof=t;
			totalprof+=t;
		}
		norder=k;
		leftprof=totalprof;
		curprof=0;
		memset(stnum,0,sizeof(stnum));
		backt(0);
		printf("%d\n",maxprof);
	}
    return 0;
    }