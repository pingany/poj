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
LONG a[MAXN], b[MAXN]; 
void solve()
{
	sort(a, a+n);
	sort(b, b+n);
	int ret =0 ;
	for(int i = 0, j = 0; i < n;)
		{
			if(a[i] > a[j])
			{
				++ret;
				++i;
				++j;
			}
			else 
				++i;
		}
	cout << max(0, (ret - (n- ret)) * 200);
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
	solve();
	return true;
}

int main()
{
	
	ASSERT(freopen("in.txt", "r",stdin));
	while(testcase())
		cout << "\n";
	return 0;
}