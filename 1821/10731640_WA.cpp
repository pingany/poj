#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define INLINE inline
#ifdef LOCAL
#define ASSERT(x)	{if(!(x)) __asm{int 3};}
#else
#define ASSERT(x)
#endif

#define MAX_INT 0x7fffffffL
#define forn(i, a, b) for(int i = (a); i < (b); i++)
#define forn2(i, a, b) for(int i = (a); i > (b); i--)
typedef unsigned long long LONG;
#define uint unsigned int

#ifdef LOCAL
#define MAXN 8
#define MAXK 4
#else
#define MAXN 16000
#define MAXK 100
#endif
struct Worker
{
	int limit, price, stand;
	Worker(){}
	bool operator<(const Worker&w) const
	{
		return stand < w.stand;
	}
};
Worker works[MAXK];
int n, k;

// int ws_cmp(const Worker&w, int x)
// {
// 	return w.stand > x;
// }
// int findWorker(int x)
// {
// 	int wi = lower_bound(ws, ws+k, x, ws_cmp) - ws;
// 	return wi;
// }

int f[MAXN+2][MAXK+1];
void solve()
{
	sort(works, works+k);
	memset(f, 0, sizeof(f));
	for(int x = n; x>=1; --x)
	{
		for(int wi = k-1; wi>=0; --wi)
		{
			if(works[wi].stand >= x)
			{
				int maxf = 0;
				int end = min(n+1 - x, works[wi].limit)+1;
				forn(i, works[wi].stand+1-x, end)
				{
					int nextX = x + i;
					int p = works[wi].price*i;
					maxf = max(maxf, p + f[nextX][wi+1]);
				}
				f[x][wi] = maxf;
			}
			else
			{
				break;
			}
		}
	}
	int maxf = 0;
	forn(i, 0, k)
		maxf = max(maxf, f[1][i]);
	cout << maxf;
}
bool testcase()
{
	cin >> n >> k;
	if(!cin)
		return false;
	forn(i,0, k)
	{
		cin >> works[i].limit >> works[i].price >> works[i].stand;
	}
	solve();
	return true;
}

int main()
{
	
	ASSERT(freopen("in.txt", "r",stdin));
#ifdef LOCAL
	while(testcase())
		cout << "\n";
#else
	testcase();
#endif
	return 0;
}