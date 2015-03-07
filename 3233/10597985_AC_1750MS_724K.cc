#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define INLINE inline
#ifdef _MSC_VER
#define ASSERT(x)	do{if(!(x)) __asm{int 3};}while(0)
#else
#define ASSERT(x)
#endif

#define MAX_INT 0x7fffffffL
#define forn(i, a, b) for(int i = (a); i < (b); i++)
#define uint unsigned int
#define MAXN 30
typedef unsigned short Matrix [MAXN][MAXN];
Matrix E;

#define P 10000

int n, k, m;

int add(int i, int j)
{
	return (i+j)%m;
}
void mul(Matrix& m, int row, int col, const Matrix&m2, int col2)
{
	Matrix result = {0};
	forn(i, 0, row)
		forn(j, 0, col2)
			forn(k, 0, col)
				result[i][j] = add(result[i][j], m[i][k]*m2[k][j]);
	memcpy(m, result, sizeof(result));
}

void add(Matrix&A, const Matrix& E)
{
	forn(i, 0, n)
			forn(j, 0, n)
				A[i][j] = add(A[i][j],E[i][j]);
}

// return m ^ t
void pow(Matrix&m, int t)
{
	Matrix result;
	memcpy(result, E, sizeof(E));
	while(t)
	{
		int x = t % 2;
		if(x)
			mul(result, n, n, m, n);
		mul(m, n, n, m, n);
		t /= 2;
	}
	memcpy(m, result, sizeof(m));
}

// return a^1 + a^2 + ... + a^k
void solveSimple(Matrix& a, int k)
{
	Matrix result = {0};
	Matrix origin;
	memcpy(origin, a, sizeof(a));
	while(k--)
	{
		add(result, a);
		mul(a, n, n, origin, n);
	}
	memcpy(a, result, sizeof(a));
}

// return a^1 + a^2 + ... + a^k
void solveByHalf(Matrix&a, int k)
{
	if(k <= 10)
	{
		solveSimple(a, k);
		return;
	}
	Matrix origin;
	memcpy(origin, a, sizeof(origin));
	int t = k/2;
	solveByHalf(a, t);
	// a = origin^1 + ... + origin^t

	Matrix b;
	memcpy(b, origin, sizeof(origin));
	pow(b, t);
	add(b, E);
	// b = origin^t +1

	mul(a, n, n, b, n);
	if(k & 1)
	{
		memcpy(b, origin, sizeof(origin));
		pow(b, k);
		add(a, b);
		// a  = a + origin^k
	}
}

void solve()
{
	Matrix a;
	memset(E, 0, sizeof(E));
	forn(i, 0, n)
		E[i][i] = 1;
	forn(i, 0, n)
		forn(j, 0, n)
		{
			int t;
			cin >> t;
			a[i][j] = t % m;
		}
	solveByHalf(a, k);
	forn(i, 0, n)
	{
		cout << a[i][0];
		forn(j, 1, n)
			cout << " " << a[i][j];
		cout << "\n";
	}
}

bool testcase()
{
	cin >> n >> k >> m;
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