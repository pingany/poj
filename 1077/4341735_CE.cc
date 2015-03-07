
#include<iostream>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;


struct eqstr
{
	bool operator()(const char *s1,const char * s2)const
	{
		//cout<<s1<<" "<<s2<<endl ;
		return strcmp(s1,s2)<0;
	}
};
#include<set>
typedef set<const char *,eqstr>  Set;

/*
struct eqstr
{
	bool operator()(const char *s1,const char * s2)const
	{
		//cout<<s1<<" "<<s2<<endl ;
		return strcmp(s1,s2)==0;
	}
};*/
#include<ext/hash_set>
using namespace __gnu_cxx ;
typedef hash_set<const char*, hash<const char *>, eqstr > Set;

struct Node
{
	char s[10];
	Node * parent;
	char pos;
};
const int N=9*8*7*6*5*4*3*2;
Node space[N];
int  sp=0;
char start[10];
char *end="12345678x";

queue<Node*> que;
Set tree;
enum Direction{UP=0,DOWN=1,LEFT=2,RIGHT=3};
inline Node * allocate()
{
	return &space[sp++];
}
Node * move(Node * node  ,int mode)
{
    int i= node->pos/3,  j=node->pos%3;
	int pos=node->pos;
	Node *p=0;
	switch(mode)
	{
		case UP:
			if(i!=0)
			{
				p=allocate();
				p->parent=node;
				strcpy(p->s,node->s);
				swap(p->s[pos-3],p->s[pos]);
				p->pos= node->pos -3;
			}
			break;
		case DOWN:
			if(i!=2)
		{
			    p=allocate();
				p->parent=node;
				strcpy(p->s,node->s);
				swap(p->s[pos],p->s[pos+3]);
				p->pos=node->pos+3;
		}
			break;
		case LEFT:
			if(j!=0)
		{
			   p=allocate();
			   p->parent=node;
			   strcpy(p->s,node->s);
			   swap(p->s[pos],p->s[pos-1]);
			   p->pos=node->pos -1;
		}
			break;
		case RIGHT:
			if(j!=2)
		{
			   p=allocate();
			   p->parent=node;
			   strcpy(p->s,node->s);
			   swap(p->s[pos],p->s[pos+1]);
			   p->pos=node->pos+1;
		}
			break;
	}
	return p;
	
}
Node *   bfs(Node * node)
{
	Node *p,*q;
	int i;
	Set::iterator it;
   que.push(node);
   tree.insert(node->s);
   while(!que.empty())
	{
	   p=que.front();
	   que.pop();
	   
	   for( i=UP;i<=RIGHT; ++i)
		{
			q=move(p,i);
		   if(0!=q)
			{
			   if(strcmp(q->s, end)==0)
				{
				   return  q ;
				}
			   it=tree.find(q->s);
			   if(it==tree.end()) // visited=false
				{
					tree.insert(q->s);
					que.push(q);
				}
				else --sp; //释放allocate
			}
		}	  
	}
}
int main()
{
	
	
	int i;
	//freopen("d:/acm/pku_1077.txt","r",stdin);
  for(i=0;i<9;i++)
	  scanf("%s",start+i);
  start[9]=0;
  
 // strcpy(start,"12x453786");
  Node *p=allocate();
  strcpy(p->s, start);
  p->pos = strchr(start,'x')-start;
  p->parent=0;
  

  stack<char> st;
  p=bfs(p);
  while(p->parent !=0)
  {
     switch(p->pos - p->parent->pos)
	 {
	 case 1:st.push('r');break;
	 case 3:st.push('d');break;
	 case -1:st.push('l');break;
	 case -3:st.push('u');break;
	 }
     p=p->parent;
  }
 
  char c;
  while(!st.empty())
  {
	  putchar(st.top());
	  st.pop();
  }
  printf("\n");
  return 0;
}
