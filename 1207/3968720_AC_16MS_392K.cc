#include<iostream>
using namespace std;
int getlen(int n)
{
	 int i=0;
   while(n!=1)
   {
     if(n & 1) //奇数
	n=n*3+1;
     else n>>=1;
     ++i;
   }
   return i+1;
}
void  solve()
{
	int x,y,i,j,k,t,maxlen;
	while(scanf("%d%d",&x,&y)==2)
	{
		if(x<y){i=x;j=y;}
		else {i=y;j=x;}
		maxlen=0;
		for(k=i;k<=j;k++)
		{
				t=getlen(k);
				if(  maxlen< t)
					maxlen=t;
		}
		printf("%d %d %d\n",x,y,maxlen);
	}
}
int main()
{  
	//freopen("c:/acm/pku_1207.txt","r",stdin);
   solve();
   return 0;
}