#include<stdio.h>
#include<memory.h>
#define  max(i,j)   ((i)>(j)?(i):(j))
#define M  251
char a[M],b[M];
int c[M+2];
int lcs(char a[],int m,char b[],int n)
{
	int x=max(m,n)+1;
	int newold=0,old=0;
	memset(c,0,sizeof(int)*x);
	int j,i;
	for(j=1;j<=n;j++,old=0)
		for(i=1;i<=m;i++)
	{
		newold=c[i];
		if(a[i-1]==b[j-1])c[i]=old+1;
		else c[i]=max(c[i],c[i-1]);
		old=newold;
	}
	x=c[i-1];
	return x;
}
int main()
{
	//freopen("c:/acm/pku_1458.txt","r",stdin);
	while(scanf("%s%s",a,b)!=EOF)
	{
		printf("%d\n",lcs(a,strlen(a),b,strlen(b)));
	}
	return 0;
}