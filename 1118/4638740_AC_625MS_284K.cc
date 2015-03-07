#include<stdio.h>
struct Point
{
  int x,y;
  };
 Point  ps[700];
int main()
{
	//freopen("d:/acm/pku_1118.txt","r",stdin);
     int n;
	 int   i,j,k;
	 int dx,dy,tx,ty;
	 int num;
	 int maxnum;
	 while(scanf("%d",&n),n)
	{
		 maxnum=0;
		  for(i=0;i<n;i++)
			  scanf("%d%d",&ps[i].x,&ps[i].y);
		  for(i=0;i<n-2;i++)
			  for(j=i+1;j<n-1;j++)
		{
			   num=2;
			   dx=ps[j].x-ps[i].x;
			   dy=ps[j].y-ps[i].y;
			   for(k=j+1;k<n;k++)
			{
				    tx=ps[k].x-ps[j].x;
					ty=ps[k].y-ps[j].y;
					if(dx*ty== dy*tx) num++;
			}
			if( num>maxnum)maxnum=num;
		}
		printf("%d\n",maxnum);
	}
}