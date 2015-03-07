#include<iostream>
#include<algorithm>
using namespace std;
#define M 1000
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
Team spaces[M];
Team  *team[M]={0};
int nc,np=20;
int ci,pi,ti,accepted;

bool cmp(const Team*  t,const Team * s)
{
    if(t->nac!=s->nac)return t->nac > s->nac;
	if(t->totaltime!=s->totaltime)return t->totaltime < s->totaltime;
	return t->number < s->number;
}

void solve()
{
	int i,j,ncase;
	scanf("%d%d",&nc,&ncase);
	Problem *p;
	for(i=0;i<nc;i++) 
	{
		team[i]=&spaces[i];
		team[i]->number=i+1;
	}
	while(ncase)
	{ncase--;
		scanf("%d%d%d%d",&ci,&pi,&ti,&accepted);
		ci--;
		pi--;
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
int main()
{
	//freopen("c:/acm/acm_rank.txt","r",stdin);
	solve();
	//test();
   return 0;
}