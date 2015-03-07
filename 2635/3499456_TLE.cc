#include<iostream>
using namespace std;
char k[101];
int l;
int n;
bool isok(int x)
{
  int s=0,i;
  for(i=0;i<n;i++)
  {
    s=(s*10+k[i])%x;
  }
  return s==0;
  
}
void solve()
{
    int x,i;
    n=strlen(k);
    for(i=0;i<n;i++)
      k[i]-='0';
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