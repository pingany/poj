#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define M 100000
#define LEN 10
//map<string,int> maps;

char buffer[LEN],ts[LEN];
char trans[127];
int n;
void init()
{
	trans['A']=trans['B']=trans['C']='2';
	trans['D']=trans['E']=trans['F']='3';
	trans['G']=trans['H']=trans['I']='4';
	trans['J']=trans['K']=trans['L']='5';
	trans['M']=trans['N']=trans['O']='6';
	trans['P']=trans['R']=trans['S']='7';
	trans['T']=trans['U']=trans['V']='8';
	trans['W']=trans['X']=trans['Y']='9';
	int i;
	for(i='0';i<='9';i++)trans[i]=i;
}
void transfer(char *s,char * d)
{
	int i=0;
	while(*s!=0)
	{
		//if(i==3)d[i++]='-';
		d[i++]=trans[*s];
		s++;
	}
	d[i]=0;
}
void mygets(char *buffer)
{
	char c;
	int i=0;
	while((c=getchar())!='\n' && c!=EOF)
	{
		if(isdigit(c) || isupper(c))buffer[i++]=c;
	}
	buffer[i]=0;
}
/*
void solve()
{
	init();
	scanf("%d\n",&n);
	int i;
	for(i=0;i<n;i++)
	{
		mygets(buffer);
		transfer(buffer,ts);
        maps[ts]++;    ///
	}
	map<string,int>::iterator it=maps.begin(),end=maps.end();
	bool have=false;
	while(it!=end)
	{
		if(it->second>1)
		{
            have=true;
			printf("%s %d\n",it->first.c_str(),it->second);
		}
		    ++it;
	}
	if(!have)printf("No duplicates.\n");
}*/
///trie  solve
const int MAX_NEXT=10;
inline char hash(char c){return c-'0';}
inline char inhash(char c){return c+'0';}
struct gao
{
  int num;
  bool allowend;
  struct gao *next[MAX_NEXT];
  gao(){init(0);}
  void init(int cc)
  {
	     allowend=false;
		 num=cc;
		 memset(next,0,sizeof(next));
  }
   gao(int cc)
   {
	    init(cc);
  }
};
gao root,*pr=&root;

int  build_count(char s[])//统计出现的次数
{
	int i;
	gao* p=pr;
	while(*s)
	{
       i=hash(*s);
	   if(p->next[i]==0)
	   {
		   p->next[i]=new gao();
	   }
	   p=p->next[i];
	   s++;
	}
	p->allowend=true;
	p->num++;
	return p->num;
}
bool have=false;
void print(gao *p,char s[])
{
	static char *start=s;
	int i;
	if(p->num>1)
	{
		have=true;
		*s=0;
		printf("%c%c%c-%s %d\n",start[0],start[1],start[2],start+3,p->num);
	}
	for(i=0;i<MAX_NEXT;i++)
	{
		if(p->next[i])
		{
			*s=inhash(i);
			print(p->next[i],s+1);
		}
	}
}
void trie_solve()
{
	init();
	scanf("%d\n",&n);
	int i;
	for(i=0;i<n;i++)
	{
		mygets(buffer);
		transfer(buffer,ts);
		build_count(ts);
	}
	print(pr,ts);
	if(!have)printf("No duplicates.\n");
}
int main()
{
	//freopen("c:/acm/trie.txt","r",stdin);
	//freopen("out1","w",stdout);
	//solve();
	trie_solve();
	return 0;
}

//底下生成测试用数据，测试过没有Runtime Error
/*
int rand(int x,int y){return rand()%(y-x+1)+x;}
#include<time.h>
int main()
{
//	freopen("c:/acm/pku_1002.txt","w",stdout);
//	printf("100000\n");
//	srand(time(0));
//	for(int i=0;i<100000;i++)
//		printf("%03d%03d\n",rand(0,999),rand(0,999));
   return 0;
}*/