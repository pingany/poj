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

int f[MAXN+1][MAXN+1];
int n1, n2;
char s1[MAXN+1], s2[MAXN+1];
const int MM[5][5] = {
	{5, -1, -2, -1, -3},
	{-1, 5, -3, -2, -4},
	{-2, -3, 5, -2, -2},
	{-1, -2, -2, 5, -1},
	{-3, -4, -2, -1, 0}
};
int index[128];
#define m(c1, c2)  MM[index[c1]][index[c2]]
void solve()
{
	f[n1][n2] = 0;
	int i = n1;
	forn2(j, n2-1, -1)
	{
		f[i][j] = f[i][j+1] + m('-', s2[j]);
	}
	int j = n2;
	forn2(i, n1-1, -1)
	{
		f[i][j] = f[i+1][j] + m(s1[i], '-');
	}
	forn2(i, n1-1, -1)
		forn2(j, n2-1, -1)
		{
			int maxf = m(s1[i], s2[j]) + f[i+1][j+1];
			maxf = max(maxf, m(s1[i], '-') + f[i+1][j]);
			maxf = max(maxf, m('-', s2[j]) + f[i][j+1]);
			f[i][j] = maxf;
		}
	cout << f[0][0] << "\n";
}
int main()
{
	int T;
	index['A'] = 0;
	index['C'] = 1;
	index['G'] = 2;
	index['T'] = 3;
	index['-'] = 4;
	cin >> T;
	while (T--)
	{
		cin >> n1 >> s1;
		cin >> n2 >> s2;
		solve();
	}
	return 0;
}