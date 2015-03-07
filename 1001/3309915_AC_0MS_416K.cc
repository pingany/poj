#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<char> Vc;

void times(Vc &x, Vc &y ,Vc &xy)
{
	int xs=x.size(),ys=y.size(),i,j;
	int diwei=0,k=0,jinwei,t;
	xy.resize(xs+ys,0);
	for(j=0;j<ys;j++,diwei++)
	{
		for(i=0,k=diwei,jinwei=0;i<xs;i++,k++)
		{
			t=x[i]*y[j]+jinwei;
			t+=xy[k];
			jinwei=t/10;
			xy[k]=t%10;			
		}
		while(jinwei>0)
		{
			xy[k]=jinwei%10;
			jinwei/=10;
			k++;
		}
	}	
	xy.resize(k);
}
void times(Vc &x, Vc &y)
{
	int xs=x.size(),ys=y.size(),i,j;
	int diwei=0,k=0,jinwei,t;
	Vc xy(xs+ys,0);
	for(j=0;j<ys;j++,diwei++)
	{
		for(i=0,k=diwei,jinwei=0;i<xs;i++,k++)
		{
			t=x[i]*y[j]+jinwei;
			t+=xy[k];
			jinwei=t/10;
			xy[k]=t%10;			
		}
		while(jinwei>0)
		{
			xy[k]=jinwei%10;
			jinwei/=10;
			k++;
		}
	}	
	xy.resize(k);
	x.assign(xy.begin(),xy.end());
}

void pow_an(Vc& x,int n,Vc &z)// not recursion 
{
	Vc y(x);
	z.assign(1,1);
	while(n>0)
	{
		if(n%2!=0) 
		{
			times(z,y);
		}
		Vc ycopy(y);
		times(y, ycopy);
		n/=2;
	}
}

void printVector(Vc & x)
{
	Vc::iterator it=x.begin();
	while(it!=x.end())
	{
		printf("%d ",(*it));
		it++;
	}
	printf("\n");
}
void printVectorReverse(Vc &x)
{
	int xs=x.size(),i;
	if(xs==0){printf("0");}
	for(i=xs-1;i>=0;i--)
	{
		printf("%d",x[i]);
	}
	printf("\n");
}
void reverseVector(Vc & x)
{
	int xs=x.size();
	int k=xs/2,i;
	for(i=0;i<k;i++)
		swap(x[i],x[xs-i-1]);
}
void inputVector(Vc &x,int n)
{
	int k,i;
	for(i=0;i<n;i++)
	{
		cin>>k;
		x.push_back(k);
	}
}
void charsToVc(Vc &x)
{
	int s=x.size(),i;
	for(i=0;i<s;i++)x[i]-='0';
}
void  solve()
{
	Vc x;	
	Vc y;
	Vc xy;
#define M 1001
	char a[M];
	char b[M];
	int n1,n2,i;
	while(cin>>a &&cin>>b)
	{
		//x.insert(x.begin(),a,a+strlen(a));
		//y.insert(y.begin(),b,b+strlen(b));
		//reverseVector(x);
		//reverseVector(y);
		n1=strlen(a);
		n2=strlen(b);
		x.resize(n1);
		y.resize(n2);
		for(i=0;i<n1;i++)
			x[i]=a[n1-i-1];
		for(i=0;i<n2;i++)
			y[i]=b[n2-i-1];
		charsToVc(x);
		charsToVc(y);		
		times(x,y,xy);
		printVectorReverse(xy);
		x.clear();
		y.clear();
		xy.clear();
	}
}
void cloneVector(Vc  & x,int startx, Vc & y,int starty,int leny)
{
	int i,j,end=starty+leny;
	for(i=startx,j=starty;j<end;j++,i++)
	{
		x[i]=y[j];
	}
}
void add(Vc &x,int startx,int lenx,Vc &y,int starty,int leny, Vc & xy,int startxy)
{
	if(lenx>leny)
	{
		int jinwei=0,i,j;
		cloneVector(xy,startxy,x,startx,lenx);
		for(i=startxy,j=starty;j<starty+leny;j++,i++)
		{
			
		}
	}
}
long pow_an(int a,int n)// not recursion 
{
	long z=1,y=a;
	while(n>0)
	{
		if(n%2!=0) z*=y;
		y*=y;
		n/=2;
	}
	return z;
}
void printSpecial(Vc & x,int n)
{
	int xs=x.size();
	bool afterpoint=false;
    int i;
	int sp=0,size=xs;
	for(i=0;i<n;i++)//去小数点后面的0
	{
		if(x[i]!=0)break;
		else sp++;
	}
	for(i=xs-1;i>=0;i--)//去掉前面的0
	{
		if(x[i]!=0)break;
		else size--;
	}
	if(size<=n)
	{
		printf(".");
	   for(i=n;i>size;i--)printf("0");
	}   
   for(i=size-1;i>=sp;i--)
	{
	   printf("%d",x[i]);
	   if(i==n && i>sp) //防止纯粹整数
		{ printf(".");
	   }
	}
	
   printf("\n");
}
char * charDeal(char * q,int len)
{
	char *head=q;
	while(*head=='0')head++;
	bool haspoint=(0!=strchr(head,'.'));
	if(haspoint)
	{
	char *p=q+len-1;
	while(*p=='0')p--;
	if(*p=='.')p--;
	*(p+1)=0;
	}
	return head;
}
char a[5];
int n;
int main()
{
	//freopen("c:/acm/pku_exponetiation.txt","r",stdin);
	//freopen("out1.txt","w",stdout);
	int len,i;
	char *ppoint;
	Vc x,z;
	while(scanf("%s%d",a,&n)!=EOF)
	{
		x.clear();
		z.clear();
		len=strlen(a);
		char *head=charDeal(a,len);
		len=strlen(head);
		for(i=len-1;i>=0;i--)
		{
			if(head[i]!='.')x.push_back(head[i]-'0');
		}
		pow_an(x,n,z);
		ppoint=strchr(head,'.');
		if(ppoint!=0)
		{
			len=(head+len-1-ppoint)*n;
			printSpecial(z,len);
		}
		else printVectorReverse(z);
	}
	return 0;
}
