#include<stdio.h>
#include<algorithm>
using namespace std;
int a[25][805];
int p[205],d[205];
short last[25][805];
int s[25];
int abc(int x)
{
    return (x>0)?x:(-x);
}
int main()
{
    int base,l,n,m,i,j,k,cur,num=1,min,l2;
    while(scanf("%d%d",&n,&m),n&&m)
    {
        cur=20*m*2;
        for(i=1;i<=n;i++)
        scanf("%d%d",&d[i],&p[i]);
        for(i=0;i<=m;i++)
        for(j=0;j<=cur;j++)
        {
            last[i][j]=-1;
            a[i][j]=-1;
        }
        base=cur/2;
        for(i=1;i<=n;i++)
        if(a[1][d[i]-p[i]+base]<d[i]+p[i])
        {
            last[1][d[i]-p[i]+base]=i;
            a[1][d[i]-p[i]+base]=d[i]+p[i];
        }
        for(j=2;j<=m;j++)
        for(k=0;k<=cur;k++)
        if(last[j-1][k]!=-1)
        {
            for(i=1;i<=n;i++)
            {
                for(l=j-1,l2=k;l>=1;l--)
                {
                    if(last[l][l2]==i)
                    break;
                    l2=l2-d[last[l][l2]]+p[last[l][l2]];
                }
                if(l<1)
                {
                    if(a[j-1][k]+d[i]+p[i]>a[j][k+d[i]-p[i]])
                    {
                        last[j][k+d[i]-p[i]]=i;
                        a[j][k+d[i]-p[i]]=a[j-1][k]+d[i]+p[i];
                    }
                }
            }
        }
        min=cur+1;
        for(k=0;k<=cur;k++)
        if(last[m][k]!=-1&&abc(k-base)<abc(min-base)||(abc(k-base)==abc(min-base)&&a[m][k]>a[m][min]))
        {
            min=k;
        }
        printf("Jury #%d\n",num++);
        printf("Best jury has value %d for prosecution and value %d for defence:\n",(a[m][min]+min-base)/2,(a[m][min]-min+base)/2);
        for(j=m,cur=0;j>=1;j--,cur++)
        {
            s[cur]=last[j][min];
            min=min-d[last[j][min]]+p[last[j][min]];
        }
        sort(s,s+cur);
        for(i=0;i<cur;i++)
        {
            putchar(' ');
            printf("%d",s[i]);
        }
        putchar('\n');
        putchar('\n');
    }
    return 0;
}

