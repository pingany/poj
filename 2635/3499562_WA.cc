#include<iostream>
using namespace std;
char k[101];
int l;
int n;
int primers[1000001];
int sp=-1;
inline bool isok(int x)
{
  int s=0,i;
  for(i=0;i<n;i++)
  {
    s=(s*10+k[i])%x;
  }
  return s==0;  
}

inline int mypow(int a,int x,int p)
{
   int z=a,s=1;
   while(x)
   {
    if(x&1) s=s*z%p;
    z=z*z%p;
    x>>=1;
   }
   return s;
}
inline bool isprimer(int x)
{
    return mypow(2,x-1,x)==1;
}
void solve()
{
    int x,i;
    n=strlen(k);
    for(i=0;i<n;i++)
      k[i]-='0';
    for(i=0;i<=sp && primers[i]<l;i++)
    {
      x=primers[i];
      if(isok(x))
      {  
        printf("BAD %d\n",x);
        return ;
      }
    }
    printf("GOOD\n");
}
void init()
{
   int x=2;
   for(;x<1000001;x++)
   {
     if(isprimer(x)) primers[++sp]=x;
   }
}
int main()
{
  init();
  //freopen("c:/acm/pku_2635.txt","r",stdin);
  scanf("%s%d",k,&l);
  while(l)
  {
       solve();
       scanf("%s%d",k,&l);
  }
 return 0;
 }