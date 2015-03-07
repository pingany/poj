#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define M 100000
#define LEN 10
map<string,int> maps;
char buffer[LEN*2],ts[LEN*2];
char trans[127];
int n;
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
void solve()
{
	init();
	scanf("%d\n",&n);
	int i;
	for(i=0;i<n;i++)
	{
		gets(buffer);
		transfer(buffer,ts);
        maps[ts]++;    ///？
	}
	map<string,int>::iterator it=maps.begin(),end=maps.end();
	bool have=false;
	while(it!=end)
	{
		if(it->second>1)
		{
            have=true;
			printf("%s %d\n",it->first.c_str(),it->second);
		}
		    ++it;
	}
	if(!have)printf("No duplicates.\n");
}

int main()
{
	freopen("c:/acm/pku_1002.txt","r",stdin);
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