#include<iostream>
using namespace std;
#define N 5002
char a[N],b[N];
int c[N+2];
int lcs(char a[],int m,char b[],int n)
{
	int x=max(m,n)+1;
	int newold=0,old=0;
	memset(c,0,sizeof(int)*x);
	int j,i;
	for(j=1;j<=n;j++,old=0)
		for(i=1;i<=m;i++)
	{
		newold=c[i];
		if(a[i-1]==b[j-1])c[i]=old+1;
		else c[i]=max(c[i],c[i-1]);
		old=newold;
	}
	x=c[i-1];
	return x;
}
void solve()
{
  int n,i,k;
  scanf("%d\n",&n);
  gets(a);
  for(i=0;i<n;i++)b[i]=a[n-1-i];
  k=lcs(a,n,b,n);
  printf("%d",n-k);

}
int main()
{
	//freopen("c:/acm/pku_1159.txt","r",stdin);
solve();
return 0;
}
