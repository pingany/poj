#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
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
struct BigInt
{
	typedef int type;
	std::vector<type> v;
	BigInt(){}
	BigInt(ULONG x)
	{
		while(x)
		{
			v.push_back(x % 10);
			x /= 10;
		}
	}
	ULONG calc()
	{
		ULONG ret = 0;
		for(int i = v.size()-1; i >=0 ; --i)
			ret = ret * 10 + v[i];
		return ret;
	}
	void trim()
	{
		int i;
		for( i = v.size()-1; i >=0 ; --i)
			if(v[i] != 0)
				break;
		v.resize(i+1);
	}
	bool operator== (ULONG x)
	{
		return calc() == x;
	}
	bool operator==(const BigInt&b) const
	{
		if(v.size() != b.v.size())
			return false;
		for(int i = v.size()-1; i >=0 ; --i)
			if(v[i] != b.v[i])
				return false;
		return true;
	}
	bool operator !=(const BigInt&b) const { return !(*this == b); }
	type& operator[](int i) { return v[i];}
	type operator[](int i) const { return v[i];}
};

#ifndef T
#define T BigInt
#endif
#define INVALID_VALUE b0
const T b0 = T();
const T b1 = T(1);

ostream& operator<< (ostream& cout, const BigInt&a)
{
	for(int i = a.v.size() -1 ; i >=0; --i)
		cout << (int)a.v[i];
	return cout;
}

BigInt operator+(const BigInt&b1, const BigInt&b2)
{
	BigInt ret;
	ret.v.resize(max(b1.v.size(), b2.v.size())+1, 0);
	int v1size = b1.v.size(), v2size = b2.v.size();
	int end = max(v1size, v2size);
	int c= 0;
	int i =0;
	while(i < end || c > 0)
	{
		c = (i < v1size ?  b1.v[i] : 0) + (i < v2size ? b2.v[i] : 0) + c;
		ret.v[i] = c % 10;
		c /= 10;
		++i;
	}
	ret.trim();
	return ret;
}

BigInt operator-(const BigInt&b1, const BigInt&b2)
{
	BigInt ret;
	ASSERT(b1.v.size() >= b2.v.size());
	ret.v.resize(max(b1.v.size(), b2.v.size())+1, 0);
	int v1size = b1.v.size(), v2size = b2.v.size();
	int end = max(v1size, v2size);
	int c= 0;
	int i =0;
	while(i < end)
	{
		c = (i < v1size ?  b1.v[i] : 0) - (i < v2size ? b2.v[i] : 0) - c;
		if(c < 0)
		{
			ASSERT( c + 10 >= 0);
			ret.v[i] = c + 10;
			c = 1;
		}
		else
		{
			ret.v[i] = c;
			c = 0;
		}
		++i;
	}
	ASSERT(c == 0);
	ret.trim();
	return ret;
}

BigInt operator*(const BigInt&a, const BigInt&b)
{
	BigInt ret;
	int v1size = a.v.size(), v2size = b.v.size();
	ret.v.resize(v1size + v2size);
	for(int i = 0; i < v1size; ++i)
	{
		int c = 0;
		int offset = i;	
		for(int j = 0; j < v2size; j++)
		{
			 c = c + a[i] * b[j] + ret[offset+j];
			 ret[offset+j] = c % 10;
			 c /= 10;
		}
		int j = offset+v2size;
		while(c > 0)
		{
			c = c + ret[j];
			ret[j] = c % 10;
			c /= 10;
			++j;
		}
	}
	ret.trim();
	return ret;
}

void testBigInt()
{
	forn(i, 999999, 1000111)
	{
		ASSERT(BigInt(i) == i);
		ASSERT(BigInt(i) - i == 0);
		ASSERT(BigInt(i+99) - i == 99);
		ASSERT(BigInt(i) + i == i+i);
		ASSERT(BigInt(i) * 0 == 0);
		ASSERT(BigInt(i) * 1 == i);
		ASSERT(BigInt(i) * 2 == i*2);
		ASSERT(BigInt(i) *BigInt(i+1) == (ULONG)i*(i+1));
	}

	ASSERT(BigInt(1ULL << 50) - BigInt(1ULL << 40) == (1ULL << 50) - (1ULL << 40));
}

T sf[51], sg[51];
// T sa[51];
T sc[51][51];

//T a(int n)
//{
//	if(sa[n] != INVALID_VALUE)
//		return sa[n];
//	return  sa[n] = (n==0 ? 1 : n* a(n-1));
//}

T c(int n, int m)
{
	ASSERT( n >= m);
	m = min(m, n-m);
	if( m == 0)
		return b1;
	if( m == 1)
		return n;
	if(sc[n][m] != INVALID_VALUE)
		return sc[n][m];
	return sc[n][m] = c(n-1, m) + c(n-1, m-1);
}

T g(int n)
{
	if( n == 0)
		return b1;
	if(sg[n] != INVALID_VALUE)
		return sg[n];
	return sg[n] = (1ULL << (n-1)) * g(n-1);
}

T f(int n)
{
	if(sf[n] != INVALID_VALUE)
		return sf[n];
	T ret =0;
	forn(x, 1, n)
	{
		ret = ret + g(n-x) * f(x) * c(n-1, x-1);
	}
	return sf[n] = g(n) - ret;
}
void solve()
{
	cout << f(n);
}

bool testcase()
{
	cin >> n;
	if(!n)
		return false;
	solve();
	return true;
}

int main()
{
#ifdef LOCAL
	testBigInt();
#endif
	// memset(sf, 0, sizeof(sf));
	// memset(sg, 0, sizeof(sg));
	ASSERT(freopen("in.txt", "r",stdin));
	while(testcase())
		cout << "\n";
	return 0;
}