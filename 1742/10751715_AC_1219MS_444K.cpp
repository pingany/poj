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


int A[100];
int c[100];
int n, m;
char ok[100001];
short used[100001];

void solve()
{
	memset(ok, 0, m+1);
	ok[0] = 1;
	int ret =0;
	int mm = m+1;
	forn(i, 0, n)
	{
		memset(used, 0, sizeof(short)*(m+1));
		forn(j, A[i], mm)
		{
			if(!ok[j] && ok[j-A[i]] && used[j-A[i]] < c[i])
			{
				ok[j] = 1;
				used[j] = used[j-A[i]] +1;
				++ret;
			}
		}
	}
	printf("%d\n", ret);
}
bool testcase()
{
	scanf("%d%d", &n, &m);
	if(!n)
		return false;
	forn(i, 0, n)
		scanf("%d", A+i);
	forn(i, 0, n)
		scanf("%d", c+i);

	solve();
	return true;
}

int main()
{
	
	ASSERT(freopen("in.txt", "r",stdin));
	while(testcase());
	return 0;
}


#ifdef SOLUTION1
char f[100001], g[100001];
int a[100*10 + 1];
int to2s(int x, int out[])
{
	int outi = 0;
	int k = 1;
	for(;;)
	{
		if(k < x)
		{
			out[outi++] = k;
			x -= k;
		}
		else
		{
			out[outi++] = x;
			break;
		}
		k <<= 1;
	}
	return outi;
}

void solve()
{
	int out[11];
	int nn = n;
	int na =0 ;
	forn(i, 0, nn)
	{
		int len = to2s(c[i], out);
		ASSERT(len <= 10);
		forn(j, 0, len)
		{
			int x = A[i] * out[j];
			if(x <= m)
				a[na++] = x;
		}
	}
	n = na;
	// sort(a, a+n);
	//unique(a, a+n);
	int mm = m+1;
	int ret =0;

	memset(f, 0, m+1);
	memset(g, 0, m+1);
	f[0] = 1;
	g[0] = 1;
	forn(i, 0, n)
	{
		int mm = m-a[i]+1;
		forn(j, 0, mm)
		{
			g[j + a[i]] |= f[j];
		}
		memcpy(f, g, m+1);
	}
	forn(j, 1, mm)
		if(f[j])
			++ret;
	printf("%d\n", ret);
}
#endif
