#include<stdio.h>
#include<memory.h>
char   rels[26][27];
int totalcolor;//总共可以使用的颜色数量
int curcolor;//当前已经使用过的颜色数量
int cs[27]; //每个定点的颜色
int cancolor[27];//cancolor[m]表示m种颜色可以完成着色
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
	//统计相邻的节点都用了哪些颜色
	while(*p)
	{
		used_colors[ cs[*p-'A'] ]++; 
		++p;
	}
	//先在已使用的颜色中找一个颜色 涂上
	for(i=1;i<=curcolor;i++)
	{
		if(!used_colors[i]) 
		{
			cs[k]=i;
			go(k+1);
			cs[k]=0;
		}
	}
	//取一个新的颜色 涂上
	curcolor++;
	if(curcolor<=totalcolor)
	{
		cs[k]=curcolor;
		go(k+1);
		cs[k]=0;
	}
	curcolor--;
	
}
void  bsearch()
{
	int l=1,r=n,m;
	while(l<r)
	{
		m=(l+r)/2;
		if(cancolor[m]==-1)
		{
			totalcolor=m;
			curcolor=0;
			memset(cs,0,26);
			found=false;
			go(0);
			cancolor[m]=found;
		}		
		if(cancolor[m])
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
	  memset(cancolor,-1,sizeof(cancolor));
	  bsearch();
	 
  }
   return 0;
   }