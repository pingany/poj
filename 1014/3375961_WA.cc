#include<iostream>
#include<cstdio>
using namespace std;
#define M 100
int a[7];
int t2;
int index=0;
inline int min(int x,int y){return x<y?x:y;}
bool  solve()
{
	int i,k,j,tt;
	bool found=false;
	for(i=min(t2/6,a[6]);	i>=0;	i--)
		for(j=min( (t2-6*i)/5, a[5]);	j>=0;	 j--)
			for(k=min( (t2-6*i-5*j)/4,a[4]);	 k>=0;	k--)
			{
				tt=(t2-6*i-5*j-4*k);
				if(tt==0){ i=-1;j=-1;k=-1;found=true; break;}
				if(a[3]>=tt/3)
				{
					if(tt%3==1)
					{
						if(a[1]>=1 || a[2]>=2){ i=-1;j=-1;k=-1;found=true; break;}
					}
					else if(tt%3==2)
					{
						if(a[1]>=2 || a[2]>=1){ i=-1;j=-1;k=-1;found=true; break;}
					}
					else { i=-1;j=-1;k=-1;found=true; break;}
				}
				else 
				{
					tt=tt-3*a[3];
					if(2*a[2]+a[1]>=tt)
					{
						if(tt & 1 ==1)
						{
							if(a[1]>=1) { i=-1;j=-1;k=-1;found=true; break;}
							if(a[3]>=1)
							{
								tt+=3;//少要一个三
								if(2*a[2]+a[1]>=tt){ i=-1;j=-1;k=-1;found=true; break;}
							}
						}
						else { i=-1;j=-1;k=-1;found=true; break;}
					}
				}
			}
			return found;
}
int main()
{
	//freopen("c:/acm/pku_1014_divising.txt","r",stdin);
	while(cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6] && (a[1]+a[2]+a[3]+a[4]+a[5]+a[6]))
	{
		t2=a[1]+a[2]*2+a[3]*3+a[4]*4+a[5]*5+a[6]*6;
		if(t2 & 1 !=0)
		{
			printf("Collection #%d:\nCan't be divided.\n",++index);
		}
		else 
		{
			t2>>=1;
			if(!solve())printf("Collection #%d:\nCan't be divided.\n",++index);
			else printf("Collection #%d:\nCan be divided.\n",++index);
		}
	}
	return 0;
}