#include<iostream>
using namespace std;
#define M 100000
#define LEN 10
int maps[M];
char buffer[100],ts[100];
char trans[127];
int n;
int index=0;
void mygets(char *buffer)
{
	char c;
	int i=0;
	while((c=getchar())!='\n' && c!=EOF)
	{
		if(isdigit(c) || isupper(c))buffer[i++]=trans[c];
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
	for(i='0';i<='9';i++)trans[i]=i;
}
void solve()
{	
	scanf("%d\n",&n);
	init();
	int i,k;
	for(i=0;i<n;i++)
	{
		mygets(buffer);
		maps[index++]=atoi(buffer);
	}
	sort(maps,maps+n);
    i=0;
	bool have=false;
	while(i<n)
	{
		k=i;
		while(k+1<n && maps[k]==maps[k+1])k++;
		if(k>i){have=true;printf("%03d-%04d %d\n",maps[i]/10000,maps[i]%10000,k-i+1);}
		i=k+1;
	}
	if(!have)printf("No duplicates.\n");
}

int main()
{
	//freopen("C:\\acm\\ECNA99-real\\E\\E.5.dat","r",stdin);
	//freopen("out1","w",stdout);
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