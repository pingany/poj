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

int a[100*10 + 1];
int A[100];
int c[100];
char f[100001], g[100001];
int n, m;
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
			a[na++] = A[i] * out[j];
	}
	n = na;
	sort(a, a+n);
	//unique(a, a+n);
	int mm = m+1;
	int ret =0;

	memset(f, 0, sizeof(f));
	f[0] = 1;
	forn(i, 0, n)
	{
		memset(g, 0, sizeof(g));
		int mm = m-a[i]+1;
		forn(j, 0, mm)
		{
			g[j + a[i]] |= f[j];
		}

		mm = m+1;
		forn(j, 0, mm)
			f[j] |= g[j];
	}
	forn(j, 1, mm)
		if(f[j])
			++ret;
	cout << ret;
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
	while(testcase())
		cout << "\n";
	return 0;
}