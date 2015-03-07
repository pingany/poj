#include<iostream>
#include<time.h>
#include<algorithm>
using namespace std;
const int N=10000;
int a[N];
int n;
void print(int [],int);
int partition(int a[],int left,int right)
{
	int i=left+1;
	int j=right;
	int q=a[left];
	while(1)
	{
		while(a[i]<q && i<=right)i++;
		while(a[j]>q)j--;
		if(i<j){
		swap(a[i],a[j]);
		i++;j--;
		}
		else
		{
			swap(a[left],a[j]);
			return j;
		}
	}
}
void print(int a[],int n)
{
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
}
int middle(int a[],int left,int right)
{
  int k=(left+right)/2;
  int j=partition(a,left,right);
  while(j!=k)
	{
	  if(j<k)
	  {
		  left=j+1;
		  j=partition(a,left,right);
	  }
	  else 
	  {
		  right=j-1;
		  j=partition(a,left,right);
	  }
	}
	return a[j];
}
void rand(int a[],int n)
{
	for(int i=0;i<n;i++)a[i]=rand();
}

int main()
{
	int i=0;
   // freopen("c:/acm/pku_middle.txt","r",stdin);	
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	cout<<middle(a,0,n-1);

    return 0;
 }
