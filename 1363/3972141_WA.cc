#include<stdio.h>
#include<memory.h>
int main()
{
	int n,x,c,i;
	int small,big;

	int flag;
	//freopen("c:/acm/pku_1363.txt","r",stdin);
  while(scanf("%d",&n),n)
	{
	  flag=true;
	   while(scanf("%d",& x), x)
		{
		   big=small=x;
		  for(i=1;i<n;++i)
			{
			  scanf("%d",&x);
			  if(!flag) continue;
			  if(x>big) small=big=x;
			  else  
				{
				  if(x<small) small=x;
				  else 
					{
					 flag=false;
					}
				}
			}
			if(flag)puts("Yes");
			else puts("No");
		}
		puts("");
	}
  return 0;
}