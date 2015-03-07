#include <iostream>
using namespace std;
bool check(int k,int m)
{
	int i;
	int leng = 2*k;
	int pos = 1;
	for(i=1;i<=k;i++)
	{
		pos = (pos +m-1)%leng;
		if(pos==0)
			pos=leng;
		leng--;
		if(pos<=k)
			return false;
		if(pos>leng)
			pos =1;
	}
}
int main()
{
	int i,j,k;
	int a[20];
   for(i=1;i<14;i++)
	   for(j=i+1;;j++)
	   {
		   if(check(i,j))
		   {
			   a[i]=j;
			   break;
		   }
	   }
	   while(cin>>k&&k)
	   {
		   cout<<a[k]<<endl;
	   }
	   return 0;
}