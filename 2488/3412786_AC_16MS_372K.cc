#include<iostream>
using namespace std;
int path[26][2];
int state[26];
int step;
int m,n;
bool found;
int total;
int index=0;
void go(int,int);
int moves[8][2]={
	{-1,-2},
	{1,-2},
	{-2,-1},
	{2,-1},
	{-2,1},
	{2,1},
	{-1,2},
	{1,2}
};
void solve()
{
	found=false;
	scanf("%d%d",&m,&n);
	total=m*n;
	int i,j,k;
	
	printf("Scenario #%d:\n",++index);
	for(i=0;i<(m+1)/2;i++)
		for(j=0;j<(n+1)/2;j++)
		{
			for(k=0;k<total;k++)state[k]=1;
			
			state[i*n+j]=0;
			path[0][0]=i;
			path[0][1]=j;
			step=1;
			go(i,j);
			state[i*n+j]=1;
			if(found){i=m;j=n;}
		}
		if(!found)printf("impossible\n\n");
}
void printAns()
{
	int i;
  for(i=0;i<total;i++)
	  printf("%c%d",path[i][1]+'A',path[i][0]+1);
  printf("\n\n");
}
void go(int hang,int lie)
{
	if(found)return ;
	int i,x,y,z;
	if(step==total)
	{
		printAns();
		found=true;
		return ;
	}
	for(i=0;i<8;i++)
	{
		x=hang+moves[i][0];
		y=lie+moves[i][1];
		z=x*n+y;
		if(x>=0 && x<m && y>=0 && y<n && state[z])
		{
			state[z]=0;
			path[step][0]=x;
			path[step][1]=y;
			step++;
			go(x,y);
			step--;
			state[z]=1;
		}
	}
}

int main()
{
	//freopen("c:/acm/pku_2488.txt","r",stdin);
	int ncase;
	scanf("%d",&ncase);
	while(ncase--)solve();
	return 0;
}
