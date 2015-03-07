
#include<iostream>
using namespace std;
const int M=19;
char qizi[M][M+1];
char buffer[2*M+2];
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
void  input()
{
	/*for(j=0;j<M;j++)
	{
		hang=qizi[j];  
		gets(buffer);
		for(i=0;i<M;i++) hang[i]=buffer[i*2];
		hang[M]=0;
	}*/
	int i,j;
	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
		scanf("%s",&qizi[i][j]);
		
		qizi[i][M]=0;
	}
}
void solve()
{
	char *hang,*p;
	int j,i,k,bp,x;
	input();
	//行
	for(i=0;i<M;i++)
	{
		hang=qizi[i];
		if(p=mystr(hang,"11111"))
		{
			pr(1,i+1,p-hang+1);
			return ;
		}
		if(p=mystr(hang,"22222"))
		{
			pr(2,i+1,p-hang+1);
			//return ;
		}
	}
	// 列
	for(j=0;j<M;j++)
	{
		k=-1;
		for(i=0;i<M;i++)buffer[++k]=qizi[i][j];
			buffer[++k]=0;
		if(p=mystr(buffer,"11111"))
		{
			pr(1,p-buffer+1,j+1);
			return ;
		}
		if(p=mystr(buffer,"22222"))
		{
			pr(2,p-buffer+1,j+1);
			return ;
		}	
	}
	//  1  
	//    1
	for(k=0;k<M;k++)
	{
		 bp=-1;
		 i=k;
		 x=0-k;
		 for(;i<M;i++)buffer[++bp]=qizi[i][i+x];
		 	buffer[++bp]=0;
		if(p=mystr(buffer,"11111"))
		{
			j=p-buffer+k+1;
			pr(1,j,j+x);
			return ;
		}
		if(p=mystr(buffer,"22222"))
		{
			j=p-buffer+k+1;
			pr(2,j,j+x);
			return ;
		}	
	}
	for(k=1;k<M;k++)
	{
		bp=-1;
		j=k;
		x=j-0;
		for(;j<M;j++)buffer[++bp]=qizi[j-x][j];
		buffer[++bp]=0;
		if(p=mystr(buffer,"11111"))
		{
			j=p-buffer+k+1;
			pr(1,j-x,j);
			return ;
		}
		if(p=mystr(buffer,"22222"))
		{
			j=p-buffer+k+1;
			pr(2,j-x,j);
			return ;
		}	

	}
	//   1
	// 1
	for(k=0;k<M;k++)
	{
		bp=-1;
		i=k;
		x=0+i;
		for(;i>=0;i--)buffer[++bp]=qizi[i][x-i];
		buffer[++bp]=0;
		if(p=mystr(buffer,"11111"))
		{
			i=k-(p-buffer);
			pr(1,i+1,x-i+1);
			return ;
		}
		if(p=mystr(buffer,"22222"))
		{
			i=k-(p-buffer);
			pr(2,i+1,x-i+1);
			return ;
		}	
	}
	for(k=1;k<M;k++)
	{
		bp=-1;
		x=M-1+k;
		j=k;
		for(;j<M;j++)buffer[++bp]=qizi[x-j][j];
		buffer[++bp]=0;
		if(p=mystr(buffer,"11111"))
		{
			j=p-buffer+k;
			pr(1,x-j+1,j+1);
			return ;
		}
		if(p=mystr(buffer,"22222"))
		{
			j=p-buffer+k;
			pr(2,x-j+1,j+1);
			return ;
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
 