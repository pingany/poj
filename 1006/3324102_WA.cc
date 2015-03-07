#include<iostream>
using namespace std;
const int p1=23,p2=28,p3=33;
int s1,s2,s3,currentday;
int result;
int index=0;
void solve_1006()
{
   int x1=s1,x2=s2,x3=s3;
   while(x1!=x2 || x2!=x3)
	{
	   while(x1< x2)x1+=p1;
	   while(x2< x1)x2+=p2;
	   while(x1< x3)x1+=p1;
	   while(x3< x1)x3+=p3;
	   while(x2< x3)x2+=p2;
	   while(x3< x2)x3+=p3;
	}
	if(x1>currentday) result=x1-currentday;
	else result=x1+21252-currentday;
	printf("Case %d: the next triple peak occurs in %d days.\n",++index,result);
}

int main()
{
	//freopen("c:/acm/pku_1006.txt","r",stdin);
	while(scanf("%d %d %d %d",&s1,&s2,&s3,&currentday), s1!=-1)
	{
		solve_1006();
	}
  return 0;
  }
