#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LONG; 
const int MAX=19;
int f[20]={1,1,2,5,14,42,132,429,1430,4862,16796,58786,
208012,742900,2674440,9694845,35357670,129644790,477638700,1767263190};
int s[20];
void init_create()
{
	int i,j;
	  f[0]=1;
	  f[1]=1;
	  for(i=2;;i++)
	  {
		  f[i]=0;
		  for(j=0;j<i;j++)
			  f[i]+=f[j]*f[i-1-j];
		  printf("%lld\n",f[i]);
		  if(f[i]>500000000)break;
	  }
}
void init()
{
	 int i;
	 s[0]=0;
	 for(i=1;i<=MAX;i++)s[i]=s[i-1]+f[i];
}
void solve(int n)
{
	if(n==0)return ;
	int index=lower_bound(s,s+MAX,n)-s;
	if(index==1){ printf("X");return ;}
	n-=s[index-1];
	int i,j, sum=0,t;
	for(i=0;i<index;i++)
	{
		t=f[i]*f[index-1-i];
		if(sum+t<n) sum+=t;
		else break;
	}
	n-=sum;
	j=index-i-1;
	t=(n-1)/f[j]+1;
	if(i!=0)
	{
			printf("(");
			solve(s[i-1]+t);
			printf(")");
	}	
	printf("X");
	t=(n-1)%f[j]+1;
	if(j!=0)
	{
			printf("(");
			solve(s[j-1]+t);
			printf(")");
	}
}
int main()
{
	init();
	int x;
	//freopen("c:/acm/pku_1095.txt","r",stdin);
	while(scanf("%d",&x),x)
	{
		solve(x);
		printf("\n");
	}
	 return 0;
}