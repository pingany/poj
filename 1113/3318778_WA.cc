#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
class Point
{
	public :
		int x;
		int y;
		Point(){x=0;y=0;}
		Point (int a,int b){x=a;y=b;}	
};
int distance2(Point *p1,Point *p2)// (p1-p2)^2
{
      int a=p1->x - p2->x,b=p1->y - p2->y;
	  return a*a+b*b;
}
inline double  mysqrt(double x ){return  sqrt(x);}
Point operator-(const Point & q,const Point &p)
	{
			return Point(q.x-p.x,q.y-p.y);
	}
	int operator*(const Point & q,const Point &p)
	{
		return (q.x*p.y-q.y*p.x);
	}
const int minN=1000;
const double PI=3.1415926;
const int minL=1000;
Point *p0=0;
Point spaces[minN];
Point *points[minN];
Point *stack[minN];
int l;
int npoint;
int sp=-1;
inline void init_stack(){sp=-1;}
inline Point *top()
{
	if(sp<0)return 0;
	else return stack[sp];
}
inline Point *next_top()
{
	if(sp<1)return 0;
	else return stack[sp-1];
}
inline void pop(){sp--;}
inline void push(Point *p)
{
	stack[++sp]=p;
}
inline bool cmp_point(const Point *p1,const  Point *p2)
{
	return (*p1-*p0)*(*p2-*p0)>0;
}
void solve_point()
{
	init_stack();
	int i;
	for(i=0;i<npoint;i++)
		points[i]=&spaces[i];
	int miny=points[0]->y;
	int minyp=0;
	for(i=1;i<npoint;i++)
	{
		if(points[i]->y <miny)
		{
			minyp=i;
			miny=points[i]->y;
		}
	}
	swap(points[minyp],points[0]);
	p0=points[0];
	sort(points+1,points+npoint,cmp_point);	
	push(points[0]);
	push(points[1]);
	Point *p1,*p2;
	for(i=2;i<npoint;i++)
	{
		while(1)
		{	
			p1=top();
			p2=next_top();
			if(p2==0 || (*points[i]-*p1)*(*p2-*p1)>0)
				{
					push(points[i]); break;
				}
			else pop();
		}
	}
}

void input_point()
{
	int i;
	scanf("%d %d",&npoint,&l);
	for(i=0;i<npoint;i++)
	{
		scanf("%d %d",&spaces[i].x,&spaces[i].y);
	}	
}
inline int nextp(int i){return (i+sp+2)%(sp+1);}
inline int prep(int i){return (i+sp)%(sp+1);}
double angle(Point *p1,Point *p2,Point *p3);
void output()
{
	int i,j,k;
	double sum=0;
	Point *p1,*p2,*p3;
	//for(i=0;i<=sp;i++) 
	//	printf("%d %d\n",stack[i]->x,stack[i]->y);
	for(i=0;i<=sp;i++) 
	{
		j=prep(i);
		p1=stack[j];
		p2=stack[i];
		k=nextp(i);
		p3=stack[k];
		sum+=mysqrt(distance2(p2,p3))+angle(p1,p2,p3);
	}
	printf("%.0f",sum);
}

double angle(Point *p1,Point *p2,Point *p3)
{
	int a2=distance2(p1,p2),b2=distance2(p2,p3),c2=distance2(p1,p3);
	double ag=acos((a2+b2-c2)/(2*mysqrt(a2)*mysqrt(b2)));	
	return (PI-ag)*l;
}
int main()
{
	//freopen("c:/acm/tubao2.txt","r",stdin);
	input_point();
    if(npoint>=3)
	{
		solve_point();
	}
	 output();

  return 0;
}
