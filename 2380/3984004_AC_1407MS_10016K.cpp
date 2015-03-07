#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 500000
struct Sale
{
	int iid,sid,num;
};
Sale   ss[N] ,*ps[N];
int    items[N];
int	   sps[N];
int    iis[N];
inline bool cmp(const Sale *p,const Sale *q)
{
	if(p->sid < q->sid) return true;
	else if(p->sid==q->sid)return p->iid < q->iid;
	return false;
}
int main()
{
	//freopen("c:/acm/pku_2380.txt","r",stdin);
	int i,n,j,ni,t,ns,k;
      for(i=0;i<N;i++)  ps[i]=&ss[i];
     scanf("%d",&n);
     for(i=0;i<n;i++)
	{
         scanf("%d%d%d",&ps[i]->iid,&ps[i]->sid,&ps[i]->num);
		 iis[i]=ps[i]->iid;
	}
	sort(iis,iis+n);
	  
	  ni=1;
	  items[0]=iis[0];
	  for(i=1;i<n;i++) 
	{
		  if(iis[i]!=iis[i-1]) ni++; //求总的item种类数量
		  items[ni-1]=iis[i];
	}

	 sort(ps,ps+n,cmp);
	 sps[0]=ps[0]->sid;
	 ns=1;
	 for(i=1;i<n;i++)
	{
		 if(ps[i]->sid!=ps[i-1]->sid) ns++;
		 sps[ns-1]=ps[i]->sid;
	}
		
	 printf("-1");
	 for(i=0;i<ni;i++)printf(" %d",items[i]);
	 printf("\n");
	 k=0;
	 for(i=0;i<ns;i++)
	{
		 printf("%d",sps[i]);
		 for(j=0;j<ni;j++)
		{
			 t=0;
			 while(k<n&& ps[k]->sid==sps[i] &&  ps[k]->iid==items[j])
			{
				 t+=ps[k]->num;
				 ++k;
			}
			printf(" %d",t);
		}
		printf("\n");
	}

	 return 0;
}