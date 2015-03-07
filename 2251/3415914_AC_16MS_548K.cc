#include<iostream>
#include<queue>
using namespace std;
const int M=30;
char a[M][M][M+1];
bool vis[M][M][M];
int f[M][M][M];
char buffer[M];
int l,r,c;
struct Point
{
	int x,y,z;
};
Point start,end;
queue<Point> que;
bool found;
inline bool canput(const Point &p)
{
	return (p.x>=0 && p.y>=0 && p.z>=0 
		&& p.x<l && p.y<r&& p.z<c
		&& a[p.x][p.y][p.z]!='#'&& !vis[p.x][p.y][p.z]);
}
void go(int x,int y, int z)
{
	while(!que.empty())que.pop();
	que.push(start);
	vis[start.x][start.y][start.z]=1;
	f[start.x][start.y][start.z]=0;
	Point p;
	while(!que.empty())
	{
		p=que.front();
		if(p.x==end.x && p.y==end.y  && p.z==end.z )
		{
			found=true;
			printf("Escaped in %d minute(s).\n",f[p.x][p.y][p.z]);
			return;
		}
		que.pop();
		p.x+=1;
		if(canput(p)) 
		{
			vis[p.x][p.y][p.z]=1;
			f[p.x][p.y][p.z]=f[p.x-1][p.y][p.z]+1;
			que.push(p);
		}
		p.x-=2;
		if(canput(p)) 
		{
			vis[p.x][p.y][p.z]=1;
			f[p.x][p.y][p.z]=f[p.x+1][p.y][p.z]+1;
			que.push(p);
		}
		p.x+=1;
		p.y+=1;
		if(canput(p)) 
		{
			vis[p.x][p.y][p.z]=1;
			f[p.x][p.y][p.z]=f[p.x][p.y-1][p.z]+1;
			que.push(p);
		}
		p.y-=2;
		if(canput(p)) 
		{
			vis[p.x][p.y][p.z]=1;
			f[p.x][p.y][p.z]=f[p.x][p.y+1][p.z]+1;
			que.push(p);
		}
		p.y+=1;
		p.z+=1;
		if(canput(p)) 
		{
			vis[p.x][p.y][p.z]=1;
			f[p.x][p.y][p.z]=f[p.x][p.y][p.z-1]+1;
			que.push(p);
		}
		p.z-=2;
		if(canput(p)) 
		{
			vis[p.x][p.y][p.z]=1;
			f[p.x][p.y][p.z]=f[p.x][p.y][p.z+1]+1;
			que.push(p);
		}
		p.z+=1;
	}

}
bool solve()
{
	scanf("%d %d %d\n",&l,&r,&c);
	if(l==0)return false;
	memset(vis,0,sizeof(vis));
	found=false;
	int i,j;
	char *p;
	for(i=0;i<l;i++)
	{
		for(j=0;j<r;j++)
		{
			gets(a[i][j]);
			if((p=strchr(a[i][j],'S'))!=0)
			{
				start.x=i;
				start.y=j;
				start.z=p-a[i][j];
			}
			if((p=strchr(a[i][j],'E'))!=0)
			{
				end.x=i;
				end.y=j;
				end.z=p-a[i][j];
			}
		}
		gets(buffer);
	}
	go(start.x,start.y,start.z);
	if(!found)printf("Trapped!\n");
	return true;
}
int main()
{
	//freopen("c:/acm/pku_2251.txt","r",stdin);
	while(solve());
	return 0;}