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

#define MAXN 100000
int a[MAXN], s[MAXN+1];
int q[MAXN], head, tail;
int n,k;

inline double g(int i, int j)
{
	ASSERT(i < j);
	return ((double)(s[j] - s[i]))/(j-i);
}
void solve()
{
	s[0] = 0;
	forn(i, 1, n+1)
		s[i] = s[i-1] + a[i-1];
	head = 0;
	tail = -1;
	double maxf = 0;
	q[++tail] = 0;
	forn(i, k, n+1)
	{
		while(head < tail && g(q[head], q[head+1]) < g(q[head+1], i))
			++head;
		double x = g(q[head], i);
		maxf = max(x, maxf);
		while(head < tail && g(q[tail-1], q[tail]) > g(q[tail], i-k+1))
			--tail;
		q[++tail] = i-k+1;
	}
	cout << (int)(1000 * maxf) << "\n";
}

bool testcase()
{
	cin >> n >> k;
	if(!cin)
		return false;
	forn(i, 0, n)
		scanf("%d", a+i);
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


#ifdef SOLUTION1
double b[MAXN], f[MAXN];
int start[MAXN];
int solution;

template<typename T>
T sum(T b[], int start, int len)
{
	T ret = 0;
	for(int i = start; i< start +len; ++i)
		ret += b[i];
	return ret;
}
bool check(double avg)
{
	forn(i, 0, n)
		b[i] = a[i] - avg;
	double s;
	f[k-1] = s = sum(b, 0, k);
	start[k-1] = 0;
	
	forn(i, k, n)
	{
		f[i] = f[i-1]+b[i];
		start[i] = start[i-1];

		s = s + b[i] - b[i-k];
		if(s > f[i])
		{
			f[i] = s;
			start[i] = i-k+1;
		}
	}
	forn(i, k-1, n)
	{
		if(f[i] >= 0)
		{
		    int len = i-start[i]+1;
			solution = 1000ULL * sum(a, start[i], len) / len;
			return true;
		}
	}
	return false;
}

void solve()
{
	double maxValue =  *max_element(a, a+n);
	double minValue = *min_element(a, a+n);
	while(maxValue - minValue > 1e-9)
	{
		double middleValue = (maxValue + minValue)/2;
		if(check(middleValue))
			minValue = middleValue;
		else
			maxValue = middleValue;
	}
	if(n == 1)
		solution = a[0] * 1000;
	cout << (int)(1000 *(minValue + 1e-4)) << "\n";
}
#endif
