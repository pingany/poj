#include<stdio.h>
#include<string.h>
bool    cmp(char *s, char *d,int n)
{
	int i=0;
	for(i=0;i<n;i++)
		if(memcmp(s+i,d,n)==0) return true;
	return false;
}
bool    mul(char *s,char *d ,int n,int m)
{
		int jinwei=0;
		int t;
		char *p=s+n-1;
		char *q=d+n-1;
		while(p>=s)
	{
			t=(*p) * m+jinwei;
			*q=t%10;
			jinwei=t/10;
			--q;
			--p;
	}
	if(jinwei>0) return false;
	return  true;
}
void deal(char *s ,int n)
{
	int i;
	for(i=0;i<n;i++) 
	{
		s[i]-='0';
       s[i+n]=s[i];
  	}
}
void solve()
{
	char s[61*2];
	char d[61];
	int i,n,j;
	while( gets(s))
	{
		n=strlen(s);
		deal(s,n);
		for(i=2;i<=n;i++)
		{
			if(!( mul(s,d,n,i) && cmp(s,d,n)) )  break;			
		}
		for(j=0;j<n;j++)s[j]+='0';
		s[n]=0;
		if(i==n+1)printf("%s is cyclic\n",s);
		else printf("%s is not cyclic\n",s);
	}
}

int main()
{
	//freopen("c:/acm/1047.txt","r",stdin);
		solve();
		//while(1);
		return 0;
}
