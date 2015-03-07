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

double n, c, L;

inline double getY(double x)
{
	return (1+n*c)*sin(x) - x;
}

inline double getNextX(double x, double y)
{
	double h = (1+n*c)*cos(x) -1;
	return -y/h + x;
}

void solve()
{
	double x = 2, y = getY(x);
	while(abs(y) > 1E-9)
	{
		x = getNextX(x, y);
		y = getY(x);
	}
	double r = (1+n*c)*L/(2*x);
	double ret = r * (1 - cos(x));
	printf("%.3f\n", ret);
}

bool testcase()
{
	cin >> L >> n >> c;
	if(L < 0)
		return false;
	solve();
	return true;
}

int main()
{
	
	ASSERT(freopen("in.txt", "r",stdin));
	while(testcase());
	return 0;
}