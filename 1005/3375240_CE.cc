#include<iostream>
#include<cstdio>
using namespace std;
#define M 100
int index=0;
const double PI=3.14159;
void solve(float x,float y)
{
      printf("Property %d: This property will begin eroding in year %d.\n",++index,(int)ceil(PI*(x*x+y*y)/2/50));
}
int main()
{
	int n;
	float x,y;
	cin>>n;
	while(n--)
	{
		cin>>x>>y;
		solve(x,y);
	}
	printf("END OF OUTPUT.\n");
   return 0;
}