#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
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

#define MAXN 10000
int n,s;
int t[MAXN], f[MAXN];
int st[MAXN+1], sf[MAXN+1];
int d[MAXN+1];
void solve()
{
	st[n] = 0;
	sf[n] = 0;
	for(int i = n-1; i >= 0; --i)
	{
		st[i] = st[i+1] + t[i];
		sf[i] = sf[i+1] + f[i];
	}
	d[n] = 0;
	for(int i = n-1; i >= 0; --i)
	{
		int minf = MAX_INT;
		forn(k, i+1, n+1)
			minf = min(minf, d[k] + (s+st[i] - st[k])*sf[i]);
		d[i] = minf;
	}
	cout << d[0];
}
bool testcase()
{
	cin >> n >> s;
	if(!cin)
		return false;
	forn(i, 0, n)
		cin >> t[i] >> f[i];
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