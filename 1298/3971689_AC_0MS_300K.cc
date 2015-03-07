#include<stdio.h>
#include<string.h>
char t[]="VWXYZABCDEFGHIJKLMNOPQRSTU";
void trans(char s[])
{
	while(*s){ if(*s>='A' && *s <='Z')*s=t[*s-'A']; ++s;}
}
int main()
{
	//freopen("c:/acm/pku_1298.txt","r",stdin);
  char s[201];
  while(gets(s), strcmp(s,"ENDOFINPUT")!=0)
  {
     gets(s);
	 trans(s);
	 puts(s);
     gets(s);
  }
  return 0;
}