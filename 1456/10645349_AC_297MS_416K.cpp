#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INLINE inline
#ifdef LOCAL
#define ASSERT(x)	do{if(!(x)) __asm{int 3};}while(0)
#else
#define ASSERT(x)
#endif

#define MAX_INT 0x7fffffffL
#define forn(i, a, b) for(int i = (a); i < (b); i++)
#define forn2(i, a, b) for(int i = (a); i > (b); i--)
#define uint unsigned int
typedef unsigned long long LONG;

struct Good
{
	int p,d;
};

bool good_cmp(const Good&g1, const Good&g2)
{
	return g1.d == g2.d ? g1.p > g2.p : g1.d > g2.d;
}
#define MAXN 10000
Good goods[MAXN];
bool testcase()
{
	int n;
	cin >> n;
	if(!cin)
		return false;
	forn(i, 0, n)
		cin >> goods[i].p >> goods[i].d;
	sort(goods, goods+n, good_cmp);
	if( n == 0)
	{
		cout << 0;
		return true;
	}
	priority_queue<int> queue;
	int ret = goods[0].p, deadline = goods[0].d;
	forn(i, 1, n)
	{
		if(goods[i].d == deadline)
		{
			queue.push(goods[i].p);
		}
		else
		{
			ASSERT(goods[i].d < deadline);
			int x = deadline -1 - goods[i].d;
			while(x-- && !queue.empty())
			{
				ret += queue.top();
				queue.pop();
			}
			queue.push(goods[i].p);
			ret += queue.top();
			queue.pop();
			deadline = goods[i].d;
		}
	}
	int x = deadline - 1;
	while(x-- && !queue.empty())
	{
		ret += queue.top();
		queue.pop();
	}
	cout << ret;
	return true;
}

int main()
{
	
	ASSERT(freopen("in.txt", "r",stdin));
	while(testcase())
		cout << "\n";
	return 0;
}