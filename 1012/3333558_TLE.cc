#include<istream>
#include<vector>
#include<algorithm>
using namespace std;
int  joseph(int k)
{
	int n=k*2;
   vector<int> vc(n);
   int m,s=k,x,size;
   bool flag=true;
  while(flag)
	{
	  for(m=s;m<s+k;m++)
		{
		  vc.resize(n);
		  x=0;
		  size=vc.size();
		  while(size>k)
			{
			  x=(x+m)%size;
			  if(x<k) break;
			  vc.erase(vc.begin()+x);

			  size=vc.size();			  
			}
			if(size==k){flag=false;break;}
		}
		s+=n;
	}
  return m+1;
}
int main()
{
	//freopen("c:/acm/joseph.txt","r",stdin);
	int k;
	while(scanf("%d",&k),k)
	{
		 printf("%d\n",joseph(k));
	}
 return 0;
 }