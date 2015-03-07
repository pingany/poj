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

char s[729][729];
int pow3[7] = {0, 1, 3, 9, 27, 81, 243};
bool testcase()
{
	int n;
	cin >> n;
	if(n <= 0)
		return false;
	int m = pow3[n];
	forn(i, 0, m)
	{

		forn(j, 0, m)
		{
			putchar(s[i][j]);
		}
		putchar('\n');
	}
	return true;
}
void copy(int n, int x, int y)
{
	forn(i, 0, n)
		forn(j, 0, n)
			s[i+y][j+x] = s[i][j];
}
int main()
{
	memset(s, ' ', sizeof(s));
	s[0][0] = 'X';
	forn(n, 1, 8)
	{
		copy(pow3[n-1], pow3[n-1]*2, 0);
		copy(pow3[n-1], pow3[n-1], pow3[n-1]);
		copy(pow3[n-1], 0, pow3[n-1]*2);
		copy(pow3[n-1], pow3[n-1]*2, pow3[n-1]*2);
	}
	ASSERT(freopen("in.txt", "r",stdin));
	while(testcase())
		cout << "-\n";
	return 0;
}