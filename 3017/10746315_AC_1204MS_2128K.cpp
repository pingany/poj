#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
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

int n;
LONG m;
#ifdef LOCAL
#define MAXN 8
#else
#define MAXN 100000
#endif
int a[MAXN], q[MAXN], head, tail;
LONG f[MAXN], s[MAXN], f2[MAXN];
int bound;
multiset<LONG> sets;

inline int b(int x)
{
	int upper = x+1;
	int lower = bound+1;
	while(lower < upper)
	{
		int middle = (upper + lower) >> 1;
		if((middle == 0 ? s[x] : s[x] - s[middle-1]) > m)
			lower = middle+1;
		else 
			upper = middle;
	}
	return upper-1;
}

LONG solve()
{
	// ASSERT( (-1)/2 == -1);
	s[0] = a[0];
	forn(i, 1, n)
		s[i] = s[i-1] + a[i];
	sets.clear();
	head = 0;
	tail = -1;
	bound = -1;
	if(a[0] > m)
		return -1;
	q[++tail] = 0;
	f[0] = a[0];
	forn(i, 1, n)
	{
		bound = b(i);
		if(bound == i)
			return -1;
		ASSERT(bound >= -1);
		ASSERT(head <= tail);
		int origin_tail = tail;
		while(head <= tail && q[head] <= bound)
		{
			if(head < origin_tail)
				sets.erase(f2[head]/*f[q[head]] + a[q[head+1]]*/);
			++head;
		}
		while(head <= tail && a[q[tail]] <= a[i])
		{
			--tail;
			if(tail >= head)
				sets.erase(f2[tail]/*f[q[tail]] + a[q[tail+1]]*/);
		}
		q[++tail] = i;
		if(tail > head)
			sets.insert(f2[tail-1] = f[q[tail-1]] + a[q[tail]]);
		ASSERT(head <= tail);
		f[i] = (bound < 0 ? 0 : f[bound]) + a[q[head]];
		if(!sets.empty())
			f[i] = min(f[i], *sets.begin()); // min value of sets
		
	}
	return f[n-1];
}

bool testcase()
{
	if(2 != scanf("%d%lld", &n, &m))
		return false;
	forn(i, 0, n)
		scanf("%d", a+i);
	printf("%lld\n", solve());
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