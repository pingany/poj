#include<iostream>
#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
#define M 25
int n,H,T[M],F[M],D[M],dist[M],stay[M],staybak[M],fast;
int fish;
struct Pair
{
	int first;
	int second;
	Pair(int f,int s):first(f),second(s){}
	inline friend 
 bool operator < (const Pair &p ,const Pair &r)
 {
     return p.second<r.second || (p.second==r.second&& p.first>r.first);
 }
};

void input()
{
	scanf("%d",&H);
	int i;
	for(i=0;i<n;i++)scanf("%d",&F[i]);
		for(i=0;i<n;i++)scanf("%d",&D[i]);
			for(i=0;i<n-1;i++)scanf("%d",&T[i]);
}
void init()
{
    int sum=0;
	int i;
	for(i=0;i<n;i++)
	{
		dist[i]=sum;sum+=5*T[i];
	}
}

int solve()
{
	init();
	priority_queue<Pair> dq;
	int k,t,i,sum,totalt;
	fish=0;
	fast=0;
	for(k=0;k<n;k++)
	{
		if(!dq.empty())dq.pop();
		totalt=H*60-dist[k];
		t=totalt;
		sum=0;
		memset(stay,0,sizeof(int)*n);
		for(i=0;i<=k;i++)dq.push(Pair(i,F[i]));
		while(t>0 &&!dq.empty())
		{
			  Pair pa=dq.top();
			  dq.pop();
			  sum+=pa.second;
			  stay[pa.first]+=5;
			  if(pa.second-D[pa.first]>0)
			      dq.push(Pair(pa.first,pa.second-D[pa.first]));			  
              t-=5;
		}
		if(t>0)stay[0]+=t;
		if(fish<sum)
		{
		  fish=sum;
		  fast=k;
		  memcpy(staybak,stay,sizeof(int)*n);
		}
	}
	return fish;
}
void output()
{
   int i;
   for(i=0;i<n-1;i++)printf("%d, ",staybak[i]);
   printf("%d \n",staybak[n-1]);
   printf("Number of fish expected: %d \n\n",fish);
}
int main()
{
	//freopen("c:/acm/gone_fish.txt","r",stdin);
	while(scanf("%d",&n),n)
	{
        input();
        solve();
		output();
	}
   return 0;
}