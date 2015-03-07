#include<stdio.h>
#include<memory.h>
char b[10001];
inline int fd(int x)
{
	int s=x;
	while(x)
	{
		s+=x%10;
		x/=10;
	}
	return s;
}
int main()
{
	int i,x;
	 memset(b,0,sizeof(b));
	 for(i=1;i<10000;++i)
	{
		 if(!b[i])printf("%d\n",i);
		 x=fd(i);
		 if(x<=10000) b[x]=1;
	}
	return 0;
}