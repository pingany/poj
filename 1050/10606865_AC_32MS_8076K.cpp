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
#define forn2(i, a, b)  for(int i = (a); i > (b); i--)

#define MAXN 100
int N;
int a[MAXN][MAXN];
int s[MAXN][MAXN][MAXN];
int f[MAXN][MAXN][MAXN];

void solve()
{
	forn(i, 0, N)
		forn2(j, N-1, -1)
			forn(k, 1, (N-j))
			{
				if(k == 1)
					s[i][j][k] = a[i][j];
				else
				{
					s[i][j][k] = s[i][j+1][k-1] + a[i][j];
				}
			}
	int maxf = -127 * MAXN * MAXN;
	forn2(i, N-1, -1)
		forn(j, 0, N)
			forn(k, 1, (N-j))
			{
				f[i][j][k] = max(s[i][j][k], s[i][j][k] + \
					((i+1 < N) ? f[i+1][j][k] : 0));
				maxf = max(maxf, f[i][j][k]);
			}
	cout << maxf;

}
int main()
{
	cin >> N;
	forn(i, 0, N)
	forn(j, 0, N)
		cin >> a[i][j];
	solve();
	return 0;
}