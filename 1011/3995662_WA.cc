#include<stdio.h>
#include<algorithm>
#include<functional>
using namespace std;
bool  found;
int		a[64];
int     used[64];
int    sumlen,maxlen,len,ns,n;
void    dfs(int no,int curlen,int level);
void    fit(int no);
void  fit(int no)
{
	int i;
	if(found)return;
	if(no==ns)
	{
		found=true;  return;
	}
	//寻找没有使用的最大木棍
	for(i=0;i<n;i++)
		if(!used[i]) break;
	used[i]=1;
    dfs(no,a[i],i);
	used[i]=0;
}
void dfs(int no,int curlen,int level)
{
	int i,j;
	if(found)return;
	if(curlen==len)
	{
		fit(no+1);
		return;
	}
	for(i=level+1;i<n;i++)
	{
		if(!used[i] && curlen+a[i] <=len)
		{
			used[i]=1;
			dfs(no,curlen+a[i],i);
			used[i]=0;
			if(found) return;
			j=i;
			while(j<n && a[j]==a[i])++j;
			if(i!=j)i=j-1;

		}
	}
}
int main()
{
	//freopen("c:/acm/pku_1011.txt","r",stdin);
	int i;
   while(scanf("%d",&n),n)
   {
	   maxlen=0;
	   sumlen=0;
      for(i=0;i<n;i++)
      {
        scanf("%d",&a[i]);
		if(maxlen<a[i]) maxlen=a[i];
		sumlen+=a[i];
      }
	  sort(a,a+n,greater<int>());
	  for(ns=sumlen/maxlen; ns>=1;ns--)
	   {
		    if( sumlen%ns!=0) continue;
			len=sumlen/ns;
			memset(used,0,sizeof(used));
			found=false;
			fit(0);
			if(found=true)
		   {
				printf("%d\n",len);
				break;
		   }
	   }
   }
}