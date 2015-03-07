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
typedef long long LONG;
typedef unsigned long long ULONG;
#define uint unsigned int
int start, finish;
int f[2][33][70];
int g[33];
#define f(start, n, x)  f[start][n][x+33]

int to2(int n, int out[])
{
	int len =0 ;
	while(n)
	{
		out[len++] = n &1;
		n >>= 1;
	}
	return len;
}

bool isOk(int number)
{
	int out[33];
	int len = to2(number, out);
	int n0 =0, n1=0;
	for(int i = len-1; i>=0; --i)
	{
		if(out[i])
			++n1;
		else 
			++n0;
	}
	return n0 >= n1;
}

int f2(int i, int x)
{
	int ret = 0;
	forn(a, x, 33)
		ret += f(1, i, a) + f(0, i, a);
	return ret;
}

int get(int number)
{
	if(number == 1)
		return 1; // "0"

	int out[33];
	int len = to2(number, out);
	int ret = 0;
	forn(i, 1, len)
		ret += g[i];
	int n0 =0, n1=1;// highest digit is 1, of course
	for(int i = len-2; i>=0; --i)
	{
		if(out[i])
		{
			// if 1xx, then calc 0yy
			ret += f2(i/* i digits*/, -(n0 + 1 -n1));
			++n1;
		}
		else
		{
			++n0;
		}
	}
	return ret;
}

void solve()
{
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	f(0, 0, 0) = 1;
	f(0, 1, 1) = 1;
	f(1, 1, -1) = 1;
	g[1] = 1;
	int ret;
	forn(i, 2, 33)
	{
		forn(x, -32, 33)
		{
			f(1, i, x) = f(0, i-1, x+1) + f(1, i-1, x+1);
			f(0, i, x) = f(0, i-1, x-1) + f(1, i-1, x-1);
		}
		ret = 0;
		forn(x, 0, 33)
			ret += f(1, i, x);
		g[i] = ret;
	}
	cout << get(finish) - get(start) + (isOk(finish) ? 1 :0);
}

bool testcase()
{
	cin >> start >> finish;
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
		cout << "\n";
#else
	testcase();
#endif
	return 0;
}