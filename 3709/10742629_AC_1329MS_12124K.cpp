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
#define uint unsigned int

template <typename T, unsigned int _MAXN, typename GType, 
typename _GFunction,
typename _Compare=less_equal<GType> >
struct OrderQueue
{
	typedef void (*RemoveCallback)(const T&v, const T&newElement);
	
	T vs[_MAXN];
	int m_front, m_back; 
	_GFunction g;
	_Compare pred;
	RemoveCallback removeCallback;
	
	OrderQueue(): removeCallback(NULL){ clear(); }
	void clear() { m_front = 0; m_back = -1; }
	void setRemoveCallback(RemoveCallback callback) { removeCallback = callback; }
	void push_back(const T& c)
	{
		if(size() < 2)
		{
			vs[++m_back] = c;
		}
		else
		{
			int bi;
			for(bi = m_back; bi > m_front; --bi )
			{
				T a = vs[bi-1];
				T b = vs[bi];
				if(pred(g(a, b), g(b, c)))
					break;
			}
			m_back = bi+1;
			vs[m_back] = c;
		}
	}
	void pop_front(const GType&value)
	{
		int ai;
		for(ai = m_front; ai < m_back; ++ai)
		{
			T a = vs[ai];
			T b = vs[ai+1];
			if(pred(value, g(a, b)))
				break;
		}
		m_front = ai;
	}
	int size() { return m_back-m_front+1; }
	T& front() { ASSERT(m_back>= m_front); return vs[m_front]; }
};

#if 0//def LOCAL
#define MAXN 8
#else
#define MAXN 500001
#endif
int n, k;
LONG f[MAXN], s[MAXN];
LONG dp[MAXN];

#define IMPOSSBILE (1LL << 50)

#define b(i, k)  (dp[k] + s[i] - s[k] - (i-k)*f[k+1])
struct GFunction
{
	// here k < j
	// return >=i(any possible i) means k is good than j
	LONG operator()(int k, int j)
	{
		LONG y = ((dp[k] -s[k] + k*f[k+1]) - (dp[j] -s[j] + j*f[j+1]));
		if(f[k+1] == f[j+1])
		{
			return y == 0 ? MAXN+1 : ( y < 0 ? MAXN+1: -1);
		}
	 	return y/(f[k+1] - f[j+1]); 
	}
};
OrderQueue<int, MAXN, LONG, GFunction,  less_equal<LONG> > q;
void solve()
{
	dp[0] = 0;
	forn(x, 1, k)
		dp[x] = IMPOSSBILE;
	dp[k] = b(k, 0);
	q.clear();
	q.push_back(0);
	q.push_back(1);
	forn(i, k+1, n+1)
	{
		q.pop_front(i);
		int x = q.front();
		ASSERT( x < i);
		ASSERT(dp[i] == b(i, x));
		dp[i] = b(i, x);
		if(i+1 >= k)
			q.push_back(i-k+1);
	}
	cout << dp[n];
}

void solve2()
{
	dp[0] = 0;
	forn(x, 1, k)
		dp[x] = IMPOSSBILE;
	dp[k] = b(k, 0);
	forn(i, k+1, n+1)
	{
		LONG minf = IMPOSSBILE;
		for(int j = 0; j <= i- k; ++j)
		{
			minf = min(minf, b(i, j));
		}
		dp[i] = minf;
	}
	cout << dp[n];
}
bool testcase()
{
	
	s[0] = 0;
	forn(i, 1, n+1)
		s[i] = s[i-1] + f[i];
#ifdef LOCAL
	solve2();
	cout << "\n";
#endif
	solve();
	return true;
}


#include <time.h>
int rand(int i , int j)
{
	return rand() % (j-i+1) + i;
}
void test()
{
	srand(time(NULL));
	n = rand(2, 50000);
	k = rand(2, n);
	f[0] = 0;
	forn(i, 1, n+1)
		f[i] = rand(0, 500000);
	sort(f+1, f+n+1);
	testcase();
}

int main()
{
#ifdef LOCAL
	int x = 30;
	while(x--)
		test();
#endif
	ASSERT(freopen("in.txt", "r",stdin));
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &k);
		f[0] = 0;
		forn(i, 1, n+1)
			scanf("%d", f+i);
		testcase();
		cout << "\n";
	}
	return 0;
}