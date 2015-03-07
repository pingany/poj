# include <cstdio>
# include <set>
using namespace std;
# define N 100001
int data[N],n,q[N],s=-1,e=-1;
long long sum[N],dp[N],m;
struct cmp
{
	bool operator()(long long a,long long b)
	{
		return a<b;
	}
};
set<long long,cmp> refer;
int bsearch(int pos)
{
	int s=0,e=pos;
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(sum[pos]-sum[mid]<=m)
			e=mid-1;
		else
			s=mid+1;
	}
	return e+1;
}
int min(long long a,long long b)
{
	return a<b?a:b;
}

int main()
{
	scanf("%d%lld",&n,&m);
	data[0]=sum[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&data[i]);
		sum[i]=data[i]+sum[i-1];
	}
	dp[1]=data[1];
	q[++e]=1;
	for(int i=2;i<=n;i++)
	{
		int p=bsearch(i);//满足条件的决策下限值
		if(p==i)//嘻嘻，可以提前结束喽
		{
			cout<<-1<<endl;
			return 0;
		}
		while(s!=e&&data[q[e]]<=data[i])//维护单调队列，把队尾元素的data值小于当前data值的全部T了，同时维护BST
		{
			if(e-1!=s)
				refer.erase(dp[q[e-1]]+data[q[e]]);
			e--;
		}
		while(s!=e&&q[s+1]<p)//从队头开始，把不满足下限限制的值全部T了，同时维护BST
		{
			if(s+1!=e)
				refer.erase(dp[q[s+1]]+data[q[s+2]]);
			s++;
		}
		q[++e]=i;//把当前值丢到队列里
		if(s!=e-1)
			refer.insert(dp[q[e-1]]+data[q[e]]);//恩，在BST里加入决策值
		dp[i]=dp[p]+data[q[s+1]];//特殊点判断
		if(!refer.empty())
			dp[i]=min(dp[i],*refer.begin());//在BST里取最小值，恩，就是最佳决策～
	}
	printf("%lld\n",dp[n]);//AC～
	return 0;


}