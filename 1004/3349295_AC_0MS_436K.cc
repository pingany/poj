#include<iostream>
#include<cstdio>
using namespace std;
#define M 12
double ac[M];
void solve()
{
	int i;
	double s=0;
	for(i=0;i<M;i++)
	{
	cin>>ac[i];
	s+=ac[i];
	}
	printf("$%.2f\n",s/M);
}

int main()
{
	//freopen("c:/acm/pku_1004.txt","r",stdin);
	solve();
   return 0;
}