#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define INLINE inline
#ifdef _MSC_VER
#define ASSERT(x)	do{if(!(x)) __asm{int 3};}while(0)
#else
#define ASSERT(x)
#endif

#define MAX_INT 0x7fffffffL
#define forn(i, a, b) for(int i = (a); i < (b); i++)
#define uint unsigned int
typedef unsigned long long LONG;
#define MAXN 5000
struct Point
{
	int x, y;
};

#define IMPOSSIBLE MAX_INT
#define INVALID_VALUE (-1)
struct PointX
{
	int x;
	PointX() { x = INVALID_VALUE; }
};
typedef map<int, PointX> MAP;
int n;
int y;
Point ps[MAXN];
MAP maps[MAXN];
#define f(i, prevX) maps[i][prevX].x

inline LONG pow2(int x)
{
	return x*x;
}
LONG dis2(int x1, int y1, int x2, int y2)
{
	return pow2(x1 - x2) + pow2(y1 - y2);
}
int get(int i, int  prevX)
{
	if( i == n-1)
		return 0;
	int& r = f(i, prevX);
	if(r != INVALID_VALUE)
		return r;
	int ret = IMPOSSIBLE;
	int nx = ps[i].x * 2 - prevX;
	forn(j, i+1, n)
	{
		LONG dis = dis2(nx, y, ps[j].x, ps[j].y);
		if(dis < ps[j].y * ps[j].y)
		{
			int nextRet = get(j, nx);
			if(nextRet != IMPOSSIBLE && nextRet + 1 < ret)
				ret = nextRet + 1;
		}
	}
	return f(i, prevX) = ret;
}

void solve()
{
	int r = get(0, ps[0].x);
	if(r == IMPOSSIBLE)
		 r = -1;
	cout << r;
}
bool testcase()
{
	cin >> n;
	forn(i, 0, n)
		cin >> ps[i].x >> ps[i].y;
	forn(i, 0, n)
		maps[i].clear();
	y = ps[0].y;
	solve();
	return true;
}

int main()
{
	ASSERT(sizeof(PointX) == 4);
	ASSERT(freopen("in.txt", "r",stdin));
	int T;
	cin >> T;
	while(T--)
	{
		testcase();
		cout << "\n";
	}
	return 0;
}