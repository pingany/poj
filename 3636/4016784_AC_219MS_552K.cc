#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<functional>
using namespace std;
#define MAXM 20000
struct Stick
{
	int l,w;
};
Stick ss[MAXM];
int vis[MAXM];
bool cmp(const Stick & s1,const Stick & s2)
{
	if(s1.l==s2.l) return s1.w > s2.w;
	return  s1.l < s2.l;
}
int opt[MAXM];
int main()
{
	//freopen("c:/acm/pku_1065.txt","r",stdin);
	int ncase,n,i,j,w,l;
	int sum;
   scanf("%d",&ncase);
   while(ncase--)
   {	   
      scanf("%d",&n);
	  
	  sum=n;
      for(i=0;i<n;i++)scanf("%d%d",&ss[i].l,&ss[i].w);
	  sort(ss,ss+n,cmp);
	  /*
	  memset(vis,0,sizeof(int)*n);
	  for(i=0;i<n-1;i++)
	   {
		  if(!vis[i])
		   {
			     w=ss[i].w;
				// l=ss[i].l;
				 for(j=i+1;j<n;j++)
				  {					 
					 if(!vis[j]  && ss[j].w >w) 
					 {
						 vis[j]=1;
						 w=ss[j].w;
						 //l=ss[j].l;
						 sum--;
					 }
				  }
		   }
	   }
	   printf("%d ",sum);
	   */
	   int len=0;
	   for(i=0;i<n;i++)
	   {
		   j=upper_bound(opt,opt+len,ss[i].w,greater<int>())-opt;
		   if(j==len) ++len;
		   opt[j]=ss[i].w;
	   }
	   printf("%d\n",len);
	   
   }
    return 0;
}