#include<iostream>
#include<cstdio>
using namespace std;
int p(int x,int y)
{
	if(x==y || x==0 || y==0)return 1;
	if((x-y)%2==0)return 1;
	return 0;
}

int main()
{
	int x,y;
	while(cin>>x>>y)cout<<p(x,y)<<"\n";
	return 0;
}