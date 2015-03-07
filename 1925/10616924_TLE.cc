#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#ifdef NO_HASH_MAP
#	define MAP map
#	include <map>
#else
#	if 0 //def __GNUC__
#		define MAP hash_map
#		include <ext/hash_map>
		using namespace __gnu_cxx;
#	elif defined(_MSC_VER)
#		define MAP hash_map
#		include <hash_map>
		using namespace stdext;
#   else 
#		define MAP map
#		include <map>
#	endif
#endif /* NO_HASH_MAP */

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
typedef unsigned long long LONG;
#define MAXN 5000
struct Point
{
	int x, y;
};

#define IMPOSSIBLE MAX_INT
#define INVALID_VALUE (-1)
struct Value
{
	int value;
	Value() { value = INVALID_VALUE; }
};
typedef MAP<int, Value> ValueMAP;
int n;
int y;
Point ps[MAXN];
LONG pow2Y[MAXN]; /* ps[j].y^2 */
LONG mul2Y[MAXN];	/* (ps[j].y-y)^2 */
ValueMAP maps[MAXN];
#define f(i, prevX) maps[i][prevX].value

inline LONG pow2(int x)
{
	return ((LONG)x)*x;
}
// LONG dis2(int x1, int y1, int x2, int y2)
// {
// 	return pow2(x1 - x2) + pow2(y1 - y2);
// }
int get(int i, int  prevX)
{
	int r = f(i, prevX);
	if(r != INVALID_VALUE)
		return r;
	int ret = IMPOSSIBLE;
	int nx = (ps[i].x << 1) - prevX;
	forn2(j, n-1, i)
	{
		if(ps[j].x <= nx)
			break; // no more x can less than nx
		LONG dis = pow2(nx - ps[j].x) + mul2Y[j]; //dis2(nx, y, ps[j].x, ps[j].y);
		if(dis < pow2Y[j])
		{
			if( j == n-1)
			{
				ret = 1;
				break;
			}
			else
			{
				int nextRet = get(j, nx);
				if(nextRet != IMPOSSIBLE && nextRet + 1 < ret)
					ret = nextRet + 1;
			}
		}
	}
	f(i, prevX) = ret;
	return ret;
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
	{	
		cin >> ps[i].x >> ps[i].y;
		maps[i].clear();
		pow2Y[i] = pow2(ps[i].y);
	}
	y = ps[0].y;
	forn(i, 0, n)
		mul2Y[i] = pow2(ps[i].y - y);

	solve();
	return true;
}

int main()
{
	ASSERT(sizeof(Value) == 4);
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