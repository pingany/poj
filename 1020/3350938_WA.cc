#include<iostream>
#include<algorithm>
using namespace std;
#define M 45
int square[M]={0};
int save[M];
bool found;
int m;
int n;//size:m*m;  piece range(1,n);
int need[17];
//KHOOOOB!
//HUTUTU!
void count_square(int s1,int s2)
{
	if(s2==0)return ;
	square[s2]+=s1/s2;
	int s3=s1%s2;
	count_square(s2,s3);
}
void sub_square(int x,int y)
{
	int d=x-y;
	square[x]--;
	square[d]+=x/d+y/d;
	count_square(d,x%d);
	count_square(d,y%d);
}
void go(int k)
{
	int y,x;
	if(found)return;
	if(k>=n)
	{
			printf("KHOOOOB!\n");
			found=true;
			return ;
	}
	x=need[k];
	if(square[x]<=0) 
	{
	   for(y=x+1;y<=m;y++)
		{
		   if(square[y]>0)
			{
			   memcpy(save,square+y,sizeof(int)*(m+1-y));
			   sub_square(y,x);
			   go(k+1);
			   memcpy(square+y,save,sizeof(int)*(m+1-y));
			}
		}
	}
	else
	{
		square[x]--;
		go(k+1);
	}
}
bool cmp(int i,int j){return i>=j;}
void solve()
{
	int  ncase;	
	scanf("%d",&ncase);
	int i,j;
	for(i=0;i<ncase;i++)
	{
		memset(square,0,sizeof(square));
		memset(need,0,sizeof(need));
		scanf("%d%d",&m,&n);
		square[m]++;
		int total=0;
		for(j=0;j<n;j++)
		{
		   scanf("%d",&need[j]);
		   total+=need[j]*need[j];
		}
		if(total!=m*m) 
		{
			printf("HUTUTU!\n");
			break;
		}
		sort(need,need+n,cmp);
		found=false;
		go(0);
		if(!found)printf("HUTUTU!\n");
	}
}
int main()
{
	//freopen("c:/acm/pku_1020.txt","r",stdin);
	solve();
   return 0;
}