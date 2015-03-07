#include<stdio.h>
#include<memory.h>
int main()
{
	int n,x,c,i;
	int small,big;
	//freopen("c:/acm/pku_1363.txt","r",stdin);
  while(scanf("%d",&n),n)
	{
	   while(scanf("%d",& x), x)
		{
		   big=small=x;
		  for(i=1;i<n;++i)
			{
			  scanf("%d",&x);
			  if(x>big) small=big=x;
			  else  
				{
				  if(x<small) small=x;
				  else 
					{
					  c=getchar();
					  while(10!=c && 13!=c) c=getchar();
					  puts("No");
					  break;
					}
				}
			}
			if(i==n)puts("Yes");
		}
		puts("");
	}
  return 0;
}