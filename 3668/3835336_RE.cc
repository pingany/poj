#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=201;
int n;
int a[maxn][2];
int b[maxn*maxn][2];
int *p[maxn*maxn];
inline bool cmp(const int * a, const int *b)
{
	return  a[1]*b[0] <= a[0]*b[1];
}
inline bool equal(const int * a, const int *b)
{
	return  a[1]*b[0] == a[0]*b[1];
}
void solve()
{
	int sp=0;
	int i,j,x,y,s;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d%d",&a[i][0],&a[i][1]);
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
	{
		x=a[j][0]-a[i][0];
		y=a[j][1]-a[i][1];
		if(x>=0)
		{
			
			b[sp][0]=x;
			b[sp][1]=y;
		}
		else
		{
			
			b[sp][0]=-x;
			b[sp][1]=-y;
		}
		p[sp]=b[sp];
		++sp;		
	}
	sort(p,p+sp,cmp);
	s=sp;
	for(i=1;i<sp;i++)
	{
		if(equal(p[i-1],p[i])) --s;
	}
	printf("%d",s);
}
int main()
{
	//freopen("c:/acm/3668.txt","r",stdin);
		solve();
	
		return 0;
}

