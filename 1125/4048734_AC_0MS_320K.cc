#include<stdio.h>
#define MAXV 100
int a[MAXV+1][MAXV+1],d[MAXV+1][MAXV+1];
int main()
{  
	//freopen("c:/acm/pku_1125.txt","r",stdin);
	int n,m,i,j,k,w,t;
	int totalmin,max;
   while(scanf("%d",&n),n)
   {
	   for(i=1;i<=n;i++)
		   for(j=1;j<=n;j++)
		       if(i!=j)a[i][j]=1000001;
				else a[i][j]=0;
    for(i=1;i<=n;i++)
    {
       scanf("%d",&m);
       for(j=0;j<m;j++)
       {
          scanf("%d%d",&k,&w);
		  a[i][k]=w;
       }
    }
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		 d[i][j]=a[i][j];
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(d[i][k]+d[k][j]< d[i][j])
				d[i][j]=d[i][k]+d[k][j];
	totalmin=0;
	t=0;
	max=0;
	for(i=1;i<=n;i++)
	   {
		  max=-1;
		  for(j=1;j<=n;j++)
			  if( max< d[i][j])  max=d[i][j];
		  if(i==1 || totalmin >max) 
		   {
			  t=i;
			  totalmin=max;
		   }
	   }
	   printf("%d %d\n",t,totalmin);
   }

   return 0;
   }