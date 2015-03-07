#include<iostream>
using namespace std;
const int MAXN=10;
int M,N,counter=0;
int a[MAXN];
void go(int i,int max,int sum)
{
	int j;
	for(j=1;j<=max;j++)
	{
		sum+=j;
		if(sum<M && i<N-1)
		{
			a[i]=j;
			go(i+1,a[i],sum);
		}
		else if(sum==M)counter++;
		sum-=j;
	}
}
int main()
{
	//freopen("c:/acm/pku_apple.txt","r",stdin);
	int datan;
	cin>>datan;
	int i=0;
	for(i=0;i<datan;i++)
	{
		counter=0;
		cin>>M>>N;
		go(0,M,0);
		cout<<counter<<"\n";
	}
	return 0;
}
