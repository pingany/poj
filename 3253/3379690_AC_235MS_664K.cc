#include<iostream>
#include<queue>
using namespace std;
#define M 20001
typedef long long   LONGLONG;
LONGLONG sum=0;
class gao
{
	public :
	int n;
	inline friend bool operator < (const gao & x,const gao &y){return x.n > y.n;}
};
priority_queue < gao > que;
void solve()
{
	int n,i,t;
	gao x,y;
   cin>>n;
   i=n;
   while(i--)
	{
	   cin>>x.n;
	   que.push(x);
	}
	i=n-1;
	while(i--)

	{
		x=que.top();
		que.pop();
		y=que.top();
		que.pop();
		x.n=x.n+y.n;
		que.push(x);
		sum+=x.n;
	}
	cout<<sum;
	//printf("%I64d",sum);
}

int main()
{
	solve();
   return 0;
}