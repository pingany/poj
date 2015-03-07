#include<iostream>
using namespace std;
const int M=19;
char qi[M][2*M+2];
char buffer[M+1];
inline void pr(int b,int i,int j)
{
	printf("%d\n%d %d\n",b,i,j);
	}
char *mystr(char *hang,char *s)
{
  char *p=strstr(hang,s);
  while(p)
		{
		  if(p[5]==s[0])
		  {
		    if(p[6]==0){p=0;break;}
			else p=strstr(p+5+2,s);
		  }
		  else break;
		}
		return p;
}	
void solve()
{
	char *hang,*p;
	int j,i,k,bp;
	for(j=0;j<M;j++)
	{
		hang=qi[j];
		gets(hang);
		for(i=0;i<M;i++) hang[i]=hang[i*2];
		hang[M]=0;
	}
	for(i=0;i<M;i++)
	{	   
		hang=qi[i];
		if(p=mystr(hang,"11111"))
		{pr(1,i+1,p-hang+1); return ;}
		if(p=mystr(hang,"22222")){ pr(2,i+1,p-hang+1);return ;}
	}
	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)buffer[j]=qi[j][i];
		buffer[M]=0;
		if(p=mystr(buffer,"11111")){pr(1,p-buffer+1,i+1);return ;}
		if(p=mystr(buffer,"22222")){pr(2,p-buffer+1,i+1);return ;}
	}

	for(j=0;j<M;j++)
	{
		i=0;
		k=j;
		bp=-1;
		while(k<M)
		{
			buffer[++bp]=qi[i][k];
			++i;
			++k;
		}
		buffer[++bp]=0;
		if(p=mystr(buffer,"11111"))
		{
			k=p-buffer;
			pr(1,k+1,j+k+1);return ;}
		if(p=mystr(buffer,"22222"))
		{
			k=p-buffer;
			pr(2,k+1,j+k+1);return ;}
		i=0;
		k=j;
		bp=-1;
		while(k>=0)
		{
			buffer[++bp]=qi[i][k];
			++i;
			--k;
		}
		buffer[++bp]=0;
		if(p=mystr(buffer,"11111"))
		{
		    k=p-buffer+5;
			pr(1,k,j-k+2);return ;}
		if(p=mystr(buffer,"22222"))
		{
			k=p-buffer+5;
			pr(2,k,j-k+2);return ;}
	}
	for(j=0;j<M;j++)
	{
		i=0;
		k=j;
		bp=-1;
		while(k<M)
		{
			buffer[++bp]=qi[k][i];
			++i;
			++k;
		}
		buffer[++bp]=0;
		if(p=mystr(buffer,"11111"))
		{
			k=p-buffer;
			pr(1,j+k+1,k+1);return ;
		}
		if(p=mystr(buffer,"22222"))
		{
			k=p-buffer;
			pr(2,j+k+1,k+1);return ;
		}
		i=M-1;
		k=j;
		bp=-1;
		while(k<M)
		{
			buffer[++bp]=qi[k][i];
			--i;
			++k;
		}
		buffer[++bp]=0;
		if(p=mystr(buffer,"11111"))
		{
			k=p-buffer+5;
			pr(1,j+k,19-k+1);return ;
		}
		if(p=mystr(buffer,"22222"))
		{
			k=p-buffer+5;
			pr(2,j+k,19-k+1);return ;
		}
	}
	printf("0\n");
}
int main()
{
	//freopen("c:/acm/5zhiqi.txt","r",stdin);
	int ncase;
  scanf("%d\n",&ncase);
  while(ncase--)solve();
  return 0;
 }
 