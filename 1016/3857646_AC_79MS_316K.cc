#include<stdio.h>
#include<string.h>
#define MAX 200
//22 is self-inventorying 
//31123314 is self-inventorying 
//314213241519 enters an inventory loop of length 2 
//21221314 is self-inventorying after 2 steps 
//111222234459 enters an inventory loop of length 2
char  s[17][MAX];
int a[10];
void trans(char *s,char *d)
{
	int i;
	char *p=s;
	memset(a,0,sizeof(a));
	while(*s)
	{
		a[*s-'0']++;
		++s;
	}
	p=d;
	*p=0;
	for(i=0;i<10;i++)
	{
		if(a[i])
		sprintf(p,"%d%d",a[i],i);
		while(*p)p++;
	}
}
void solve()
{
	int i,j;
	while( scanf("%s",s[0]) ,0!=strcmp(s[0],"-1") )
	{
		for(i=1;i<=15;i++)
		{
			trans(s[i-1],s[i]);
			if(strcmp(s[i-1],s[i])==0) break;
		}
		if(i==1)printf("%s is self-inventorying\n",s[0]);
		else if(i<=15)printf("%s is self-inventorying after %d steps\n",s[0],i-1);
		else 
		{
			for(i=1;i<=15;i++)
			{
				for(j=0;j<i-1;j++)
				{
					if(strcmp(s[j],s[i])==0)
					{
						printf("%s enters an inventory loop of length %d\n",s[0],i-j);
						i=100;
						j=100;
					}
				}
			}
			if(i!=101)printf("%s can not be classified after 15 iterations\n",s[0]);
		}
	}
}

int main()
{
	//init();
	//freopen("c:/acm/pku_1016.txt","r",stdin);
		solve();
		//while(1);
		return 0;
}

