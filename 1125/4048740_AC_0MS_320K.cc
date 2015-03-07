#include<stdio.h>
#define MAXV 100
int a[MAXV+1][MAXV+1],d[MAXV+1][MAXV+1];
#define INF 1000001
int main()
{  
	//freopen("c:/acm/pku_1125.txt","r",stdin);
	int n,m,i,j,k,w,t;
	int totalmin,max;
	bool flag;
	while(scanf("%d",&n),n)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(i!=j)a[i][j]=INF;
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
				totalmin=INF;
				t=0;
				max=0;
				flag=true;
				for(i=1;i<=n;i++)
				{
					flag=true;
					max=-1;
					for(j=1;j<=n;j++)
					{
						if(d[i][j]>=INF) 
						{
							flag=false;
							break;
						}
						if( max< d[i][j])  max=d[i][j];
					}
					if(flag && (totalmin >max) ) 
					{
						t=i;
						totalmin=max;
					}
				}
				if(totalmin!=-1)printf("%d %d\n",t,totalmin);
				else printf("disjoint\n");
	}

	return 0;
}