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
const int MAXN=100;
const double PI=3.141592653589;
const int minL=1000;
Point *p0=0;
Point spaces[MAXN];
Point *points[MAXN];
Point *stack[MAXN];
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
	//恐怕最后一条边共线
	i=0;
	 while(1)
		{	
			p1=top();
			p2=next_top();
			if(p2==0 || (*points[i]-*p1)*(*p2-*p1)>0)
			{
				break;
			}
			else pop();
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
void output()
{
	int i;
	double sum=0;
	Point *p2,*p3;
	//for(i=0;i<=sp;i++) 
	//printf("%d %d\n",stack[i]->x,stack[i]->y);
	for(i=0;i<=sp;i++) 
	{
		p2=stack[i];
		if(i==sp)p3=stack[0];
		else p3=stack[i+1];
		sum+=mysqrt(distance2(p2,p3));
	}
	printf("%.0f",sum+2*PI*l);
}
const int MAXNPOINT=10;
char matrix[MAXNPOINT][MAXNPOINT];
void show(Point **ps,int n)
{
	int i,j;
	for(i=0;i<MAXNPOINT;i++)
		for(j=0;j<MAXNPOINT;j++)
			matrix[i][j]=0;
		for(i=0;i<n;i++)
			matrix[ps[i]->x][ps[i]->y]='*';
		for(i=0;i<MAXNPOINT;i++)
		{
			for(j=0;j<MAXNPOINT;j++)
				printf(" %c",matrix[i][j]);
			printf("\n");
		}
}
void rand_maxtrix()
{
	int  n;
	freopen("c:/acm/tubao_data.txt","w",stdout);
	for(n=0;n<100;n++)
	{
		int i,j,np=0;
		for(i=0;i<MAXNPOINT;i++)
			for(j=0;j<MAXNPOINT;j++)
			{
				matrix[i][j]=rand()%2;
				if(matrix[i][j]==1)np++;
			}
			
			printf("%d %d\n",np,100);
			for(i=0;i<MAXNPOINT;i++)
				for(j=0;j<MAXNPOINT;j++)
				{
					if(matrix[i][j]==1)printf("%d %d\n",i,j);
				}

	}
					fclose(stdout);
	
}
int main()
{
	//freopen("c:/acm/tubao2.txt","r",stdin);
	//rand_maxtrix();
	//int counter=0;
	//for(counter=0;counter<3;counter++)
	{
	//	printf("\n==================================\n");
		input_point();
		
		if(npoint>=3)
		{
			solve_point();
		}
	//	show(points,npoint);
//		printf("\n===\n");
	//	show(stack,sp+1);
		output();
	}	
	return 0;
}
