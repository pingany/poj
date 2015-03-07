#include<stdio.h>
#include<memory.h>
int a[1000002];
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
   for(j=x;j<y;j++)a[j]=1;
   }
   for(i=min;i<max;i++)
	{
	   if(a[i]==0) break;
	}
	j=i;
	for(++i;i<max;i++)
	{
		if(a[i]==1)break;
	}
	printf("%d %d\n%d %d\n",min,j,i,max);
  return 0;
  }