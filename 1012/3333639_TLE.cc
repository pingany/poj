#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
vector<int> vc;
int n;
int next(int x,int m)
{
	int i=0,end=vc.size()-1;
    while(i<m)
	{
		if(x==end)x=0;
		else x++;
		if(vc[x]==0)
		{
			i++;
		}		
	}
	return x;
}
int  joseph(int k)
{
   n=k*2;
   int m,s=k,x,size;
   vc.resize(n,0);
   bool flag=true;
  while(flag)
	{
	  for(m=s;m<s+k;m++)
		{		  
		  x=-1;
		  vc.assign(n,0);
		  size=n;
		  while(size>k)
			{
			 
			 // for(int  i=0;i<vc.size();i++)cout<<vc[i]<<" ";
			  //cout<<endl;
			   x=next(x,m);
			  if(x<k) break;
			  vc[x]=1;
			  size--;			  
			}
			if(size==k){flag=false;break;}
		}
		s+=n;
	}
  return m;
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