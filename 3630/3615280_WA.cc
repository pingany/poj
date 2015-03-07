#include<iostream>
using namespace std;
const int MAX_NEXT=10;// max length of next array
inline char hash(char c){return c-'0';}//use to store element



struct Trie
{
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

Trie space[10000*100];
int sp=0;
inline Trie *allocate()
{
	memset(&space[sp],0,sizeof(space[sp]));
	if(sp>=10000*100) return new Trie();
    return &space[sp++];
}
inline void clear()
{
	sp=0;
	memset(&root,0,sizeof(root));
}
inline int build_test(char s[])
{
		int i;
	 Trie* p=pr;
	while(*s)
	{
       i=hash(*s);
	   if(p->next[i]==0)
	   {
		   p->next[i]=allocate();
	   }
	   p=p->next[i];
	   if(p->allowend)return 0;
	   s++;
	}
	p->allowend=true;
	return 1;
}
void destory(Trie * &p)
{
	if(!p)return ;
	int i=0;
	for(;i<MAX_NEXT;i++) if(!p->next[i])destory(p->next[i]);
	delete p;
	p=0;
}
void destoryAll()
{
	Trie *p=&root;
	int i=0;
	for(;i<MAX_NEXT;i++) if(0!=p->next[i]){ destory(p->next[i]) ;}
}
/*
char dsp[10001][11];
char *ds[10001];
int n;
bool cmp(const char *s,const char *d)
{

}
void solve()
{
	sort(ds,ds+n,cmp);
}*/
int n;
int main()
{
	//freopen("c:/acm/pku_3630.txt","r",stdin);
	char s[100];
	bool errorf=false;
	int ncase;
	scanf("%d",&ncase);
	while(ncase--)
	{
		errorf=false;
		scanf("%d\n",&n);
		while(n--)
		{
			gets(s);
			if(errorf) continue;
			if( !build_test(s)){printf("NO\n");errorf=true;}
		}
		if(!errorf)printf("YES\n");
		clear();
	}
  return 0;
}

