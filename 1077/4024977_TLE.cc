#include<stdio.h>
#include<map>
#include<queue>
#include<stack>
using namespace std;
map<int,int> setps;
struct  Puzzle
{
	char s[10];
	char  pos;
	char  dir;
};
Puzzle  st[362880];
queue<Puzzle*>  que;
int sp=0;
inline bool vis(int n)
{
	return (setps.find(n)!=setps.end());
}
char get_xpos(char *s)
{
	char *p=s;
	while(*s!='9')
	{
		s++;
	}
	return s-p;
}
inline int get_hashn(char *s)
{
	int n=0;
	while(*s)
	{
		n=n*10+*s-'0';
		++s;
	}
	return n;
}
inline void deal(char *s,int pos,char dir)
{
	int n=get_hashn(s);
	if(!vis(n)) 
	{
		//分配空间
		strcpy(st[sp].s,s);
		st[sp].pos=pos;
		st[sp].dir=dir;

		que.push(&st[sp]);//压入队列
		setps[n]=sp;//标志被访问了

		++sp;
	}
}
char lastdir=0;
void bfs(Puzzle * p)
{
	que.push(p);


	char *s;
	int pos;
	while(!que.empty())
	{
		p=que.front();
		que.pop();
		s=p->s;
		pos=p->pos;
		if(pos%3!=0)
		{
			swap(s[pos],s[pos-1]);
			if(!strcmp(s,"123456789"))
			{
				lastdir='l';
				break;
			}
			deal(s,pos-1,'l');

			swap(s[pos],s[pos-1]);
		};//防止最左边
		if(pos%3!=2)
		{
			swap(s[pos],s[pos+1]);
			if(!strcmp(s,"123456789"))
			{
				lastdir='r';
				break;
			}
			deal(s,pos+1,'r');

			swap(s[pos],s[pos+1]);
		};//防止最右边
		if(pos>=3)
		{
			swap(s[pos],s[pos-3]);
			if(!strcmp(s,"123456789"))
			{
				lastdir='u';
				break;
			}
			deal(s,pos-3,'u');


			swap(s[pos],s[pos-3]);
		};//防止最上边
		if(pos<=5)
		{
			swap(s[pos],s[pos+3]);
			if(!strcmp(s,"123456789"))
			{
				lastdir='d';
				break;
			}
			deal(s,pos+3,'d');

			swap(s[pos],s[pos+3]);
		};//防止最下边
	}

}
int main()
{  
	//if(!freopen("c:/acm/pku_1077.txt","r",stdin))return 1;
	int  i;
	char pos=0;
	/// input 
	char *s=st[0].s;
	sp=1;
	for(i=0;i<9;i++)
	{
		scanf("%s",s+i);
		if('x'==s[i])
		{
			s[i]='9';
			pos=i;
		}
	}
	st[0].pos=pos;
	st[0].dir=0;
	setps[get_hashn(s)]=0;  //标志被访问了
	lastdir=0;
	bfs(&st[0]);
	strcpy(s,"123456789");
	char  dir=lastdir;
	if(lastdir==0) {printf("unsolvable"); return 0;}
	pos=8;
	stack<char> ss;
	int n;
	while(dir!=0)
	{
		ss.push(dir);
		switch(dir)
		{
		case 'l':
			swap(s[pos],s[pos+1]);
			break;
		case 'r':
			swap(s[pos],s[pos-1]);
			break;
		case 'u':
			swap(s[pos],s[pos+3]);
			break;
		case 'd':
			swap(s[pos],s[pos-3]);
			break;
		}
		n=get_hashn(s);
		i=setps[n];
		pos=st[i].pos;
		dir=st[i].dir;
	}
	while(!ss.empty())
	{
		putchar(ss.top());
		ss.pop();
	}
	return 0;
}
//ullddrurdllurdruldr