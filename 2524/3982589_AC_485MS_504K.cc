#include<stdio.h>
#include<algorithm>
using namespace std;
int root[50000];
inline int getroot(int i)
{
	int k=i;
	while(i!=root[i])
		i=root[i];
	root[k]=i;
	return i;
}
int main()
{
	//freopen("c:/acm/pku_2524.txt","r",stdin);
	int n,m,i,sum,j;
	int ncase=1;
   while( scanf("%d%d",&n,&m),n)
   {
	   for(i=0;i<n;i++)root[i]=i;
     while(m--)
     {
        scanf("%d%d",&i,&j);
			root[getroot(i)]=getroot(j);
     }
	 for(i=0;i<n;i++)root[i]=getroot(i);
	 sort(root,root+n);
	 sum=1;
	 for(i=1;i<n;i++)
	   {
		 if(root[i]!=root[i-1])sum++;
	   }
	   printf("Case %d: %d\n",ncase++,sum);
   }
}