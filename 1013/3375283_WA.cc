#include<iostream>
#include<cstdio>
using namespace std;
#define M 100
char l[3][7],r[3][7],e[3][7];
char a[128]={0};
char *fx[]={"heavy","light"};
int main()
{
	int n;
	int i,j,k;
	//freopen("c:/acm/pku_1013.txt","r",stdin);
	cin>>n;
	char *p;
	while(n--)
	{
	    cin>>l[0]>>r[0]>>e[0]>>l[1]>>r[1]>>e[1]>>l[2]>>r[2]>>e[2];
		for(k=0;k<3;k++)
		{
		if(strcmp(e[k],"even")==0)
		{
            i=0;
			while(l[k][i]!=0)
			{
				a[l[k][i]]=1;
				a[r[k][i]]=1;
				i++;
			}
		}
		else  j=k;
		}
		i=0;
		while(l[j][i]!=0)
		{
			if(a[l[j][i]]==0){printf("%c is the counterfeit coin and it is %s.\n",l[j][i],strcmp(e[j],"up")==0?fx[0]:fx[1]);break;}
			if(a[r[j][i]]==0){printf("%c is the counterfeit coin and it is %s.\n",r[j][i],strcmp(e[j],"up")==0?fx[1]:fx[0]);break;}
			i++;
		}
	}
   return 0;
}