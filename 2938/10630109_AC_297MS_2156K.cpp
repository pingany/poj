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

#ifdef LOCAL
#define MAXN 7
#else
#define MAXN 1000
#endif

struct Record
{
	uint time;
	short year;
	bool mustSave;
};
Record records[MAXN];
int n;
short f[MAXN][MAXN+1];
#define IMPOSSIBLE (MAXN+1)
inline int cmp(const Record&r1, const Record&r2)
{
	return r1.time - r2.time;
}

inline int getYear(int i, int pre)
{
	return cmp(records[i], records[pre]) >= 0 
		? records[pre].year - 1 : records[pre].year;
}
void solve()
{
	records[0].year = 0;
	forn(i, 1, n)
	{
		records[i].year = getYear(i, i-1);
	}
	forn(i, 0, n)
		f[i][n] = 0;
	forn2(pre, n-1, -1)
		forn2(i, n-1, pre)
		{
			int minf;
			int year = getYear(i, pre);
			if(year == records[i].year)
			{
				// if(i + 1 < n)
				// 	minf = records[i].mustSave ? 1 : 0;
				// else
				{
					minf = 1+f[i][i+1];
					if(!records[i].mustSave)
						minf = min(minf, (int)f[pre][i+1]);
				}
			}
			else if(records[i].mustSave)
			{
				minf = IMPOSSIBLE;
			}
			else
			{
				minf = f[pre][i+1];
			}
			f[pre][i] = minf;
		}
	int minf = IMPOSSIBLE;
	bool canRemoveAll = true;
	forn(pre, 0, n)
	{
		if (records[pre].mustSave)
		{
			canRemoveAll = false;
			break;
		}
	}
	if(canRemoveAll)
		minf = 0;
	else
	{
		forn(pre, 0, n)
		{
			if(records[pre].year != 0)
				break;
			minf = min(minf, 1+(int)f[pre][pre+1]);
			if(records[pre].mustSave)
			{
				break;
			}
		}
	}
	ASSERT(minf < IMPOSSIBLE);
	cout << minf;
}

bool testcase()
{
	char number [20];
	uint t1, t2, t3, t4;
	char c;
	scanf("%d", &n);
	if(!n)
		return false;
	forn(i, 0, n)
	{
		//cin >> records[n-1-i].date >> number >> c;
		scanf("%d:%d:%d:%d %s %c", &t1, &t2, &t3, &t4, number, &c);
		records[n-1-i].time = (t1 << 24) | (t2 << 16) | (t3 << 8) | t4;
		records[n-1-i].mustSave = c == '+';
	}
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