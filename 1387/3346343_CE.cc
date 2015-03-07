#include<iostream>
#include<cstdio>
using namespace std;
#define M 200
int m,n,r,c;
int matrix[M][M];
int singlen[M],singlecol[M];
int clip[M],clipn[M];
int cmp_densest(int a,int b,int c,int d)
{
	return a*d-b*c;
}
void input()
{
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&matrix[i][j]);
}
void solve2()
{
	int i,j,k,x,row;
	int maxclip=0,maxrowcol=1,r1,c1,r2,c2;
	for(i=0;i+r-1<=m-1;i++)
	{
		for(j=i+r-1;j<m;j++)
		{
			row=j-i+1;
			for(x=0;x<n;x++)
			{
				singlecol[x]=0;
				for(k=i;k<=j;k++)
				{
					singlecol[x]+=matrix[k][x];
				}
				singlen[x]=1;
			}
			clip[c-1]=0;
			for(x=0;x<c;x++)
			{
				clip[c-1]+=singlecol[x];
			}
			for(x=c;x<n;x++)
			{
				clip[x]=clip[x-1]+singlecol[x]-singlecol[x-c];
			}
			for(x=1;x<n;x++)
			{
				if(cmp_densest(singlecol[x-1],singlen[x-1],singlecol[x],singlen[x])>0)
				{
					singlen[x]+=singlen[x-1];
					singlecol[x]+=singlecol[x-1];
				}
			}
			for(x=c-1;x<n;x++)
			{
				clipn[x]=c;
				if(x>c && cmp_densest(singlecol[x-c],singlen[x-c],clip[x],clipn[x])>0)
				{
					clip[x]+=singlecol[x-c];
					clipn[x]+=singlen[x-c];
				}
				if(cmp_densest(clip[x],clipn[x]*row,maxclip,maxrowcol)>0)
				{
					maxclip=clip[x];
					maxrowcol=clipn[x]*row;
					r1=i;
					c1=x-clipn[x]+1;
					r2=j;
					c2=x;
				}
			}
		}
	}
	printf("%d %d %d %d\n",r1+1,c1+1,r2+1,c2+1);
}
void solve()
{
	int i,j,k,x,row;
	int maxclip=0,maxrowcol=1,r1,c1,r2,c2;
	for(i=0;i+r-1<=m-1;i++)
	{
		for(x=0;x<n;x++)
		{
			singlecol[x]=0;
			for(k=i;k<i+r-1;k++)
			{
				singlecol[x]+=matrix[k][x];
			}
		}
		for(j=i+r-1;j<m;j++)
		{
			for(x=0;x<n;x++)
			{
				singlecol[x]+=matrix[j][x];
				singlen[x]=1;
			}
			row=j-i+1;
			
			clip[c-1]=0;
			for(x=0;x<c;x++)
			{
				clip[c-1]+=singlecol[x];
			}
			for(x=c;x<n;x++)
			{
				clip[x]=clip[x-1]+singlecol[x]-singlecol[x-c];
			}
			for(x=1;x<n;x++)
			{
				if(cmp_densest(singlecol[x-1],singlen[x-1],singlecol[x],singlen[x])>0)
				{
					singlen[x]+=singlen[x-1];
					singlecol[x]+=singlecol[x-1];
				}
			}
			for(x=c-1;x<n;x++)
			{
				clipn[x]=c;
				if(x>c && cmp_densest(singlecol[x-c],singlen[x-c],clip[x],clipn[x])>0)
				{
					clip[x]+=singlecol[x-c];
					clipn[x]+=singlen[x-c];
				}
				temp=cmp_densest(clip[x],clipn[x]*row,maxclip,maxrowcol);
				if(temp>0 || (temp==0&& x-clipn[x]+1<c1)
				{
					maxclip=clip[x];
					maxrowcol=clipn[x]*row;
					r1=i;
					c1=x-clipn[x]+1;
					r2=j;
					c2=x;
				}
			}
		}
	}
	printf("%d %d %d %d\n",r1+1,c1+1,r2+1,c2+1);
}
void simulate(int a[],int n,int c)
{
    int f[M];
	int i;
	int maxf=-1000000;
	f[0]=a[0];
	clip[c-1]=0;
	for(i=0;i<c;i++)
		clip[c-1]+=a[i];
	for(i=c;i<n;i++)
	{
		clip[i]=clip[i-1]+a[i]-a[i-c];
	}
	for(i=1;i<n;i++)
	{
		if(f[i-1]>0)
			f[i]=f[i-1]+a[i];
		else f[i]=a[i];
	}
	for(i=c-1;i<n;i++)
	{
		if(i-c>=0 && f[i-c]>0)
		{
			clip[i]+=f[i-c];
		}
		if(clip[i]>maxf)maxf=clip[i];
	}
	printf("%d\n",maxf);
}
int main()
{
	//freopen("c:/acm/submatrix_densest_pku_1387.txt","r",stdin);
	while(scanf("%d",&m),m)
	{
		scanf("%d%d%d",&n,&r,&c);
		input();
		solve();
	}
	//freopen("c:/acm/test.txt","r",stdin);
	//int a[M];int n=0;
	//while(cin>>a[n])n++;
	//simulate(a,n,2);
	printf("*");
	return 0;
}