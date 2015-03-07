#include<iostream>
#include<cstdio>
using namespace std;
#define M 100
int a[7];
int t2;
int index=0;
inline int min(int x,int y){return x<y?x:y;}
bool flag[60001];
bool dp()
{

    

    int i,j,k,sum = 0,max=0;

    for(i=1;i<=6;i++)

        sum += a[i]*i;

    if(sum%2!=0)

        return false;

    memset(flag,0,sizeof(flag));

    flag[0] = true;

    for(i=1;i<=6;i++)

    {

        if(a[i]>0)

        {

            for(j=max;j>=0;j--)  //至于为什么要从大到小，写成从小到大的，调试一下就可以看出问题，//比如有1个1，原来flag[0] = true,循环一遍后flag[1] = true,此时再判断flag[1]=true,继续flag[2] = true就不//合题意了，从大到小可以解决这个问题

            {

                if(flag[j])

                {

                    for(k=1;k<=a[i];k++)

                    {

                        if(j+k*i==sum/2)

                            return true;

                        else if(j+k*i<sum/2&&!flag[j+k*i])

                        {

                            if(j+k*i>max) max = j+k*i;

                            if(j+k*i>sum/2) max = sum/2;

                            flag[j+k*i] = true;

                        }

                    }

                }

            }

        }

    }

    return false;

}


int main()
{
	//freopen("out2","w",stdout);
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
			if(!dp())printf("Collection #%d:\nCan't be divided.\n",++index);
			else printf("Collection #%d:\nCan be divided.\n",++index);
		}
	}
	return 0;
}
