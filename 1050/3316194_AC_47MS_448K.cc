#include<iostream>
using namespace std;
const int N=100;
int n;
char  s[N][N];
int c[N],f[N];
int maxf;
int max(int i,int j){return i>j?i:j;}
void solve()
{
	int a,b,i;
	for(a=0;a<n;a++)
	{
		for(i=0;i<n;i++)
			c[i]=0;
		for(b=a;b<n;b++)
		{
			for(i=0;i<n;i++)
			{
				c[i]+=s[b][i];
				if(i==0)f[i]=c[i];
				else f[i]=max(f[i-1]+c[i],c[i]);
				if(f[i]>maxf) maxf=f[i];
			}
		}
	}
}
int main()
{ 
	//freopen("c:/acm/pku_max_rect.txt","r",stdin);
	int i,j,c;
	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
		    cin>>c;
			s[i][j]=c;
		}
	if(n>0)maxf=s[0][0];
	solve();
	cout<<maxf;
	return 0;
}
