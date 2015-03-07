#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;

int all,find1,res,times,used[65],stick[65];
int maxlen,lenth,sum;

void dfs(int no, int curlen, int level);
void fit(int no)
{
    int i;
    if(find1==1 || no>res)
	{//find1==1剪枝4
			find1 = 1;
			 return ;
    }
	for(i=0; i<all; i++)
	{
        if(!used[i]) break;
    }
    used[i] = 1;
    times++;
    dfs(no, stick[i], i);
    times--;
    used[i] = 0;
}//剪枝：以当前最大值开始搜索一遍，无结果，返回

void dfs(int no, int curlen, int level)
{
    if(curlen == lenth)
	{
        fit(no+1);
        return ;
    }
    if(find1==1)//剪枝4
        return ;
    int i,j;
    for(i=level+1; i<all; i++)
	{//剪枝7，level+1换为0则多出31ms
        if(!used[i] && curlen+stick[i]<=lenth)
		{//剪枝6
            //就是忘了这个最基本的 curlen+stick[i]<=lenth剪枝导致TLE了一晚上
            if(all-times+1<res-no)//剪枝8，去掉多出15ms
                return ;
            used[i] = 1;
            times++;
            dfs(no, curlen+stick[i], i);
            times--;
            used[i] = 0;
            j=i;
            if(find1==1)//剪枝4，去掉多出15ms
                return ;
            while(i<all && stick[j]==stick[i])//剪枝5,去掉则TLE
                i++;
            if(i==all)return ;
            if(i!=j)i--;
        }
    }
}

void work()
{
    if(sum%res!=0)//剪枝1
        return ;
    lenth = sum / res;
    if(maxlen > lenth)//剪枝2
        return ;
    times = 0;
    fit(1);
}

int main()
{
    int i;
    while(1){
        sum = 0;
        maxlen = 0;
        scanf("%d", &all);
        if(all==0)
            break;
        for(i=0; i<all; i++){
            scanf("%d", &stick[i]);
            if(maxlen<stick[i])
                maxlen = stick[i];
            sum += stick[i];
        }
        sort(stick, stick+all, greater<int>());//剪枝3
        memset(used, 0, sizeof(used));
        times = 0;
        for(res=all; res>0; res--){
            find1 = 0;
            work();
            if(find1==1)
                break;
        }
        printf("%d\n",sum / res);
    }
    return 0;
}
