#include<iostream>
#include<cstdio>
using namespace std;
#define M 500000
int ar[M];
int b[M];
int n;
long long xx=0;

void merge_sort(int a[],int left,int right);

void bsort(int a[],int n)
{
	int i,j;
	xx=0;
for(i=0;i<n;i++)     //冒泡排序法数逆序数
		for(j=n-1;j>i;j--)
	{
		if(ar[j-1]>ar[j])
		{
			swap(ar[j],ar[j-1]);
			xx++;
		}
	}
}
bool solve()
{
	int n,i,j;
	scanf("%d",&n);
	if(n==0)return false;
	for(i=0;i<n;i++)
	{
		scanf("%d",ar+i);
	}
	xx=0;
	merge_sort(ar,0,n-1);
	printf("%lld\n",xx);
	return true;
}
int check()  
{
	int i,j;
	for(i=0;i<n;i++)//直接数逆序数
		for(j=i+1;j<n;j++)
		if(ar[i]>ar[j])xx++;

    
	return 0;
}

void merge(int a[],int left,int mid,int right)//归并排序数逆序数
{
	int n=(right-left+1);
	int i=left,j=mid+1,k=-1;
	while(i<=mid && j<=right)
	{
		if(a[i]<=a[j]) b[++k]=a[i++];
		else
		{
		   b[++k]=a[j++];
		   xx+=mid-i+1;//求逆序数
		}
	}
	while(i<=mid)  b[++k]=a[i++];
	while(j<=right) b[++k]=a[j++];
	memcpy(a+left,b,sizeof(int)*n);
}
void merge_sort(int a[],int left,int right)
{
	if(left<right)
	{
		int mid=(left+right)/2;
		merge_sort(a,left,mid);
		merge_sort(a,mid+1,right);
		merge(a,left,mid,right);
	}
}
int main()
{
	freopen("c:/acm//pku_2299.txt","r",stdin);
	while(solve());
//srand(100000);
//	while(1)
//	{
//		//getchar();
//		n=100;
//		int i,j;
//	   for(i=0;i<n;i++)
//		ar[i]=rand()%100;
//	   xx=0;
//	   check();
//	   cout<<xx<<" ";
//	   xx=0;
//	   memcpy(b,ar,sizeof(ar));
//	   bsort(ar,n);
//	   cout<<xx<<" ";
//	   
//	   xx=0;
//	   memcpy(ar,b,sizeof(ar));
//	   merge_sort(ar,0,n-1);
//	   cout<<xx<<" ";
//	   cout<<"\n";
//	} 

   return 0;
}