#include<stdio.h>
#include<string.h>
char s[8][11];
int  l[8];
int n;
bool check()
{
	int i,j,k;
	char t;
	 for(i=0;i<n;i++)
	   {
		    for(j=1;j<=l[i];++j)
		   {
				t=s[i][j];
				s[i][j]=0;
				for(k=0;k<n;k++)
			   {
					if(k==i)continue;
					if(strcmp(s[i],s[k])==0) return false;
			   }
			   s[i][j]=t;
		   }
	   }
	   return true;
}
int main()
{
	//freopen("c:/acm/pku_1056.txt","r",stdin);
	int i;
	int index=0;
	bool t;
   while(scanf("%s",s[0])!=EOF)
   {
     i=1;
     while(gets(s[i]),strcmp(s[i],"9"))
     {
		 l[i]=strlen(s[i]);
       ++i;
     }
	 n=i;
	 t=check();
	 printf("Set %d is %simmediately decodable\n",++index,t?"":"not ");
   }
   return 0;
}