#include <iostream>
   #include <map>
   #include <string>
   using namespace std;
#define M 250000
struct Stick
{
	int x,y;
};
Stick sticks[M];
map<string,int> mp;
char s[11],d[11];
int indeg[M];
int outdeg[M];
int newtemp=0;
void solve()
{
	int i,j;

	int n=0;
	string str;
	while(scanf("%s %s\n",s,d)!=EOF)
	{
		str.assign(s);
		i=mp[str];
		if(i==0)
		{
			newtemp++;
			mp[str]=i=newtemp;
		}
		str.assign(d);
		j=mp[str];
		if(j==0)
		{
			newtemp++;
			mp[str]=j=newtemp;
		}
		sticks[n].x=i;
		sticks[n].y=j;
		n++;
	}	
	memset(indeg,0,sizeof(int)*n);
	memset(outdeg,0,sizeof(int)*n);
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
	{
		if(sticks[i].y==sticks[j].x)
		{
			outdeg[i]++;
			indeg[j]++;
		}
		if(sticks[i].x==sticks[j].y)
		{
			outdeg[j]++;
			indeg[i]++;
		}
	}
	int c1=0,c2=0;
	for(i=0;i<n;i++)
	{
		if(indeg[i]!=outdeg[i])
		{
			if(indeg[i]==outdeg[i]+1)c1++;
			if(outdeg[i]==indeg[i]+1)
			{
				c2++;
			}
		}
	}
	if(c1!=c2 || c1>1)printf("Impossible\n");
	else printf("Possible\n");
}
int main()
{
	//freopen("c:/acm/pku_2513.txt","r",stdin);
	solve();
   return 0;
}