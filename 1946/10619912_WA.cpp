#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define INLINE inline
#ifdef _MSC_VER
#define ASSERT(x)	do{if(!(x)) __asm{int 3};}while(0)
#else
#define ASSERT(x)
#endif

#define MAX_INT 0x7fffffffL
#define forn(i, a, b) for(int i = (a); i < (b); i++)
#define forn2(i, a, b) for(int i = (a); i > (b); i--)
#define uint unsigned int

int N, E, D;
#define MAXN 20
#define MAXE 100
#define MAXD 100
#define INVALID_VALUE 0xff
#define IMPOSSIBLE 0xfe
unsigned char f[MAXD+1][MAXE+1][MAXN+1];
#define f(d, e, n)  f[d][e][n]
#include <cmath>
int get(int d, int e, int n)
{
	if(d <= 0)
		return 0;
	ASSERT(n > 0);
	int minf = f(d, e, n);
	if(minf != INVALID_VALUE)
		return minf;

	minf = IMPOSSIBLE;
	if(e > 0)
	{
		forn2(x, sqrt((float)e), 0)
		{
			int ret = get(d-x, e-x*x, n);
			if(ret != IMPOSSIBLE)
				minf = min(minf, 1+ret);
		}
	}
	if(n > 1)
	{
		int headerEnegeLeft = E-(D-d);
		forn2(x, sqrt((float)(headerEnegeLeft)), 0)
		{
			int ret = get(d-x, headerEnegeLeft-x*x, n-1);
			if( ret != IMPOSSIBLE)
				minf = min(minf, 1+ret);
		}
	}
	return f(d, e, n)= minf;
}

void solve()
{
	memset(f, 0xff, sizeof(f));
	int ret = get(D, E, N);
	if(ret == IMPOSSIBLE)
		ret = 0;
	cout << ret;
}

bool testcase()
{
	cin >> N >> E >> D;
	if(!cin)
		return false;
	solve();
	return true;
}

int main()
{
	
	ASSERT(freopen("in.txt", "r",stdin));
#ifdef LOCAL
	while(testcase())
		cout << endl;
#else
	testcase();
#endif
	return 0;
}