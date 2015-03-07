#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int  maxv=751;
const int maxe=1001;

int root[maxv];
int n,m;
struct Point
{
	int x;
	int y;
};
struct Edge
{
	int i,j;
	int weight;
	
};
struct PE
{
	Edge *p;
};
inline bool operator<(const PE & a,const PE& b)
	{
		return a.p->weight >= b.p->weight;
	}
Edge e[maxv*maxv];
Point ver[maxv];
Edge * stack[maxv];
priority_queue<PE> que;
inline int dis2(Point &a,Point &b)
{
	int x=a.x-b.x,y=a.y-b.y;
	return x*x+y*y;
}
inline bool cmp(Edge *p,Edge *q)
{
	return p->i<q->i ||(p->i==q->i && p->j<=q->j); 
}
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
void solve()
{
	int i,j,k,kr,jr;
	int index=0;
	cin>>n;
	for(i=1;i<=n;i++)		
	{
		cin>>ver[i].x>>ver[i].y;
		root[i]=i;
	}
	cin>>m;
	int pm=0;//实际的边数，取出环路
	for(i=0;i<m;i++)
	{
		cin>>k>>j;
		kr=getroot(k);
		jr=getroot(j);
		if(kr!=jr)
		{
			root[kr]=root[jr];
			pm++;
		}			
	}
	PE pe;
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
	{
		e[index].i=i;
		e[index].j=j;
		e[index].weight=dis2(ver[i],ver[j]);
		pe.p=e+index;
		que.push(pe);
		index++;		
	}
	index=pm;
	int sp=0;
	Edge *p;
	while(index<n-1)
	{
		p=que.top().p;
		que.pop();
		k=p->i;
		j=p->j;
		kr=getroot(k);
		jr=getroot(j);
		if(kr!=jr)
		{
			index++;
			root[kr]=root[jr];
			stack[sp++]=p;
		}
	}
	/*
	for(i=0;i<sp;i++)
	{
		k=stack[i];
		if(e[k].i>e[k].j)swap(e[k].i,e[k].j);
	}*/
	sort(stack,stack+sp,cmp);
	for(i=0;i<sp;i++)
	{
		cout<<stack[i]->i<<" "<<stack[i]->j<<"\n";
	}
}
int main()
{
	
//freopen("c:/acm/pku_1751_highways.txt","r",stdin);
solve();
   return 0;
}