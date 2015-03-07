#include <iostream>
using namespace std;
int num[100],ma,v,n,top;

void dosth(int t)
{
	if(top>100||v==1)
		return;
	if(t%n==0)
	{
		ma=top;
		v=1;
		return;
	}
	else
	{
		num[top++]=0;
		dosth(10*t%n);
		top--;
		if(v==1)
			return;
		num[top++]=1;
		dosth((10*t+1)%n);
		top--;	
	}
}

int main()
{
	int i,t;
	while(cin>>n&&n!=0)
	{
		v=0;
		num[0]=1;
		ma=top=t=1;
		dosth(t);
		for(i=0;i<ma;i++)
			cout<<num[i];
		cout<<endl;
	}
	return 0;
}