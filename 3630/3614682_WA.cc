#include<iostream>
using namespace std;
const int MAX_NEXT=10;// max length of next array
inline char hash(char c){return c-'0';}//use to store element
struct Trie
{
  int num;
  bool allowend;
  struct Trie *next[MAX_NEXT];
  Trie(){init(0);}
  void init(int cc)
  {
	     allowend=false;
		 num=cc;
		 memset(next,0,sizeof(next));
  }
   Trie(int cc)
   {
	    init(cc);
  }
};
Trie root,*pr=&root;

int  build(char s[])//创建，同时统计出现的次数
{
	int i;
	Trie* p=pr;
	while(*s)
	{
       i=hash(*s);
	   if(p->next[i]==0)
	   {
		   p->next[i]=new Trie();
	   }
	   p=p->next[i];
	   s++;
	}
	p->allowend=true;
	p->num++;
	return p->num;
}
int build_test(char s[])
{
		int i;
	 Trie* p=pr;
	while(*s)
	{
       i=hash(*s);
	   if(p->next[i]==0)
	   {
		   p->next[i]=new Trie();
	   }
	   p=p->next[i];
	   if(p->num>=1)return 0;
	   s++;
	}
	p->allowend=true;
	p->num++;
	return p->num;
}
int main()
{
	//freopen("c:/acm/pku_3630.txt","r",stdin);
	char s[100];
	bool errorf=false;
	int ncase,n;
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
	}
  return 0;
}

