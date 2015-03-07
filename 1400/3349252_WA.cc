#include<iostream>
#include<cstdio>
using namespace std;
#define M 251
char instring[M];
int another[M];
int stack[M];
int sp=-1;
char last_op(char str[],int s,int e);
void deal(char str[],int s,int e);
inline void push(int i){stack[++sp]=i;}
inline int pop(){return stack[sp--];}
void predeal(char str[],int s,int e)
{
	 memset(another,-1,sizeof(another));
     int p,q;
	 for(p=e;p>=s;p--)
	{
		 if(str[p]==')')push(p);
		 else if(str[p]=='(')
		{
			 q=pop();
			 another[p]=q;
			 another[q]=p;
		}
	}
	if(str[s]=='(' && another[s]==e) 
	{
		s++;
		e--;
	}
	deal(str,s,e);
}
char last_op(char str[],int s,int e)
{
	int i,pos=-1;
	while(str[s]=='(' && another[s]==e)
	{
		s++;e--;
	}
	for(i=e;i>=s;i--)
	{
		if(str[i]==')') 
		{
			i=another[i];
			continue;
		}
		if(str[i]=='+'||str[i]=='-')return i;
		if((str[i]=='*'||str[i]=='/') && pos==-1)pos=i;
	}
	if(pos==-1)return -1;
	return pos;
}
void deal(char str[],int s,int e)
{
	if(s>e)return ;
     int i,p;
	 while(str[s]<='z' && str[s]>='a')
	{
		 printf("%c",str[s]);
		 s++;
	}
	while(str[s]=='(' && another[s]==e)
	{
		s++;e--;
	}
	if(s>e)return ;
	    i=last_op(str,s,e);
		if(i==-1)
	{
			deal(str,s,e);return ;//变量
	}
		if(str[i]=='+')
		{
			if(str[s]=='(' && another[s]==i-1) deal(str,s+1,i-2);
			else deal(str,s,i-1);
			printf("+");
			if(str[e]==')' &&another[e]==i+1) deal(str,i+2,e-1);
			else deal(str,i+1,e);			
		}
		if(str[i]=='-')
		{
			if(str[s]=='(' && another[s]==i-1)
			    deal(str,s+1,i-2);
			else deal(str,s,i-1);
			printf("-");
			if(str[e]==')' &&another[e]==i+1)
			{
				p=last_op(str,i+2,e-1);
				if(p!=-1)p=str[p];
				if(p=='+' || p=='-') 
				{
					printf("(");
					deal(str,i+2,e-1);
					printf(")");
				}
				else deal(str,i+2,e-1);
			}
			else deal(str,i+1,e);
			
		}
		if(str[i]=='*')
		{
			if(str[s]=='(' && another[s]==i-1)
			{
				p=last_op(str,s+1,i-2);
				if(p!=-1)p=str[p];
				if(p=='+' || p=='-')
				{
					printf("(");
					deal(str,s+1,i-2);
					printf(")");
				}
				else deal(str,s+1,i-2);						
			}
			else deal(str,s,i-1);
			printf("*");	
			if(str[e]==')' && another[e]==i+1)
			{
				p=last_op(str,i+2,e-1);
				if(p!=-1)p=str[p];
				if(p=='+'||p=='-')
				{
					printf("(");
					deal(str,i+2,e-1);
					printf(")");
				}
				else deal(str,i+2,e-1);
			}
			else deal(str,i+1,e);
			
		}
		if(str[i]=='/')
		{
			if(str[s]=='(' && another[s]==i-1)
			{
				p=last_op(str,s+1,i-2);
				if(p!=-1)p=str[p];
				if(p=='+' || p=='-')
				{
					printf("(");
					deal(str,s+1,i-2);
					printf(")");
				}
				else deal(str,s+1,i-2);						
			}
			else deal(str,s,i-1);
			printf("/");	
			{
			
				if(str[i+1]=='(')
				{
					p=last_op(str,i+2,e-1);
				    if(p!=-1)
					{
					printf("(");
					deal(str,i+2,e-1);
					printf(")");
					}
					else deal(str,i+1,e);
				}
				else deal(str,i+1,e);
			}
		}
}
int main()
{
	//freopen("c:/acm/complicate_expression.txt","r",stdin);
	int n,i;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		gets(instring);
		predeal(instring,0,strlen(instring)-1);
		printf("\n");
	}
   return 0;
}