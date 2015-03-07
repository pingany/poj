#include<iostream>
#include<algorithm>
using namespace std;
#define M  14
int a[M];

int n,need=6;
void print(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)cout<< a[i]<<" ";
	cout<<"\n";
}
int solve()
{  
	cin >> n;
	if(n==0)return 0 ;
	int i,j,k,l,m,p;
	for(i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	for(i=0;i<n-5;i++)
		for(j=i+1;j<n-4;j++)
			for(k=j+1;k<n-3;k++)
				for(l=k+1;l<n-2;l++)
					for(m=l+1;m<n-1;m++)
						for(p=m+1;p<n;p++)
	{
		printf("%d %d %d %d %d %d\n",a[i],a[j],a[k],a[l],a[m],a[p]);
	}
	printf("\n");
	return 1;
}
int input()
{
	cin >> n;
	if(n==0)return 0 ;
	int i,j,k,l,m,p;
	for(i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	return 1;
}
int t[M];
void   go(int k,int n1)
{
	if(n1==need)
	{
		int i;
		for(i=0;i<k;i++) if(t[i]) cout<<a[i]<<" ";
		cout<<"\n";
		return ;
	}
	if(n1<need)
	{
      t[k]=1;
	  go(k+1,n1+1);
	}
	if(k-n1<n-need)
	{
		t[k]=0;
		go(k+1,n1);
	}
}
int main()
{
	freopen("c:/acm/pku_2245.txt","r",stdin);
   while(input())
	{
	   memset(t,0,sizeof(t));
			go(0,0);
			cout<<"\n";
	}
   return 0;
}