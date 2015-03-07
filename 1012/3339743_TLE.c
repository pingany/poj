#include<stdio.h>
int  joseph(int k)
{
   int n,m,s,x,size,flag;
   flag=1;
   s=k;
   n=2*k;
   while(flag)
	{
	    for(m=s;m<s+k;m++)
		{
			size=n;
			x=0;
		    while(size>k)
			{			  
			  x=(x+m)%size;
			  if(x<k)break;
			  size--;			  
			}
			if(size==k){flag=0;break;}
		}
		s+=n;
	}
  return m+1;
}
int main()
{
	int k;
	while(scanf("%d",&k),k)
	{
		 printf("%d\n",joseph(k));
	}
    return 0;
 }
