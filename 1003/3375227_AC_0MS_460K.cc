#include<iostream>
#include<algorithm>
using namespace std;
#define M 278+1  // 1/2+...1/278>5.20
const float eps=0.009f;
float fn[M];
void get278()
{
	int i=2;
	float f=5.20f;
	while(f>0)
	{
		f-=1.0/i;
		i++;
	}
	printf("%d %f",i,f);
}
void init()
{
	int i=2,j;
	fn[0]=0;
	for(j=1;j<M;j++,i++)
		fn[j]=fn[j-1]+1.0/i;
}
int solve(float f)
{
   float *p=lower_bound(fn,fn+M,f);
   return p-fn;
}
int main()
{
	init();
	//freopen("c:/acm/pku_1003.txt","r",stdin);
	float f;
	while(cin>>f && (f-0.00)>eps)cout<<solve(f)<<" card(s)\n";
   return 0;
}