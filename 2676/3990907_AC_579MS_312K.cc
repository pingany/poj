#include<stdio.h>
#include<string.h>
char qi[9][10];
struct  Cell
{
	int i,j;
};
Cell cells[81];
int sp;
bool found;
void go(int k)
{
	if(found)return ;
	if(k==sp)
	{
		int i;
		found=true;
		for(i=0;i<9;i++)
			puts(qi[i]);
		return ;
	}
	int x=cells[k].i,  y=cells[k].j;
	int b[10];
	int i,j,is,js;
	memset(b,0,sizeof(b));
	for(i=0;i<9;i++)
	{
		b[qi[i][y]-'0']++;
		b[qi[x][i]-'0']++;
	}
	i=x/3 *3;
	j=y/3 *3;
	is=i;
	js=j;
	for(i=is;i<is+3;++i)
		for(j=js;j<js+3;++j) b[qi[i][j]-'0']++;
	for(i=1;i<=9;i++)
	{
		if(!b[i])
		{
			qi[x][y]=i+'0';
			go(k+1);
			qi[x][y]='0';
		}
	}	
}

int main()
{
	//freopen("c:/acm/pku_2676.txt","r",stdin);
	int ncase,i,j;
   scanf("%d\n",&ncase);
   while(ncase--)
   {
      for(i=0;i<9;i++)gets(qi[i]);
	  sp=0;
      for(i=0;i<9;i++)	     
			for(j=0;j<9;j++)
			{
				 if(qi[i][j]=='0')
				{
					cells[sp].i=i;
					cells[sp].j=j;
					++sp;
				}
			}
		found=false;
		go(0);

   }
   return 0;
}