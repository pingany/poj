#include<iostream>
#include<queue>
using namespace std;
#define M 10
#define MAX  262144
int  all1=0x3ffff;
int  turns[]={1,2,3,0};
char * ts[]=
{
	"",
	"ABDE",
	"ABC",
	"BCEF",
	"ADG",
	"BDEFH",
	"CFI",
	"DEGH",
	"GHI",
	"EFHI"
};

bool vis[MAX];
int  father[MAX],tt[MAX];
#include<stack>

inline int xturn(int x,int i)
{
	i=10-i;
	int k= x>>(2*(i-1)) & 3;
	k=turns[k];
	int a1= k<< (2*(i-1));
	int a0=( 3<< (2*(i-1)) )^ all1;
	
	return x&a0 |a1;
}
inline int   xlate(int x,int k)
{
	char *s=ts[k];
	char c;
	while(*s)
	{
		c=*s-'A'+1;
		x=xturn(x,c);
		++s;
	}
	return x;
}
void  tos(int x,char s[])
{
	int i=9;
	memset(s,'0',9);
	s[9]=0;
	while(x)
	{
		s[--i]=(x&3)+'0';
		x>>=2;
	}
}
inline int trans(int x,int i,int k)
{
	i=10-i;
	int a1= k<< (2*(i-1));
	int a0=( 3<< (2*(i-1)) )^ all1;
	return x&a0 |a1;
}

void bfs(int x)
{
	int i,y;
	queue<int> que;
	
	
	memset(father,-1,sizeof(father));
	memset(vis,0,sizeof(vis));
	vis[x]=true;
	que.push(x);
	while(!que.empty())
	{
		x=que.front();
		que.pop();
		for(i=1;i<=9;i++)
		{
			y=xlate(x,i);
			if(!vis[y])  
			{
				vis[y]=true;
				father[y]=x;
				tt[y]=i;
				que.push(y);
			}
			if(y==0)
				return ;
		}
	}
}
void solve()
{
	int n=9;
	int sum=0;
	int x,i;
	stack<int> st;
	while(n--)
	{
		scanf("%d",&x);
		sum=sum*4+x;
	}
	
	bfs(sum);
	i=0;
	while(father[i]!=-1)
	{
		st.push(tt[i]);
		i=father[i];
	}
	while(!st.empty())
	{
		printf("%d ",st.top());
		st.pop();
	}
}

int main()
{
	//freopen("c:/acm/pku_1166.txt","r",stdin);
   solve();
   return 0;
}