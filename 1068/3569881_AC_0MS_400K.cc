#include<iostream>
using namespace std;
const int MAX=41;
char s[MAX];
int getn(char *p)
{
	int left=1,right=0;
	--p;
	while(1)
	{
		if(*p==')')  right++;
		else if(*p=='(')
		{
			if(right==0) return left;
			else {  ++left; --right;}
		}
		--p;
	}
}
void solve()
{
	int n,x;
  scanf("%d",&n);
  int sp=0;
  int left=0;
  char *pre="";
  while(n--)
	{
	  scanf("%d",&x);
      memset(s+sp,'(',x-left);
	  sp+=x-left;
	  s[sp++]=')';
	  printf("%s%d",pre,getn(s+sp-1));
	  pre=" ";
	  left=x;
	}
	printf("\n");
	s[sp]=0;
}
int main()
{
	//freopen("c:/acm/pku_1068.txt","r",stdin);
	int ncase;
	scanf("%d",&ncase);
	while(ncase--)solve();
  return 0;
  }