#include<iostream>
using namespace std;
int sum;
const int M=8;
char a[M][M+1];
int c[M];
int n,k;
void go(int i,int hang)
{
	if(i==k)
	{
		sum++;
		return;
	}
	int h,lie;
	for(h=hang;h<=n-k+i;h++)
	{
		for(lie=0;lie<n;lie++)
		{
			if(!c[lie] && a[h][lie]=='#')
			{
				c[lie]=1;
				go(i+1,h+1);
				c[lie]=0;
			}
		}
	}
}
bool solve()
{
	scanf("%d%d\n",&n,&k);
	if(n==-1)return false;
	memset(c,0,sizeof(c));
	sum=0;
	int i;
	for(i=0;i<n;i++)
		gets(a[i]);
	go(0,0);
	printf("%d\n",sum);
	return true;
}
int main()
{
	//freopen("c:/acm/pku_1321.txt","r",stdin);
	while(solve());
	return 0;
}
