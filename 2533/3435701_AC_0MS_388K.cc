#include<iostream>
using namespace std;
const int maxn=10001;
int a[maxn];
int f[maxn];
void solve()
{
	int n,i,j,maxf=-1,maxt=-1;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	maxt=f[0]=1;
	for(i=1;i<n;i++)
	{
		maxf=1;
		for(j=0;j<i;j++)
		{
			if(a[j]<a[i] && maxf<(f[j]+1)) maxf=f[j]+1;
		}
		f[i]=maxf;
		if(f[i]>maxt)maxt=f[i];
	}
	printf("%d",maxt);
}
int main()
{
	//freopen("c:/acm/pku_2533.txt","r",stdin);
	solve();
	return 0;
}