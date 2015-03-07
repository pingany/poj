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
#define forn2(i, a, b) for(int i = (a); i > (b); i--)
#define uint unsigned int

typedef unsigned long long LONG;

#define MAXN 1000
int n;
LONG a[MAXN+1], b[MAXN+1]; 
int f[MAXN+1][MAXN+1];
int solve()
{
	sort(a, a+n);
	sort(b, b+n);
	int ret = -MAXN ;
	forn2(i, n, -1)
		forn2(j, n, -1)
		{
			if(i == n || j == n)
				f[i][j] = 0;
			else
			{
				int maxf = -1 + f[i+1][j];
				if(a[i] >= b[j])
				{
					int x = a[i] == b[j] ? 0 : 1;
					maxf = max(x + f[i+1][j+1], maxf);
				}
				f[i][j] = maxf;
			}
			
		}
	ret = f[0][0];
	cout << (ret * 200);
	return ret;
}

int solveQuick()
{
	sort(a, a+n);
	sort(b, b+n);
	int ret = 0 ;
	for(int as = 0, ae = n-1, bs = 0, be = n-1;
		as <= ae;)
	{
		if(a[as] > b[bs])
		{
			as++;
			bs++;
			ret++;
		}
		else if(a[ae] > b[be])
		{
			ae--;
			be--;
			ret++;
		}
		else
		{
			ret += a[as] == b[be] ? 0 : 
				(a[as] > b[be] ? 1 : -1);
			as++;
			be--;
		}
	}
	cout << (ret * 200);
	return ret;
}
bool testcase()
{
	cin >> n;
	if(!n)
		return false;
	forn(i, 0, n)
	{
		cin >> a[i];
	}
	forn(i, 0, n)
		cin >> b[i];
	solveQuick();
	return true;
}

#ifdef LOCAL
#include <time.h>
#include <stdlib.h>
void test()
{
	srand(time(NULL));
	int t = 1000;
	while(t--)
	{
		forn(k, 10, 101)
		{
			n = k;
			forn(i, 0, n)
			{
				a[i] = rand()%10;
				b[i] = rand()%10;
			}
			int r1 = solve();
			int r2 =	solveQuick();
			ASSERT(r1 == r2);
		}
	}
}
#endif

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