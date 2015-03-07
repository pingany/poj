#include<iostream>
#include<cstdio>
using namespace std;
#define M 101
int f[M];
int solve(int n)
{
	if(n==0)return 1;
	if(n==1)return 1;
	if(f[n]!=-1)return f[n];
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		sum+=solve(i)*solve(n-1-i);
	}
	return f[i]=sum;
}
int main()
{
	memset(f,-1,sizeof(f));
	int x;
	while(cin>>x)
	cout<<solve(x)<<"\n";
   return 0;
}