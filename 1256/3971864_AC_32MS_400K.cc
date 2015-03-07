#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int  as[128];
int  ds[128];
void init()
{
	int i,c;
	for(i='A';i<='Z';++i)
	{
		c=i-'A'+1;
		as[i]=2*c-1;
	}
	for(i='a';i<='z';++i)
	{
		c=i-'a'+1;
		as[i]=2*c;
	}
	for(i=1;i<=51;i+=2)
	{
		ds[i]=  (i+1)/2+'A'-1;
	}
	for(i=2;i<=52;i+=2)
	{
		ds[i]= i/2+'a'-1;
	}
}
void encode(char *s)
{
	while(*s)
	{
		*s=as[*s];
		++s;
	}
}
void decode(char *s)
{
	while(*s)
	{
		*s=ds[*s];
		++s;
	}
}
void print(char *s)
{
	while(*s)
	{
		putchar(ds[*s]);
		++s;
	}
	putchar('\n');
}
int main()
{
	//freopen("c:/acm/pku_1256.txt","r",stdin);
  int ncase,n;
  char s[14];
  init();
  scanf("%d\n",&ncase);
  while(ncase--)
	{
	    gets(s);
		n=strlen(s);
		encode(s);
		sort(s,s+n);
		print(s);
		while(next_permutation(s,s+n))
		{		
			print(s);
		}		
	}
  return 0;
  }