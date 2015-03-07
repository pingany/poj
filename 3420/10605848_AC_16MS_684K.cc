#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <queue>
#include <algorithm>  
#include <map>
#include <sstream>
using namespace std;  
 
#define INLINE inline
#ifdef LOCAL
#define ASSERT(x)	do{if(!(x)) __asm{int 3};}while(0)
#else
#define ASSERT(x)
#endif
#define forn(i, a, b)  for(int i = (a); i < (b); i++)

#define MAXN 5

typedef int Matrix [MAXN][MAXN];

const int A[MAXN][MAXN] =
{
	{1, 1, 1, 0, 1},
	{2, 1, 0, 0, 0},
	{1, 0, 0, 1, 0},
	{0, 0, 1, 0, 0},
	{1, 0, 0, 0, 0}
};
const int E[MAXN][MAXN] = 
{
	{1, 0, 0, 0, 0},
	{0, 1, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 1, 0},
	{0, 0, 0, 0, 1}
};
const Matrix init =
{
	{1, 1, 1, 0, 1}
};

const int n = 5;
int N, M;
int add(int i, int j)
{
	return (i+j)%M;
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

void solve()
{
	Matrix a;
	memcpy(a, A, sizeof(a));
	pow(a, N-1);

	Matrix result;
	memcpy(result, init, sizeof(init));
	mul(result, 1, 5, a, 5);
	cout << result[0][0] << "\n";
}

int main()
{

	ASSERT(freopen("in.txt", "r", stdin));
	while(cin >> N >> M, N)
	{
		solve();
	}
	return 0;	
}