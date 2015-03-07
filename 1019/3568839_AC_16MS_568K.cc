#include<stdio.h>
#include<math.h>
typedef long long LONG;
// LONG MAX=(1<<31)-1;
const int  MAX_X=31268;
int  f[MAX_X+1];
int  s[MAX_X+1];
int pow10[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
inline int getn(int x)
{
	return (int)log10((float)x)+1;
}
inline int fx(int x)
{
	 int n=getn(x);
	 return  n*x+n-1-(pow10[n]-10)/9;
}
/*
void test()
{
	 LONG i,s=0,x;
	 for(i=1;;i++)
	 {
		 x=fx(i);
		 if(s+x<=MAX) s+=x;
		 else break;
	 }
	 printf("%lld %lld",i,s);
}*/
void init()
{
	int i;
	 s[1]=f[1]=1;
	 for(i=2;i<=MAX_X;i++) 
	 {
		 f[i]=fx(i);
		 s[i]=s[i-1]+f[i];
	 }
}
void solve(int pos)
{
   int left,right,mid;
   left=1;
   right=MAX_X;
   while(left<right)
   {
		mid=(left+right)/2;
		if(s[mid]==pos){right=mid;break;}
		else if(s[mid]<pos) left=mid+1;
		else right=mid;
   }
   pos-=s[right-1];
   left=1;
   right=MAX_X;
   while(left<right)
   {
		mid=(left+right)/2;
		if(f[mid]==pos){right=mid;break;}
		else if(f[mid]<pos) left=mid+1;
		else right=mid;
   }
   pos-=f[right-1];
   int n=getn(right);
   printf("%d\n",right%pow10[n-pos+1]/pow10[n-pos]);
}
int main()
{
	//freopen("c:/acm/pku_1019.txt","r",stdin);
	int ncase,n;
	init();
	scanf("%d",&ncase);
	while(ncase--)
	{
		scanf("%d",&n);
		solve(n);
	}
}
