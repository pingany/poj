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
   if(a[0]==0) {printf("1\n");return ;}
   for(i=1;i<M;i++)
   {
	   a[i]=(a[i-1]*10)%n;
	   if(a[i]==0)
	   {
		   printf("1");
		   for(j=0;j<i;j++)printf("0");
		   printf("\n");return ;
	   }
   }
   memset(s,0,sizeof(s));
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
			k=M-1;
			while(a[k]==0)k++;
			for(;k>=0;k--)printf("%d",s[k]);
			printf("\n");
		}
		return ;
	}
	s[i]=0;
	go(i+1);
	s[i]=1;
	go(i+1);
	s[i]=0;
}
int main()
{
	
	while(cin>>n && n)
	{
		solve();
	}
	return 0;
}