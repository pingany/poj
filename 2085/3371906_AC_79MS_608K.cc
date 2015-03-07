#include<iostream>
#include<cstdio>
using namespace std;
#define M 50001
typedef long long LONGLONG;
int a[M];
bool check(int n,int m)
{
   int i,j,x=0;
   for(i=0;i<n;i++)
	   for(j=i+1;j<n;j++)if(a[i]>a[j])x++;
	   return x==m;
}
void solve(int n,LONGLONG m)
{
	LONGLONG nt=m;
	int  t=0;
	int i;
	int  counter=0;
	while(nt>t)
	{
		t++;
		nt-=t;	
		counter++;
	}
	if(nt!=0)counter++;
	for(i=0;i<n-counter-1;i++)a[i]=i+1;
	t=i;
	for(i=1;i<=counter+1;i++)
	{
         a[n-i]=++t;
	}
	if(nt!=0)
	{
		t=a[n-1-nt];
		for(i=n-1-nt;i>=n-counter;i--) a[i]=a[i-1];
		a[n-counter-1]=t;
	}
	printf("%d",a[0]);
	for(i=1;i<n;i++)printf(" %d",a[i]);
	printf("\n");
	//printf("\nchecked:%d\n",check(n,m));
}

int main()
{
	//freopen("c:/acm/1070.txt","r",stdin);
	//freopen("out","w",stdout);
	int n;
	LONGLONG m;
	while(cin>>n>>m && n!=-1)solve(n,m);
    return 0;
}