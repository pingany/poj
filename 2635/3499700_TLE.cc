#include<iostream>
#include<cmath>
using namespace std;
char k[101];
int ki[101];
int l;
int n;
int primers[1000001];
int sp=-1;
bool simple_isprimer(int x);
inline bool isok(int x)
{
  int s=0,i=0;
  for(;i<n;i++)
  {
    s=(s*1000+ki[i])%x;
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
   return (int)s;
}
inline bool isprimer(int x)
{
    return mypow(2,x-1,x)==1;
}

void solve()
{
    int x;
    int  pp=-1;
    n=strlen(k);
   int s=0,i=0;
  int z=n%3;
  if(z==1)
  {
     s=k[0]-'0';
     i=1;
  }
  else if(z==2)
  {
     s=(k[0]-'0')*10+k[1]-'0';
     i=2;
  }
  ki[++pp]=s;
  for(;i<n;)
  {
    s=k[i]-'0';
    ++i;
    s=s*10+k[i]-'0';
    ++i;
    s=s*10+k[i]-'0';
    ++i;
    ki[++pp]=s;
  }
    n=n/3+1;
    for(x=2;x<l;x++)
    {
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
     if(simple_isprimer(x)) primers[++sp]=x;
   }
}
bool simple_isprimer(int x)
{
  int i=2;
  int s=(int)sqrt((float)x);
  for(;i<=s;i++)if(x%i==0)return false;
  return true;
}
void test_primer()
{
   int x=3;
   init();
   for(x=3;x<1000001;x++)
   {   //cout<<primers[x]<<"\n";
      if(simple_isprimer(x)!=isprimer(x))cout<<x<<endl;
   }
}
int main()
{
  //freopen("c:/acm/pku_2635.txt","r",stdin);
  scanf("%s%d",k,&l);
  while(l)
  {
       solve();
       scanf("%s%d",k,&l);
  }
 return 0;
 }