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

#if 0//def LOCAL
#define MAXN 8
#define MAXK 4
#else
#define MAXN 16000
#define MAXK 100
#endif
struct Worker
{
	int limit, price, stand;
	Worker(){}
	bool operator<(const Worker&w) const
	{
		return stand < w.stand;
	}
};
Worker works[MAXK];
int n, k;

// int ws_cmp(const Worker&w, int x)
// {
// 	return w.stand > x;
// }
// int findWorker(int x)
// {
// 	int wi = lower_bound(ws, ws+k, x, ws_cmp) - ws;
// 	return wi;
// }

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
		bool found = false;
		int origin_back = m_back;
		for(int x = m_back; x >=m_front; --x)
		{
			if(pred(vs[x], value))
			{
				found = true;
				m_back = x+1;
				break;
			}
		}
		if(!found)
		{
			m_back = m_front;
		}
		if(removeCallback)
			for(int x = m_back; x <= origin_back; ++x)
			{
				removeCallback(vs[x], value);
			}
		vs[m_back] = value;
	}
	int size() { return m_back-m_front+1; }
	T& front() { ASSERT(m_back>= m_front); return vs[m_front]; }
	
	template<typename _Pred>
	T& frontWithCondition(const _Pred& pred)
	{
		for(int x = m_front; x <= m_back; ++x)
		{
			if(pred(vs[x]))
				return vs[x];
		}
		ASSERT(false);
	}

	// void pop_front() { ASSERT(back >= front); front++; }
};

struct Value
{
	int pos;
	int value;
};

Value makeValue(int pos, int v) 
{
	Value p = {pos, v};
	return p;
}
struct ValueCmp
{
	bool operator()(const Value&v1, const Value&v2) const
	{
		return v1.value > v2.value;
	}
};

struct Condition
{
	int end;
	Condition(int e): end(e){}
	bool operator()(const Value&v) const
	{
		return v.pos <= end;
	}
};
int f[MAXN+2][MAXK+1];
OrderQueue<Value, MAXN+2, ValueCmp > q;
void solve()
{
	sort(works, works+k);
	memset(f, 0, sizeof(f));

	for(int wi = k-1; wi>=0; --wi)
	{
		int z = 0;
		q.clear();
		for(int x = n+1; x>=1; --x)
		{
			if(x <= works[wi].stand)
			{
				int maxf = f[x][wi+1];
				int end = min(max(works[wi].stand+1, x + works[wi].limit), n+1); 
				z = q.frontWithCondition(Condition(end)).value;
				maxf = max(maxf, z - works[wi].price * x);
				
				f[x][wi] = maxf;
			}
			else
			{
				f[x][wi] = f[x][wi+1];
				z = works[wi].price*x + f[x][wi+1];
				q.push_back(makeValue(x, z));
			}
		}
	}
	// int maxf = 0;
	// forn(i, 0, k)
	// 	maxf = max(maxf, f[1][i]);
	cout << f[1][0];
}
bool testcase()
{
	cin >> n >> k;
	if(!cin)
		return false;
	forn(i,0, k)
	{
		cin >> works[i].limit >> works[i].price >> works[i].stand;
	}
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