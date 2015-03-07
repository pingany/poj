#include<iostream>
#include<algorithm>
using namespace std;
#define MAXV 101
#define MAXE 10001
int  a[MAXV][MAXV];
int b[MAXV];
void simple_prim()
{
	int n,i,j,minw,minx,sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
	   for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	   int t=n-1;
	   memset(b,0,sizeof(int)*n);
	   b[0]=1;
	   while(t--)
	   {
		  int minw=1000001;
	      for(i=0;i<n;i++)
			  for(j=0;j<n;j++)
		   {
				if(b[i]==1 && b[j]==0   && a[i][j]<minw)
			   {
					minw=a[i][j];
					minx=j;
			   }
		   }
		   b[minx]=1;
		   sum+=minw;
	   }
	   printf("%d\n",sum);
	}
}
int main()
{
	//freopen("c:/acm/pku_1258.txt","r",stdin);
   simple_prim();
   return 0;
}
