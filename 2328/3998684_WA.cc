#include<stdio.h>
int main()
{
	int x, max,min;
	char s[20];
	bool lied;
   //freopen("c:/acm/pku_2328.txt","r",stdin);
   while(scanf("%d\n",&x),x)
   {
	   gets(s);
	   max=10;
	   min=1;
	   lied=false;
	   while(s[4]!='t')
	   {
		   if(!lied)
		   {
				 if(s[4]=='l')min=x+1;
				 else // s[4]=='h'
					 max=x-1;
				 if(max<min) lied=true;
		   }
		   scanf("%d\n",&x);
		   gets(s);
	   }
	   if(lied ||  !(x<=max && x>=min) )printf("Stan is dishonest\n");
	   else printf("Stan may be honest\n");
	   
   }
   return 0;
}