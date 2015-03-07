#include<iostream>
using namespace std;
const int maxn=32000;
int tree[maxn+1];
int level[15000+1];
void solve()
{
	int n,l,r,m,total,t,tt,i;
   scanf("%d\n",&n);
   memset(level,0,sizeof(level));
   for(i=0;i<n;i++)
   {
   total=0;
     scanf("%d %d\n",&t,&tt);
     l=1;
     r=maxn;
     while(1)
     {
       m=(l+r)>>1;
       if(t<=m)
       {
			tree[m]++;
			r=m-1;
			if(t==m)break;
       }
       else 
       {
            l=m+1;
            total+=tree[m];
       }
     }
     level[total+tree[t]]++;
     
   }
}
int main()
{
   solve();
  return 0;
  }