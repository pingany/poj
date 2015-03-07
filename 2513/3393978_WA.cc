#include <iostream>
#include <map>
#include <string>
using namespace std;
#define M 6
map<string,int> mp;
char s[11],d[11];
int deg[M];
int newtemp=0;
const int MAX_NEXT=26;// max length of next array
inline char hash(char c){return c-'a';}//use to store element
inline char inhash(char c){return c+'b';}//use to print element
struct Trie
{
  int num;
  bool allowend;
  struct Trie *next[MAX_NEXT];
  Trie(){init();}
  void init()
  {
	     allowend=false;
		 memset(next,0,sizeof(next));
  }
};
Trie root,*pr=&root;

bool newtree=false;
int  find_build(char s[])//查找，没有的话添加,同时给新增num
{
	newtree=false;
	int i;
	Trie* p=pr;
	bool have=true;
	while(*s)
	{
       i=hash(*s);
	   if(p->next[i]==0)
	   {
		   have=false;
		   p->next[i]=new Trie();
	   }
	   p=p->next[i];
	   s++;
	}	
	if(!have || !p->allowend)  //都是没有
	{
		newtree=true;
		p->allowend=true;
		return p->num=++newtemp;//递增数字,区别一下
	}
	return p->num;
}
void solve()
{
	int i,c=0;
	while(scanf("%s %s\n",s,d)!=EOF)
	{
		i=find_build(s);
		if(newtree)
		{
			if(newtemp>=M)
			{
				printf("Impossible\n");
				return ;
			}
			deg[i]=1;
		}
		else deg[i]++;
		i=find_build(d);
		if(newtree)
		{
			if(newtemp>=M)
			{
				printf("Impossible\n");
				return ;
			}
			deg[i]=1;
		}
		else deg[i]++;		
	}
	if(newtemp==0)
	{
		printf("Impossible\n");
		return ;
	}
	for(i=1;i<=newtemp;i++)
	{
		if(deg[i] & 1)
		{
			c++;
			if(c>2)break;
		}
	}
	if(c>=0 && c<=2)printf("Possible\n");
	else printf("Impossible\n");
}
int main()
{
	//freopen("c:/acm/pku_2513.txt","r",stdin);
	solve();
   return 0;
}