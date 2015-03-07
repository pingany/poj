#include<iostream>
using namespace std;
int n;
const int maxn=351;
int a[maxn][maxn];
void solve()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
			scanf("%d",&a[i][j]);
	}
	for(i=n-2;i>=0;i--)
	{
			for(j=0;j<=i;j++)
				a[i][j]=a[i][j]+max(a[i+1][j],a[i+1][j+1]);
	}
	printf("%d",a[0][0]);
}
int main()
{
	//freopen("c:/acm/pku_3176.txt","r",stdin);
	solve();
	return 1;
}