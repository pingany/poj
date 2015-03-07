#include<iostream>
using namespace std;
char sr[8][23][12];
char *dis[]=
{
	"abcefg",
	"cf",
	"acdeg",
	"acdfg",
	"bcdf",
	"abdfg",
	"abdefg",
	"acf",
	"abcdefg",
	"abcdfg"
};
void paint(int k,char pos,int s)
{
	int i,j;
	
	switch(pos)
	{
	  case 'a':
		  for(i=0,j=1;j<=s;++j) sr[k][i][j]='-';
			break;
	  case 'b':
		  for(j=0,i=1;i<=s;++i) sr[k][i][j]='|';
			break;
	  case 'c':
			for(j=s+1,i=1;i<=s;++i) sr[k][i][j]='|';
			break;
	  case 'd':
			for(i=s+1,j=1;j<=s;++j) sr[k][i][j]='-';
			break;
	  case 'e':
			for(j=0,i=s+2;i<=2*s+1;++i) sr[k][i][j]='|';
			break;
	  case 'f':
		  for(j=s+1,i=s+2;i<=2*s+1;++i) sr[k][i][j]='|';
			break;
	  case 'g':
		  for(i=2*s+2,j=1;j<=s;++j) sr[k][i][j]='-';
			break;
	}
}
void init(int s,int k)
{
	int i,j;
	for(i=0;i<k;i++)
		for(j=0;j<2*s+3;j++)
	{
		memset(sr[i][j],' ',s+2);
	}
}
inline int getn(int n)
{
	if(n==0)return 1;
	int i=0;
	while(n)
	{
		n/=10;
		++i;
	}
	return i;
}
inline void drawDigit(int k,int i,int s)
{
	char *p=dis[i];
	while(*p)
	{
		paint(k,*p,s);
		++p;
	}
}
inline void print(int k,int s)
{
	int i,j,l;
	bool first;
	for(i=0;i<2*s+3;++i)
	{
		first=true;
		for(l=0;l<k;l++)
		{
			if(!first)putchar(' ');
			else first=false;
			for(j=0;j<s+2;++j)
				putchar(sr[l][i][j]);
			
		}
		putchar('\n');
	}
	putchar('\n');
}
void solve()
{
   int k,weishu;
   int s,n;
   while(scanf("%d%d",&s,&n), s)
   {
       weishu=k=getn(n);
	   init(s,k);
	   if(n==0)  drawDigit(0,0,s);
	   while(n)
	   {
		   drawDigit(--k,n%10,s);
		   n/=10;
	   }
	   print(weishu,s);
   }
}
int main()
{  
	//freopen("c:/acm/pku_1102.txt","r",stdin);
   solve();
   return 0;
}