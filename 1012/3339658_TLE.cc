#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
list<int> vc;
list<int>::iterator it,end,begin;
int n;
void  next(int m)
{
	int i=0;
    for(i=0;i<m-1;i++) 
	{
		it++;
		if(it==end) it=begin;
	}
}
int  joseph2(int k)
{
   n=k*2;
   int m,s=k,x,size,i;
   vc.resize(n,0);
   bool flag=true;
   while(flag)
	{
	    for(m=s;m<s+k;m++)
		{
			vc.clear();
	      for(i=0;i<n;i++)vc.push_back(i);
		  size=n;
		  it=vc.begin();
		  while(size>k)
			{
			  begin=vc.begin();
			  end=vc.end();
			  next(m);			  
			  x=*it;
			  if(x<k) break;
			  it=vc.erase(it);
			  size--;			  
			}
			if(size==k){flag=false;break;}
		}
		s+=n;
	}
  return m;
}
int  joseph(int k)
{
   n=k*2;
   int m,s=k,x,size;
   bool flag=true;
   while(flag)
	{
	    for(m=s;m<s+k;m++)
		{
			size=n;
			x=0;
		    while(size>k)
			{			  
			  x=(x+m)%size;
			  if(x<k)break;
			  size--;			  
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