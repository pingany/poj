#include<stdio.h>
#include<memory.h>
char   rels[26][27];
int totalcolor;
int curcolor;
int cs[27]; //每个定点的颜色
int n;//顶点数量
bool found=false;
void go(int k)
{
	if(found)return;
	if(k==n)
	{
		found=true;
		return ;
	}
	int i;
	char *p=rels[k];
	int used_colors[27]={0}; //某个颜色是否已经用了
	while(*p)
	{
		used_colors[ cs[*p-'A'] ]++;
		++p;
	}
	for(i=1;i<=totalcolor;i++)
	{
		if(!used_colors[i]) 
		{
			cs[k]=i;
			go(k+1);
			cs[k]=0;
		}
	}
	
}
void  bsearch()
{
	int l=1,r=n,m;
	while(l<r)
	{
		m=(l+r)/2;

		totalcolor=m;
		memset(cs,0,26);
		found=false;
		 go(0);
		if(found)
		{
			r=m;
		}
		else l=m+1;
	}
	printf("%d channel%s needed.\n",r,(r==1)?"":"s");
}
int main()
{
	//freopen("c:/acm/pku_1129.txt","r",stdin);
	int i;
	char c;
  while(scanf("%d\n",&n),n)
  {
	  for(i=0;i<n;i++)
	  {
		  scanf("%c:",&c);
		  gets(rels[i]);
	  }
	  bsearch();
	 
  }
   return 0;
   }