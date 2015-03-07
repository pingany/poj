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

int f[11][26];
int g[11];
char inputs[11];

void solve()
{
	forn(i, 0, 26)
	{
		f[1][i] = 1;
	}
	g[1] = 26;
	int n = strlen(inputs);
	int ret;
	forn(i, 2, n+1)
	{
		int sumI = 0;
		forn(x, 0, 26)
		{
			ret = 0;
			forn(a, x+1, 26)
				ret += f[i-1][a];
			f[i][x] = ret;
			sumI += ret;
		}
		g[i] = sumI;
	}
	ret = 0;
	forn(i, 1, n)
		ret += g[i];
	forn(i, 0, n)
	{
		int start = i ==0 ? 0 : inputs[i-1]+1-'a';
		forn(x, start, inputs[i]-'a')
			ret += f[n-i][x];
	}
	cout << ret+1;
}
bool testcase()
{
	cin >> inputs;
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