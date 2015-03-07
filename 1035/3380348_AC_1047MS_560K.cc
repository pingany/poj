#include<iostream>
#include<map>
using namespace std;
#define M 10001
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
		yes=false;
			if(len[i]==l)
			{
				{
					for(j=0;j<l;j++)
					{
						t=s[j];
						s[j]='*';
						if(requal(ss[i],s)){yes=true;s[j]=t;break;
						}
						s[j]=t;
					}
					if(yes)printf(" %s",ss[i]);
				}
			}
			else if(len[i]==l+1)//需要添加
			{
				
				for(j=0;j<=l;j++)
				{
					strncpy(ts,s,j);
					ts[j]='*';
					strcpy(ts+j+1,s+j);
					if(requal(ss[i],ts)){yes=true;break;}
				}if(yes)printf(" %s",ss[i]);
			}
			else if(len[i]==l-1)//需要删除
			{
				for(j=0;j<l;j++)
				{
					strncpy(ts,s,j);
					strcpy(ts+j,s+j+1);
					if(strcmp(ss[i],ts)==0){yes=true;break;}
				}if(yes)printf(" %s",ss[i]);
			}
		}
		printf("\n");
	}

}
int main()
{
	solve();
	//fclose(stdout);
//	while(cin>>s>>ts)
//	{
//		cout<<requal(s,ts)<<"\n";
//	}
	return 0;
}