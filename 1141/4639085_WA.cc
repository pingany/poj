#include<stdio.h>
#include<algorithm>
using namespace std;
char  s[103];
int index=0;
char ps[100];
void solve()
{
	index=0;
	int len;
	int i,j;
	s[0]='#';
	if(1!=scanf("%s",s+1)){return ;}
	len=strlen(s+1);
	s[len+1]='#';
	s[len+2]=0;
	j=0;i=1;
	while(s[i])
	{
		if(s[i]==']')
		{
			if(s[j]=='[')
			{
				--j;++i;
			}
			else if(s[j]=='#')
			{
				ps[index++]=i;i++;
			}
			else 
			{
				ps[index++]=j;
				--j;
			}
		}
		else if(s[i]==')')
		{
			if(s[j]=='(')
			{
				--j;++i;
			}
			else if(s[j]=='#')
			{
				ps[index++]=i;++i;
			}
			else 
			{
				ps[index++]=j;
				--j;
			}
		}
		else if(s[i]=='#')
		{
			
			if(s[j]=='#')
			{
				--j;++i;
			}
			else 
			{
				ps[index++]=j;
				--j;
			}
		}
			else { ++i; ++j;}
	}
	sort(ps,ps+index);
	i=0;
	j=0;
	for(i=1;i<len+1;i++)
	{
		if(j<index && i ==ps[j])
		{
			++j;
			if(s[i]=='(' || s[i]==')') printf("()");
			else printf("[]");
		}
		else printf("%c",s[i]);
	}
}
int main()
{
	//freopen("d:/acm/pku_1141.txt","r",stdin);
	solve();
	/*int n;
	scanf("%d",&n);
	while(n--)
	{
		solve();
		printf("\n");
	}
	*/
	return 0;
}