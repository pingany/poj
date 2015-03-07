#include<stdio.h>
#define abs(x) ((x)>=0?(x):(-(x)))
int main()
{
	int ncase,n,l,r,i,x,k,nn;
	
	scanf("%d",&ncase);
	while(ncase--)
	{
		l=0;
		r=0;
		scanf("%d",&n);
		k=0;
		nn=n;
		while(n--)
		{
			scanf("%d",&x);
			if(x==1)
			{
				if(k==0) l++;
				else r++;
			}
			k=1-k;
		}
		if( nn%2==1 ||  abs(l-r) <2 )
		{
			printf("YES\n");
		}
		else printf("NO\n");

	}
		
   return 0;
}