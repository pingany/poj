#include<stdio.h>
#include<memory.h>
#include<algorithm>
using namespace std;
#define MAXM (24*24)
struct Stick
{
	int l,w;
};
Stick ss[MAXM];
int vis[MAXM];
bool cmp(const Stick & s1,const Stick & s2)
{
	if(s1.l==s2.l) return s1.w < s2.w;
	return  s1.l < s2.l;
}
int main()
{
	//freopen("c:/acm/pku_1548.txt","r",stdin);
	int ncase,n,i,j,t;
	int sum;

   while(scanf("%d%d",&ss[0].l,&ss[0].w) , ss[0].l!=-1 )
   {	   
	   i=1;
      while(scanf("%d%d",&ss[i].l,&ss[i].w),ss[i].l!=0)
	   {
		  ++i;
	   }
	   n=i;
	  memset(vis,0,sizeof(int)*n);
	  sum=n;
      
	  sort(ss,ss+n,cmp);
	  for(i=0;i<n-1;i++)
	   {
		  if(!vis[i])
		   {
			     t=ss[i].w;
				 for(j=i+1;j<n;j++)
				  {					 
					 if(!vis[j] &&ss[j].w >=t) 
					 {
						 vis[j]=1;
						 t=ss[j].w;
						 sum--;
					 }
				  }
		   }
	   }
	   printf("%d\n",sum);
   }
    return 0;
}