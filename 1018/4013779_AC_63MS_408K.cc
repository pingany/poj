#include<stdio.h>
#include<algorithm>
using namespace std;
#define M 100
int  ncase;
int  ms[M];
int  n;
struct Dev
{
	int b,p;
};
Dev  a[M][M];
inline bool cmp(const Dev & d1,const Dev  &d2)
{
	return d1.b< d2.b;
}
class Cmp
{
	public:
	 bool operator()(const Dev & d1,const Dev & d2)const
	{
	  return d1.b< d2.b;
	}
};
int   mb,mp;
void  test(int brand)
{
	Dev  dev;
	dev.b=brand;
	int i=0,j,p=0;
	for(i=0;i<n;i++)
	{
		j=lower_bound(a[i],a[i]+ms[i],dev,Cmp())-a[i];
		if(j>=ms[i]) return ;//没有这么高的brand
		p+=a[i][j].p;
	}
	if(mb*p < brand*mp)
	{
		mb=brand;
		mp=p;
	}
}	
int main()
{
	int i,j,t;
   //freopen("c:/acm/pku_1018.txt","r",stdin);
   scanf("%d",&ncase);
   while(ncase--)
   {
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
       scanf("%d",&ms[i]);
       t=ms[i];
       for(j=0;j<t;++j)
       {
         scanf("%d%d",&a[i][j].b,&a[i][j].p);
       }
	   sort(a[i],a[i]+t,cmp);
	   for(j=t-2;j>=0;--j)
		 {
		   a[i][j].p=min(a[i][j].p , a[i][j+1].p);
		 }
     }
	 mb=0;
	 mp=1;
	 for(i=0;i<n;i++)
		 for(j=0;j<ms[i];j++)
	   {
		 test(a[i][j].b);
	   }
	   printf("%.3f\n",(mb+0.0)/mp);
   }
   return 0;
  }