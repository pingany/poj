#include<stdio.h>
#define N 100
#define max(i,j) ((i)>(j)?(i):(j))
int  b[N][N];
int   a[N];
int main()
{
	int n,i,j;
	
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    for(j=0;j<=i;j++)
    {
      scanf("%d",&b[i][j]);
    }
  }
  for(i=0;i<n;i++)
	a[i]=b[n-1][i];
  for(j=n-2;j>=0;j--)
	for(i=0;i<=j;i++)
	{
		a[i]=b[j][i]+max(a[i],a[i+1]);
	}
	printf("%d",a[0]);
  return 0;
}