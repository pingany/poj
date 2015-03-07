#include<iostream>
using namespace std;
#define M 100000
#define LEN 10
char space[M][LEN];
char *maps[M];
char buffer[100],ts[100];
char trans[127];
int n;
void mygets(char *buffer)
{
	char c;
	int i=0;
	while((c=getchar())!='\n' && c!=EOF)
	{
		if(isdigit(c) || isupper(c))buffer[i++]=c;
	}
	buffer[i]=0;
}
void init()
{
	trans['A']=trans['B']=trans['C']='2';
	trans['D']=trans['E']=trans['F']='3';
	trans['G']=trans['H']=trans['I']='4';
	trans['J']=trans['K']=trans['L']='5';
	trans['M']=trans['N']=trans['O']='6';
	trans['P']=trans['R']=trans['S']='7';
	trans['T']=trans['U']=trans['V']='8';
	trans['W']=trans['X']=trans['Y']='9';
	int i;
	for(i=0;i<n;i++)maps[i]=space[i];
	for(i='0';i<='9';i++)trans[i]=i;
}
void transfer(char *s,char * d)
{
	int i=0;
	while(*s!=0)
	{
		if(i==3)d[i++]='-';
		if(*s!='-')d[i++]=trans[*s];
		s++;
	}
	d[i]=0;
}
bool cmp(char *s,char *d){return strcmp(s,d)<=0;}
void solve()
{	
	scanf("%d\n",&n);
	init();
	int i,k;
	for(i=0;i<n;i++)
	{
		mygets(buffer);
		transfer(buffer,maps[i]);
	}
	sort(maps,maps+n,cmp);
    i=0;
	bool have=false;
	while(i<n)
	{
		k=i;
		while(k+1<n && strcmp(maps[k],maps[k+1])==0)k++;
		if(k>i){have=true;printf("%s %d\n",maps[i],k-i+1);}
		i=k+1;
	}
	if(!have)printf("No duplicates.\n");
}

int main()
{
	//freopen("c:/acm/pku_1002.txt","r",stdin);
	//freopen("out2","w",stdout);
	solve();
}

//底下生成测试用数据，测试过没有Runtime Error
/*
int rand(int x,int y){return rand()%(y-x+1)+x;}
#include<time.h>
int main()
{
//	freopen("c:/acm/pku_1002.txt","w",stdout);
//	printf("100000\n");
//	srand(time(0));
//	for(int i=0;i<100000;i++)
//		printf("%03d%03d\n",rand(0,999),rand(0,999));
   return 0;
}*/