#include <iostream>
#include <map>
#include <string>
using namespace std;
#define M 600001
map<string,int> mp;
char s[11],d[11];
int deg[M];
int nv=0;
const int MAX_NEXT=26;// max length of next array
inline char hash(char c){return c-'a';}//use to store element
inline char inhash(char c){return c+'a';}//use to print element
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
Trie rt,*pr=&rt;
int root[M];
inline int getroot(int k)//得到各自的root的编号
{
	int i=k;
	while(i!=root[i])
	{
		i=root[i];//路径压缩
	}
	root[k]=i;//路径压缩
	return i;
}
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
		return p->num=++nv;//递增数字,区别一下
	}
	return p->num;
}
void solve()
{
	int i,j,c=0;
	int ne=0;
	for(i=1;i<M;i++) root[i]=i;
	while(scanf("%s %s\n",s,d)!=EOF)
	{
		i=find_build(s);
		if(newtree)
		{
//			if(nv>=M)
//			{
//				printf("Impossible\n");
//				return ;
//			}
			deg[i]=1;
		}
		else deg[i]++;
		j=find_build(d);
		if(newtree)
		{
//			if(nv>=M)
//			{
//				printf("Impossible\n");
//				return ;
//			}
			deg[j]=1;
		}
		else deg[j]++;	
		i=getroot(i);
		j=getroot(j);
		if(i!=j)
		{
			ne++;
			root[i]=j;
		}
	}
	if(nv==0)
	{
		printf("Possible\n");
		return ;
	}
	if(ne!=nv-1)
	{
		printf("Impossible\n");
		return ;
	}
	for(i=1;i<=nv;i++)
	{
		if(deg[i] & 1)
		{
			c++;
			if(c>2)break;
		}
	}
	if(c>2)printf("Impossible\n");
	else printf("Possible\n");
}
int main()
{
	//freopen("c:/acm/pku_2513.txt","r",stdin);
	solve();
   return 0;
}