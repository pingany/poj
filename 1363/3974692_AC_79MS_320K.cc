#include<stdio.h>
#include<memory.h>

int stack[1002];
int a[1002];
int main()
{
	int n,i,j,sp;

	//freopen("c:/acm/pku_1363.txt","r",stdin);
  while(scanf("%d",&n),n)
	{	 
	   while(scanf("%d",& a[0]), a[0])
		{		   
		  for(i=1;i<n;++i)
			{
			  scanf("%d",&a[i]);
			}
			j=1;
			sp=-1;
			for(i=0;i<n;i++)
			{
				if(j>a[i])
				{
					if(stack[sp]==a[i]) --sp;
					else  
					{
						puts("No");
						break;
					}
				}
				else 
				{
					while(j<=a[i])
					{
							stack[++sp]=j;
							++j;
					}
					--sp;
				}				
			}
			if(i==n)puts("Yes");
		}
		puts("");
	}
  return 0;
}