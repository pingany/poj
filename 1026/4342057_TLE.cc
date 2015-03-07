#include<stdio.h>
#include<string.h>
#define N 201
int n,k;
char s[N];
int  a[N];
char  b[N];
void solve()
{
   int i;
   int x=k;
   char *p,*q,*t;
   p=s;
   q=b;
   while(x--)
	{
		for(i=0;i<n;i++)
			q[a[i]-1]=p[i];
	     t=p;
		 p=q;
		 q=t;
	}
   p[n]=0;
   q[n]=0;
   printf("%s\n", p);
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