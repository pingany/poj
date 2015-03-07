#include<stdio.h>
#include<string.h>
#define N 201
int n,k;
char s[N];
int  a[N];
int  b[N];
int  c[N];
char  last[N];
void first()
{
	int i;
	int x;
	for(i=0;i<n;i++)
	{
		--a[i];
		c[i]=a[i]; 
	}
	for(i=0;i<n;i++)
	{
		x=1;
		while( c[i]!=i) //i放到c[i]处
		{
			++x;
			c[i]=a[c[i]];
		}
		c[i]=x;//轮回间隔
	}

}
void solve()
{
	int i;
	int x;
	
	for(i=0;i<n;i++)
	{
			x=k%c[i];
			b[i]=i;
			while(x--)
		{
				b[i]=a[b[i]];
		}
	}
	for(i=0;i<n;i++)
	{
		last[b[i]]=s[i];
	}
	last[n]=0;
	printf("%s\n",last);
	
	
}
int  main()
{
	int i;
	int len;
	//freopen("d:/acm/pku_1026.txt","r",stdin);
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		first();
		while(scanf("%d",&k),k)
		{
			scanf(" ");
			gets(s);
			len=strlen(s);
			for(i=len;i<n;i++)
				s[i]=' ';
			s[n]=0;
			
			solve();
		}
		printf("\n");
	}
	return 0;
}