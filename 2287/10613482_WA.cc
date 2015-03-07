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
void solve()
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
}

void solveQuick()
{
	sort(a, a+n);
	sort(b, b+n);
	int ret = 0 ;
	for(int i = 0, j = 0; i < n;)
		{
			if(a[i] >= b[j])
			{
				ret += (a[i] > b[j]) ? 1 : 0;
				++i;
				++j;
			}
			else 
			{
				ret --;
				++i;
			}
		}
	cout << (ret * 200);
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

int main()
{
	
	ASSERT(freopen("in.txt", "r",stdin));
	while(testcase())
		cout << "\n";
	return 0;
}