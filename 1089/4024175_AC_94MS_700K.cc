#include<stdio.h>
#include<algorithm>
using namespace std;
struct yi
{
	int x,y;
};
yi a[50001];
inline bool cmp(const yi & y1,const yi & y2)
{
	return y1.x<y2.x;
}
int main()
{
	int n,i,min,max;
  //freopen("c:/acm/pku_1089.txt","r",stdin);
  scanf("%d",&n);
   for(i=0;i<n;i++)
   {
     scanf("%d%d",&a[i].x,&a[i].y);
   }
   sort(a,a+n,cmp);
   min=a[0].x;
   max=a[0].y;
   for(i=1;i<n;i++)
	{
	   if(a[i].x> max) 
		{
		   printf("%d %d\n",min,max);
			min=a[i].x;
			max=a[i].y;
		}
	   else if(a[i].y> max) max=a[i].y;
	}
	printf("%d %d\n",min,max);
   return 0;
}