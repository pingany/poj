#include<iostream>
#include<cstdio>
using namespace std;
#define M 100
char l[3][7],r[3][7],e[3][7];
char *fx[]={"heavy","light"};
int main()
{
	int n;
	int i,k;
	//freopen("c:/acm/pku_1013.txt","r",stdin);
	cin>>n;
	int light=0;
	while(n--)
	{
		cin>>l[0]>>r[0]>>e[0]>>l[1]>>r[1]>>e[1]>>l[2]>>r[2]>>e[2];
		for(k='A';k<='L';k++)
		{
			light=0;
			for(i=0;i<3;i++)
			{
				if(strchr(l[i],k)!=0)
				{
					if(strcmp(e[i],"even")==0)break;
					else if(strcmp(e[i],"up")==0)
					{
						if(light==0)light=-1;
						else if(light==1) break;
					}
					else 
					{
						if(light==0)light=1;
						else if(light==-1) break;
					}
				}
				else if(strchr(r[i],k)!=0)
				{
					if(strcmp(e[i],"even")==0)break;
					else if(strcmp(e[i],"up")==0)
					{
						if(light==0)light=1;
						else if(light==-1) break;
					}
					else 
					{
						if(light==0)light=-1;
						else if(light==1) break;
					}
				}
				else 
				{
					if(strcmp(e[i],"even")!=0)break;
				}
			}
			if(i==3)break;
		}
		printf("%c is the counterfeit coin and it is %s.\n",k,light==1?fx[1]:fx[0]);
	}
	return 0;
}