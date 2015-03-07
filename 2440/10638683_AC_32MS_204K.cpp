#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
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

const int MAXN = 7;
const int n = 7;
typedef int Matrix[MAXN][MAXN];
const int A[MAXN][MAXN] =
{
	{ 2, 0, 0, 1, 0, 0, 0},
	{-1, 0, 0, 0, 1, 0, 0},
	{-1, 0, 0, 0, 0, 1, 0},
	{ 0, 1, 0, 0, 0, 0, 1},
	{ 0,-1,-1, 0, 0, 0, 0},
	{ 0,-1, 0, 0, 0, 0, 0},
	{ 0, 0, 1, 0, 0, 0, 0}
};

// I, unit matrix
const int I[MAXN][MAXN] = 
{
	{1, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 1}
};

// The initial state, f(1, state)
const Matrix init =
{
	{6, 2, 1, 4, 1, 1, 2}
};

int f[4] = {0, 2, 4, 6};

const int M = 2005;
int add(int i, int j)
{
	return (i+j+M+M)%M;
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

void add(Matrix&A, const Matrix& I)
{
	forn(i, 0, n)
			forn(j, 0, n)
				A[i][j] = add(A[i][j],I[i][j]);
}
void pow(Matrix&m, int t)
{
	Matrix result;
	memcpy(result, I, sizeof(I));
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

int solve(int N)
{
	if( N <= 3)
		return f[N];
	Matrix a;
	memcpy(a, A, sizeof(a));
	pow(a, N-3);

	Matrix result;
	memcpy(result, init, sizeof(init));
	mul(result, 1, n, a, n);
	return result[0][0];
}


char s[1000] = {0};
int find(int i, int n)
{
	if(n == 0)
	{
		s[i] = 0;
		if(!strstr(s, "101") && !strstr(s, "111"))
			return 1;
		else 
			return 0;
	}
	int ret = 0;
	s[i] = '0';
	ret = add(ret, find(i+1, n-1));
	s[i] = '1';
	ret = add(ret, find(i+1, n-1));
	return ret;
}

int solveSimple(int n)
{
	return find(0, n);
}
void test()
{
	forn(i, 1, 100)
	{
		int x = solve(i);
		int y = solveSimple(i);
		ASSERT(x == y);
	}
}

bool testcase()
{
	int n;
	cin >> n;
	if(!cin)
		return false;
	cout << solve(n);
	return true;
}

int main()
{
#ifdef LOCAL
	test();
#endif
	ASSERT(freopen("in.txt", "r",stdin));
	while(testcase())
		cout << "\n";
	return 0;
}