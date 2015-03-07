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
typedef unsigned long long LONG;
#define uint unsigned int

#define g(k, j)  ((dp[k] - dp[j])/(st[k] - st[j]))
#define b(i, x)  (dp[x] + (s+st[i]-st[x])*sf[i])
template <typename T, unsigned int _MAXN, typename _Compare=less<T> >
struct OrderQueue
{
	typedef void (*RemoveCallback)(const T&v, const T&newElement);
	
	T vs[_MAXN];
	int m_front, m_back; 
	_Compare pred;
	RemoveCallback removeCallback;
	
	OrderQueue(): m_front(0), m_back(-1), removeCallback(NULL){}
	void clear() { m_front = 0; m_back = -1; }
	void setRemoveCallback(RemoveCallback callback) { removeCallback = callback; }
	void push_back(const T& value)
	{
		if(size() < 2)
		{
			vs[++m_back] = value;
		}
		else
		{
			int c = value;
			int bi;
			for(bi = m_back; bi > m_front; --bi )
			{
				int a = vs[bi-1];
				int b = vs[bi];
				ASSERT(a > b && b > c);
				if(g(a, b) <= g(b, c))
					break;
			}
			m_back = bi+1;
			vs[m_back] = c;
		}
	}
	void pop_front(const T&value)
	{
		int ai;
		for(ai = m_front; ai < m_back; ++ai)
		{
			int a = vs[ai];
			int b = vs[ai+1];
			ASSERT(a > b);
			if(g(a, b) >= value)
				break;
		}
		m_front = ai;
	}
	int size() { return m_back-m_front+1; }
	T& front() { ASSERT(m_back>= m_front); return vs[m_front]; }
};

#ifdef LOCAL
#define MAXN 6
#else
#define MAXN 10001
#endif
int n, s;
int t[MAXN], f[MAXN], st[MAXN], sf[MAXN];
int dp[MAXN];

OrderQueue<int, MAXN, greater<int> > q;
void solve()
{
	
	dp[n] = 0;
	q.clear();
	q.push_back(n);
	for(int i = n-1; i >=0 ; --i)
	{
		q.pop_front(sf[i]);
		int k = q.front();
		ASSERT( k > i);
		ASSERT(dp[i] == b(i, k));
		dp[i] = b(i, k);
		q.push_back(i);
	}
	cout << dp[0];
}

void solve2()
{
	dp[n] = 0;
	for(int i = n-1; i >=0 ; --i)
	{
		int minf = MAX_INT;
		forn(k, i+1, n+1)
			minf = min(minf, b(i, k));
		dp[i] = minf;
	}
	cout << dp[0];
}
bool testcase()
{
	cin >> n >> s;
	if(!cin)
		return false;
	forn(i, 0, n)
		cin >> t[i] >> f[i];
	sf[n] = 0;
	st[n] = 0;
	forn2(i, n-1, -1)
	{
		st[i] = st[i+1] + t[i];
		sf[i] = sf[i+1] + f[i];
	}
#ifdef LOCAL
	solve2();
	cout << "\n";
#endif
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