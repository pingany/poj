#include <iostream>
#include <map>
#include <string>
using namespace std;
#define M 250002
map<string,int> mp;
char s[11],d[11];
int deg[M];
int newtemp=0;
void solve()
{
	int i,j,c=0;
	string str;
	while(scanf("%s %s\n",s,d)!=EOF)
	{
		str.assign(s);
		i=mp[str];
		if(i==0)
		{
			newtemp++;
			if(newtemp>=M)
			{
				printf("Impossible\n");
				return ;
			}
			mp[str]=i=newtemp;
			
			deg[i]=1;
			
		}
		else deg[i]++;
		str.assign(d);
		j=mp[str];
		if(j==0)
		{
			newtemp++;
			if(newtemp>=M)
			{
				printf("Impossible\n");
				return ;
			}
			mp[str]=j=newtemp;
			deg[j]=1;
		}
		else deg[j]++;
	}	
	for(i=1;i<=newtemp;i++)
	{
		if(deg[i] & 1) c++;
	}
	if(c==0 || c==2)printf("Possible\n");
	else printf("Impossible\n");
}
int main()
{
	//freopen("c:/acm/pku_2513.txt","r",stdin);
	solve();
   return 0;
}