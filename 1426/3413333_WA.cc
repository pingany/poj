#include<iostream>
using namespace std;
const int M=100;
int a[M];
int s[M];
int n;
bool found;
void go(int i);
void solve()
{
	int i,j;
   a[0]=1%n;
   if(a[0]==0) {printf("1");return ;}
   for(i=1;i<M;i++)
   {
	   a[i]=(a[i-1]*10)%n;
	   if(a[i]==0)
	   {
		   printf("1");
		   for(j=0;j<i;j++)printf("0");return ;
	   }
   }
   found=false;
   go(0);

}
void go(int i)
{
	if(found)return;
	if(i==M)
	{
		int k,tot=0;
		for(k=0;k<M;k++)
			if(s[k]==1)tot+=a[k];
		if(tot!=0 && tot%n==0)
		{
			found=true;
			for(k=M-1;k>=0;k--)printf("%d",s[k]);
		}
		return ;
	}
	s[i]=0;
	go(i+1);
	s[i]=1;
	go(i+1);
}
int main()
{
	while(cin>>n && n)
	{
		solve();
	}
	return 0;
}