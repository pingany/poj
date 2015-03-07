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

#ifdef LOCAL
#define MAXN 5
#else
#define MAXN 500
#endif
int a[MAXN];
int n, m, d, k;

typedef int Matrix [MAXN][MAXN];

Matrix E;
Matrix x;
Matrix initX;

inline void reset(Matrix&m, int row, int col)
{
	forn(i, 0, row)
		memset(m[i], 0, sizeof(m[i][0])*col);
}

inline void copy(Matrix&m, const Matrix&m2, int row, int col)
{
	forn(i, 0, row)
		memcpy(m[i], m2[i], sizeof(m[i][0])*col);
}

inline int add(int i, int j)
{
	return (i+j)%m;
}

void mul(Matrix& m, int row, int col, const Matrix&m2, int col2)
{
	static Matrix result;
	reset(result, row, col2);
	forn(i, 0, row)
		forn(j, 0, col2)
			forn(k, 0, col)
				result[i][j] = add(result[i][j], m[i][k]*m2[k][j]);
	copy(m, result, row, col2);
}

void mulSpecial(Matrix& m, int row, int col, const Matrix&m2, int col2)
{
	static Matrix result;
	reset(result, row, col2);
	int i = 0; // only first row
		forn(j, 0, col2)
			forn(k, 0, col)
				result[i][j] = add(result[i][j], m[i][k]*m2[k][j]);
	forn(i, 1, row)
	{
		forn(j, 0, col2)
			result[i][j] = result[i-1][j == 0 ? (n-1) : j-1];
	}
	copy(m, result, row, col2);
}

void add(Matrix&A, const Matrix& B)
{
	forn(i, 0, n)
			forn(j, 0, n)
				A[i][j] = add(A[i][j],B[i][j]);
}

void pow(Matrix&m, int t)
{
	static Matrix result;
	copy(result, E, n, n);
	while(t)
	{
		int x = t % 2;
		if(x)
			mulSpecial(result, n, n, m, n);
		mulSpecial(m, n, n, m, n);
		t /= 2;
	}
	copy(m, result, n, n);
}

void init()
{
	reset(E, n, n);
	forn(i, 0, n)
		E[i][i] = 1;
	
	reset(x, n, n);
	forn(i, 0, n)
	{
		forn(j, 0, n)
		{
			if(min(abs(i-j), n-abs(i-j)) <=d)
				x[j][i] = 1;
		}
	}
	forn(i, 0, n)
		initX[0][i] = a[i];

	
}

void solve()
{
	init();
	pow(x, k);
	mul(initX, 1, n, x, n);
	printf("%d", initX[0][0]);
	forn(i, 1, n)
		printf(" %d", initX[0][i]);
	printf("\n");
}

bool testcase()
{
	if(4 != scanf("%d%d%d%d", &n, &m, &d, &k))
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