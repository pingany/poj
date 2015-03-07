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
#define MAXN 100000
int n;
int heights[MAXN+1];

void solve()
{
	LONG maxf = 0;
	forn(i, 0, n)
	{
		int h = heights[i];
		int j = i+1;
		while(heights[j] >= h)
			j++;
		maxf = max(maxf, (j-i)*(LONG)h);
	}
	printf("%d\n", maxf);
}

bool testcase()
{
	scanf("%d", &n);
	if(!n)
		return false;
	forn(i, 0, n)
		scanf("%d", heights+i);
	heights[n] = -1; // for while in solve()
	solve();
	return true;
}

int main()
{
	
	ASSERT(freopen("in.txt", "r",stdin));
	while(testcase());
	return 0;
}