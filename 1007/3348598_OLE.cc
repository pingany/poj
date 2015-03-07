#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N  100
#define MAX_STRLEN 50
char spaces[MAX_N][MAX_STRLEN];
char ts[MAX_STRLEN];
struct DNA
{
	char *s;
	int n;
};
DNA dnas[MAX_N];
int len,n,nn;
inline bool cmp_char(char c,char d)
{
	if(c<d) nn++;
	return c<=d;
}
int count_reverse_n2(char s[])
{
	strcpy(ts,s);
	  nn=0;
      stable_sort(ts,ts+strlen(ts),cmp_char);
	  return nn;
}
int count_reverse_n(char s[])
{
	int n=strlen(s);
	int i,j, nv=0;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
			if(s[i]>s[j])nv++;
	}
	return nv;
}
void input()
{
	int i;
	scanf("%d%d",&len,&n);
	gets(ts);
	for(i=0;i<n;i++)
	{
		dnas[i].s=spaces[i];
		gets(dnas[i].s);
		dnas[i].n=count_reverse_n(dnas[i].s);
	}
}
inline bool cmp(const DNA &di,const DNA &dj)
{
    return di.n <=dj.n;
}
void solve()
{
	input();	
	sort(dnas,dnas+n,cmp);
	int i;
	for(i=0;i<n;i++)
		printf("%s\n",dnas[i].s);
}
int main()
{
	//freopen("c:/acm/DNA_sort.txt","r",stdin);
	solve();
	//while(cin>>ts)
	  //cout<<count_reverse_n(ts);
	return 0;
}