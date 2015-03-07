#include<iostream>
using namespace std;

long long comb(int i,int j)
{
	if(j==0)return 1;
	if(i<=0)return 0;
	return comb(i-1,j)+comb(i-1,j-1);
}
void test()
{
	int x,y;
	while(cin>>x>>y)
   cout<<comb(x,y)<<" ";
}
const int N=20;
int a[N];
int mt[N][N];
int n;
int m;
int maxf;
int cal()
{
	int s=0,i,j;
   if(m==0)return 0;
   for(i=0;i<n;i++)
   {
	   if(a[i]==1)
	   {
		 for(j=0;j<n;j++)
		   if(a[j]==0) s+=mt[i][j];
	   }
   }
   return s;
}
void go(int i)
{
	if(i==n)
	{
		int t=cal();
		if(maxf<t)maxf=t;
		return ;
	}
	if(m< n>>1)
	{
		m++;
		a[i]=1;
		go(i+1);
		m--;
	}
	a[i]=0;
	go(i+1);
}
void solve()
{
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&mt[i][j]);
	maxf=-1;
	m=0;
	go(0);
	printf("%d",maxf);
}
int main()
{
	//freopen("c:/acm/pku_2531.txt","r",stdin);
	solve();
	return 0;
}
