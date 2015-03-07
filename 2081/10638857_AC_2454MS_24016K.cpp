#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <set>
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

#define MAXN 500000
LONG f[MAXN+1];
set<LONG> records;

int main()
{
	int n;
	records.clear();
	LONG a;
	long long b;
	f[0] = a = 0;
	for(int i =1; i <= MAXN; ++i)
	{
		b = a - i;
		if(b <=0 || records.find(b) != records.end())
		{
			b = a + i;
		}
		f[i] = a = b;
		records.insert(a);
	}
	while(cin >>n, n >= 0)
	{
		cout << f[n] << "\n";
	}
}