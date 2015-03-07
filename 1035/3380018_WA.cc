#include<iostream>
#include<map>
using namespace std;
#define M 100
#define LEN 16
char ss[M][LEN];
int   len[M];
char s[LEN],ts[LEN+1];
int nw=0;
bool requal(char *p,char *q)
{
	while(*p)
	{
		if(*q!='*' && *p!=*q)return 0;
		p++;q++;
	}
	if(*q)return 0;
	return 1;
}
/*
me is correct
aware: award

*/
void solve()
{
	int i,j,l,t;
	bool yes;
	while(gets(ss[nw]) && strcmp(ss[nw],"#")!=0)
	{
		len[nw]=strlen(ss[nw]);
		nw++;
	}

	while(gets(s) && strcmp(s,"#")!=0)
	{
		yes=false;
		l=strlen(s);
		for(i=0;i<nw;i++)
		{
		    if(len[i]==l && strcmp(ss[i],s)==0){printf("%s is correct\n",s);yes=true;break;}
		}
		if(yes)continue;
		printf("%s:",s);
		for(i=0;i<nw;i++)
		{
			if(len[i]==l)
			{
				{
					for(j=0;j<l;j++)
					{
						t=s[j];
						s[j]='*';
						if(requal(ss[i],s))printf(" %s",ss[i]);
						s[j]=t;
					}
				}
			}
			else if(len[i]>l)//需要添加
			{
				
				for(j=0;j<=l;j++)
				{
					strncpy(ts,s,j);
					ts[j]='*';
					strcpy(ts+j+1,s+j);
					if(requal(ss[i],ts))printf(" %s",ss[i]);
				}
			}
			else //需要删除
			{
				for(j=0;j<l;j++)
				{
					strncpy(ts,s,j);
					strcpy(ts+j,s+j+1);
					if(strcmp(ss[i],ts)==0)printf(" %s",ss[i]);
				}
			}
		}
		printf("\n");
	}

}
int main()
{
	//freopen("c:/acm/pku_1035.txt","r",stdin);
	solve();
	return 0;
}