#include<stdio.h>
#include<memory.h>
int a[1000002*2];
int main()
{
	int n,i,j,min,max,x,y;
  //freopen("c:/acm/pku_1089.txt","r",stdin);
  scanf("%d",&n);
  max=0;
  min=1000003;
  memset(a,0,sizeof(a));
   for(i=0;i<n;i++)
   {
   scanf("%d%d",&x,&y);
   if(x<min)min=x;
   if(y>max)max=y;
   for(j=x;j<y;j++) a[j*2]=1;
   for(j=x;j<=y;j++) a[j*2-1]=1;
   }
   for(i=min*2;i<max*2;i+=2)
	{
	   if(a[i]==1) a[i-1]=a[i+1]=1;
	}
   for(i=min*2-1;i<=max*2-1;i++)
	{
	   if(a[i]==1) 
	   { 
		   j=i;
		   while(a[j]==1)++j;
		   printf("%d %d\n",(i+1)/2,(j+1)/2);
		   i=j;
	   }

	}
	
  return 0;
  }