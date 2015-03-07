#include<stdio.h>
#include<memory.h>
short  inputs[100][1002];
char    coin[1000+1];
char    flag[1000+1];
int n,k;
int found=0;
int nofound=0;
int falseweight=-1;//  假设假币重一点
int result=-1;
int sum(short *s,int n)
{
	int i=0, x=0;
	for(i=0;i<n;i++) x+=coin[s[i]];
	return x;
}
int ok( short *s)
{
	int res;
	int cnt=s[0];
	short f=s[cnt*2+1];
	int left,right;
	left=sum(s+1,cnt);
	right=sum(s+cnt+1,cnt);
	if(left==right)return 0;
	if(f=='>')  res=left-right;
	else  res=right-left;
	if(falseweight==-1)
	{
		if(res>0) falseweight=1;
		else falseweight=0;
		return 1;
	}
	else if(falseweight==1)
	{
		if(res>0) return 1;
		else return 0;
	}
	else 
	{
		if(res>0) return 0;
		else return 1;
	}
}
int main()
{
	int i,j,cnt,cnt2;
	char chs[2],ch;
	//freopen("d:/acm/pku_1029.txt","r",stdin);
	scanf("%d%d",&n,&k);
	memset(flag,0,sizeof(char)*(n+1));
	for(i=0;i<k;i++)
	{
		scanf("%d",&cnt);
		inputs[i][0]=cnt;
		cnt2=cnt*2;
		for(j=0;j<cnt2;j++)
		{
			scanf("%d",&inputs[i][j+1]);
		}
		scanf("%s",chs);
		ch=chs[0];
		inputs[i][1+cnt2]=ch;
		if(ch=='=')
		{
			for(j=1;j<=cnt2;j++)
				flag[ inputs[i][j] ]=1;
			--i;// no store
			--k;
		}
	}
	memset(coin,0,sizeof(char)*(n+1));
	for(i=1;i<=n;i++)
	{
		if( flag[i]==1) continue;
		 falseweight=-1;
		coin[i]=1;
		for(j=0;j<k;j++)
		{
			if(!ok(inputs[j]))
			{
				break;
			}
		}
		if(j==k)
		{
			if(found==0)
			{
			  found=1;
			  result=i;
			}
			else if(found==1) 
			{
				nofound=1;
				break;
			}
		}
		coin[i]=0;
	}
	if(nofound) printf("0");
	else printf("%d",result);
	
    return 0;
}