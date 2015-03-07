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
#define MIN_INT (-2147483648L)

#define forn(i, a, b) for(int i = (a); i < (b); i++)
#define forn2(i, a, b) for(int i = (a); i > (b); i--)
typedef unsigned long long LONG;
#define uint unsigned int
#define MAXN 200
int low[MAXN], up[MAXN], pairs[MAXN], multi[MAXN], table[MAXN];
int n;
// int f[MAXX+1][MAXN];
#define INVALID_VALUE MIN_INT
#define IMPOSSBILE  (MIN_INT+1)

struct XValue
{
	int x;
	XValue(): x(INVALID_VALUE){}
	// XValue(int xx): x(xx){}
	// bool operator<(const XValue o)const { return x < o.x;}
};
#ifdef SOLUTION1
#define MAXX (2*100000)
map<int, XValue> values[MAXN];
#ifdef LOCAL
char t[MAXX+1][MAXN];
#define t(X, i)  t[X+ 25*20*MAXN][i]
#endif
#define f(X, i)  (values[i][X].x)
int get(int X, int i)
{
	int &r = f(X, i);
	if(r != INVALID_VALUE)
		return r;
	if(i == n-1)
	{
		int y = X / multi[i];
		if(y >= low[i] && y <= up[i] &&  y * multi[i] == X)
		{
			r = pairs[i] * y;
#ifdef LOCAL
			t(X, i) = y;
#endif
		}
		else 
			r = IMPOSSBILE;
		return r;
	}
	int maxf = IMPOSSBILE;
	forn(k, low[i], up[i]+1)
	{
		int subx = get(X-multi[i]*k, i+1);
		if(subx != IMPOSSBILE)
		{
			subx += k*pairs[i];
			if(subx > maxf)
			{
#ifdef LOCAL
				t(X, i) = k;
#endif
				maxf = subx;
			}
		}
	}
	return r = maxf;
}
int solve()
{
	//memset(f, 0, sizeof(f));
	// int *p = (int*)(void*)f, *end = (int*)(void*)((char*)f+ sizeof(f));
	// while(p < end)
	// {
	// 	*p = INVALID_VALUE;
	// 	++p;
	// }
	forn(i, 0, n)
		values[i].clear();
	int x = get(0, 0);
#ifdef LOCAL
	cout << "Table:";
	int X = 0;
	forn(i, 0, n)
	{
		table[i] = t(X, i);
		cout << table[i] << " ";
		X -= table[i]*multi[i];
	}
	cout << "\n";
#endif
	return x;
}
#endif /* SOLUTION1 */

#define MAXX (25*20*200)
int f[MAXX+1], g[MAXX+1];
int *ff, *gg;
#define f(X) ff[X]
#define g(X) gg[X]
void reset(int*f)
{
	int *end = f+MAXX+1;
	while(f < end)
	{
		*f = IMPOSSBILE;
		++f;
	}
}
int solve2()
{
	ff = f+ 25*20*100;
	gg = g + 25*20*100;
	// int maxStart = -25*20*100, endStart = 25*20*100;
	int start, end;
	reset(f);
	//i = 0;
	forn(k, low[0], up[0]+1)
	{
		f(k*multi[0]) = k*pairs[0];
	}
	forn(i, 1, n)
	{
		if(i == n-1)
		{
			start = 0;
			end = 1; // just consider X=0
		}
		else
		{
			start = -25*20*(min(100, i+1));
			end = 25*20*(min(100, i+1));
		}
		reset(g);

		int subStart = -25*20*(min(100, i));
		int subEnd = 25*20*(min(100, i));
		forn(X, start, end)
		{
			int maxf = IMPOSSBILE;
			for(int k = low[i]; k <= up[i]; ++k)
			{
				int x = X - k * multi[i];
				if( x >= subStart && x <= subEnd)
				{
					int subx = f(x);
					if(subx != IMPOSSBILE)
						maxf = max(maxf, k*pairs[i] + subx);
				}
			}
			g(X) = maxf;
		}
		memcpy(f, g, sizeof(g));
	}
	return f(0);
}

bool testcase()
{
	cin >> n;
	if(!cin)
		return false;
	forn(i, 0, n)
	{
		cin >> pairs[i] >> multi[i]>> low[i] >> up[i] ;
	}
	cout << solve2();
	return true;
}

int main()
{
	
	ASSERT(freopen("in.txt", "r",stdin));
	while(testcase())
		cout << "\n";
	return 0;
}