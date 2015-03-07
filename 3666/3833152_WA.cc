#include <iostream>
using namespace std;

const int maxn=2001;
int a[maxn];
int n;
void solve()
{
	int i,t,s,sum;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	t=0;
	sum=0;
	for(i=0;i<n;i++)
	{
		if(a[i]<t)
			sum+=t-a[i];
		else t=a[i];
	}
	s=sum;
	sum=0;
	t=0;
	for(i=n-1;i>=0;i--)
	{
		if(a[i]<t)
			sum+=t-a[i];
		else t=a[i];
	}
	if(sum<s)s=sum;
	printf("%d",s);
}

int main()
{
	//freopen("c:/acm/3366.txt","r",stdin);
		solve();
		return 0;
}

