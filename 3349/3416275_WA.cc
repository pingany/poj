#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
typedef unsigned int uint;
typedef list<uint*> lu ;
const uint M=1<<19;
const int m=6;
list<uint*> ls[M];
const uint MAX=0x3ffff;
uint a[6],a2[6];
uint b[6];
bool found;
uint space[M][6];
uint *stack[M];
int sp=-1;
uint hash(uint *str,int n) 
{ 
	uint h; 
	unsigned char *p=(unsigned char*)str; 

	for(h=0 ; n ; n--,p++) 
		h = (31 * h + *p)&MAX; 

	return h; 
}
bool equ(uint *b ,uint *c)
{
	int i;
	for(i=0;i<m;i++)if(b[i]!=c[i])return false;
	return true;
}
inline int pre(int i){if(i==0)return m-1; return i-1;}
inline int next(int i){if(i==m-1)return 0; return i+1;}
void trans()
{
		int minf= 10000001,k,i;
		for(i=0;i<m;i++)
			if(minf>b[i]){minf=b[i];k=i;}
		int j=-1;
		a[++j]=b[k];
		for(i=next(k);i!=k;i=next(i)) a[++j]=b[i];

		j=-1;
		a2[++j]=b[k];
		for(i=pre(k);i!=k;i=pre(i)) a2[++j]=b[i];
}
void solve2()
{
	int n;
	scanf("%d",&n);
	found=false;
	lu::iterator it,end;
	uint x; 
	while(n--)
	{
		scanf("%d%d%d%d%d%d",b,b+1,b+2,b+3,b+4,b+5);
		trans();

		x=hash(a,6*4);
		it=ls[x].begin();
		end=ls[x].end();
		while(it!=end)
		{
			if(equ(*it,a))
			{
				printf("Twin snowflakes found.\n");
				found=true;
				return ;
			}
			it++;
		}
		memcpy(space[++sp],a,sizeof(a));
		ls[x].insert(end,space[sp]);
        
		if(equ(a,a2))continue;
		x=hash(a2,6*4);
		it=ls[x].begin();
		end=ls[x].end();
		while(it!=end)
		{
			if(equ(*it,a2))
			{
				printf("Twin snowflakes found.\n");
				found=true;
				return ;
			}
			it++;
		}
		memcpy(space[++sp],a2,sizeof(a2));
		ls[x].insert(end,space[sp]);
	}
	if(!found){printf("No two snowflakes are alike.\n");}
}
bool cmp(const uint *b ,const uint *c)
{
	int i;
	for(i=0;i<m;i++)if(b[i]!=c[i])return b[i]<c[i];
	return true;
}
void solve()
{
	int n,i;
	scanf("%d",&n);
	found=false;
	while(n--)
	{
		scanf("%d%d%d%d%d%d",b,b+1,b+2,b+3,b+4,b+5);
		trans();
		
		++sp;
		stack[sp]=space[sp];
		memcpy(stack[sp],a,sizeof(a));

		if(equ(a,a2))continue;
		++sp;
		stack[sp]=space[sp];
		memcpy(stack[sp],a2,sizeof(a2));
		
	}
	sort(stack,stack+sp+1,cmp);
	for(i=1;i<=sp;i++)
	{
		if(equ(stack[i],stack[i-1]))
		{
			printf("Twin snowflakes found.\n");
				found=true;
				return ;
		}
	}
	if(!found){printf("No two snowflakes are alike.\n");}
}
int main()
{
	//freopen("c:/acm/pku_3349.txt","r",stdin);
	solve();
	return 0;
}