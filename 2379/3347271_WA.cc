#include<iostream>
#include<algorithm>
using namespace std;
#define M 1001
#define MaxRun  1000
#define MaxProblem 20
struct Problem
{
	int time;
	bool  ac;
	Problem(){time=0;ac=false;}
};
struct Team
{
	Problem pro[MaxProblem];
	int nac;
	int number;
	int totaltime;
	Team(){nac=0;totaltime=0;}
};
struct Run
{
	int ci,pi,time,ac;
};
Team spaces[M];
Team  *team[M]={0};
Run runspaces[MaxRun];
Run *runs[MaxRun];
int nc,np=20;
int ci,pi,ti,accepted;

bool cmp(const Team*  t,const Team * s)
{
    if(t->nac!=s->nac)return t->nac > s->nac;
	if(t->totaltime!=s->totaltime)return t->totaltime < s->totaltime;
	return t->number < s->number;
}

bool cmp1(const Run * t,const Run *s)
{
	return t->time < s->time ||(t->time==s->time && t->ac > s->ac);
}
void solve()
{
	int i,j,ncase;
	int ci,pi,time,accepted;
	scanf("%d%d",&nc,&ncase);
	Problem *p;
	for(i=0;i<nc;i++) 
	{
		team[i]=&spaces[i];
		team[i]->number=i+1;
	}
	for(i=0;i<ncase;i++)
		runs[i]=&runspaces[i];
	for(i=0;i<ncase;i++)
		scanf("%d%d%d%d",&runs[i]->ci,&runs[i]->pi,&runs[i]->time,&runs[i]->ac);		

	sort(runs,runs+ncase,cmp1);
	for(i=0;i<ncase;i++)
	{
		ci=runs[i]->ci-1;
		pi=runs[i]->pi-1;
		time=runs[i]->time;
		accepted=runs[i]->ac;
		p=&(team[ci]->pro[pi]);
		if(!(p->ac))
		{
			if(accepted)
			{
				p->ac=true;
				p->time+=ti;
				team[ci]->nac++;
			}
			else 
				p->time+=20*60;
		}
	}
   for(i=0;i<nc;i++)
	   for(j=0;j<np;j++)
	{
	   p=&(team[i]->pro[j]);
	   if(p->ac)
		{
		   team[i]->totaltime+=p->time;
		}
	}
	sort(team,team+nc,cmp);
	printf("%d",team[0]->number);
	for(i=1;i<nc;i++)
	{
		printf(" %d",team[i]->number);
	}
}
int cmp2(int i,int j)
{
	return i<j;
}
void test()
{ int i;
	int a[]={5,4,2,1,3,7,8};
	sort(a,a+7,cmp2);
	for(i=0;i<7;i++)printf("%d ",a[i]);
}
int rand(int i,int j){return rand()%(j-i+1)+i;}
#include<time.h>
void create_test()
{
	srand(time(0));
	int nc=1000;
	int n=1000;
	printf("%d %d\n",nc,n);
	while(n--)
	{
		printf("%d %d %d %d\n",rand(1,nc),rand(1,20),rand(1,36000),rand(0,1));
	}
}
int main()
{	//freopen("c:/acm/acm_rank.txt","r",stdin);

	//freopen("c:/acm/acm_rank_out.txt","w",stdout);
	solve();

	//test();
//
//	freopen("c:/acm/acm_rank.txt","w",stdout);
//	create_test();
   return 0;
}