#include<iostream>
using namespace std;
#define M 5
char  qi[M*M];
int root[7];
int a[7];

inline int getroot(int i)
{
	int k=i;
	while(i!=root[i])
		i=root[i];
	root[k]=i;
	return i;
}
inline void  unin(int i,int j)
{
	root[getroot(i)]=getroot(j);
}
inline bool  connected()
{
	int i;
	int k=getroot(0);
	for(i=1;i<7;i++)
	{
		if(k!=getroot(i)) return false;
	}
	return true;
}
void solve()
{ 
	int sum=0;
	int sumj;
	int i,j;
	for(i=0;i<M;i++)
		 scanf("%s",&qi[i*5]);
	for(a[0]=0;a[0]<=18;a[0]++)
		for(a[1]=a[0]+1;a[1]<=19;a[1]++)
			for(a[2]=a[1]+1;a[2]<=20;a[2]++)
				for(a[3]=a[2]+1;a[3]<=21;a[3]++)
					for(a[4]=a[3]+1;a[4]<=22;a[4]++)
						for(a[5]=a[4]+1;a[5]<=23;a[5]++)
							for(a[6]=a[5]+1;a[6]<=24;a[6]++)
	{
		sumj=0;
		for(i=0;i<7;i++)
		{
			if(qi[a[i]]=='J') sumj++;
		}
		if(sumj<4) continue;
		for(i=0;i<7;i++)root[i]=i;
		for(i=0;i<6;i++)
			for(j=i+1;j<7;j++)
		{
			if(a[j]-a[i]==5) unin(i,j);
			else if(a[j]-a[i]==1 && a[j]%5!=0) unin(i,j); 
		}
		if(connected()) sum++;
	}
	printf("%d",sum);
	
}
int main()
{

  //freopen("c:/acm/pku_2458.txt","r",stdin);
 solve();
 return 0;
}
