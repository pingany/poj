#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <queue>
#include <algorithm>  
  
using namespace std;  
 
#define INLINE inline
#ifdef LOCAL
#define ASSERT(x)	do{if(!(x)) __asm{int 3};}while(0)
#else
#define ASSERT(x)
#endif
#define forn(i, a, b)  for(int i = (a); i < (b); i++)

#ifdef WIN32
typedef unsigned __int64 LONG;
#else
typedef unsigned long long LONG;
#endif

#define MAXW 11
#define MAXH 11
int w, h;
LONG f[MAXH][(1<<MAXW)];
#define f(i, j) f[i][j]
const LONG INVALID_VALUE = ((LONG)-1);

void to2(int state, char *buffer)
{
	int i = 0;
	memset(buffer, 0, w);
	while(state)
	{
		buffer[i++] = state &1;
		state >>= 1;
	}
}
bool isok(int prevstate, int state)
{
	static char sp[MAXW], ss[MAXW];
	to2(prevstate, sp);
	to2(state, ss);
	forn(i, 0, w)
	{
		int x = sp[i] ^ ss[i];
		if(x != 1)
		{
			if(sp[i] == 0 && i+1 < w && sp[i+1] == 0 && ss[i+1] == 0)
			{
				++i;
			}
			else
				return false;
		}
	}
	return true;
}
LONG get(int row, int state)
{
	if(row == h)
	{
		if(state == 0)
			return 1;
		else
			return 0;
	}
	LONG ret = 0;
	ret = f(row, state);
	if(ret != INVALID_VALUE)
		return ret;
	ret = 0;
	forn(s, 0, (1<<w))
	{
		if(isok(s, state))
			ret += get(row+1, s);
	}
	return f(row, state) = ret;
}

LONG solve()
{
	memset(f, 0xff, sizeof(f));
	return get(0, 0);
}
int main()
{
	ASSERT(freopen("in.txt", "r", stdin));
	
	while( cin >> h >> w && h)
		cout << solve() << "\n";
	return 0;
}