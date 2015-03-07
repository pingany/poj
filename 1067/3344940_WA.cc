#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int p2(int x,int y)
{
	if(x==0&&y==0)return 0;
	if((x==1&&y==2)||(x==2||y==1))return 0;
	if(x==y || x==0 || y==0)return 1;
	if(x==1||y==1||x==2||y==2)return 1;
	if((x-y)%2==0)
	{
		if(x==3||y==3)return 0;
		return 1;
	}
	if(x-y==1 ||x-y==-1)return 1;
	return 0;
}
double x=(sqrt(5.0)-1)/2;
int p(int a,int b)
{
    int k=(int)floor(a*x);
	if(b==a+k||b==a+k+1)return false;
	return true;
}

int main()
{
	int x,y;
	//freopen("c:/acm/pku_1067.txt","r",stdin);
	while(cin>>x>>y)cout<<p(x,y)<<"\n";
	return 0;
}