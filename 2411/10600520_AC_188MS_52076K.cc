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
#define MAX_STATES (1<<MAXW)
int w, h;
LONG f[MAXW+1][MAXH][MAX_STATES];
char ok[MAXW+1][MAX_STATES][MAX_STATES];
#define ok(i, j) ok[w][i][j]
#define f(i, j) f[w][i][j]
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
int isok(int prevstate, int state)
{
	char *r = &ok(prevstate, state);
	if(*r != -1)
		return *r;
	// static char sp[MAXW], ss[MAXW];
	// to2(prevstate, sp);
	// to2(state, ss);
	int sp, ss;
	forn(i, 0, w)
	{
		sp = prevstate &1;
		ss = state &1;
		if((sp ^ ss) != 1)
		{
			prevstate >>= 1;
			state >>= 1;
			if(sp == 0 && i+1 < w &&  (prevstate&1)== 0 && (state&1) == 0)
			{
				i++;
			}
			else
				return (*r) = 0;
		}
		prevstate >>= 1;
		state >>= 1;
	}
	return (*r) = 1;
}
LONG get(int row, int state)
{
	// if(row < 0)
	// {
	// 	if(state == 0)
	// 		return 1;
	// 	else
	// 		return 0;
	// }
	LONG ret = 0;
	ret = f(row, state);
	if(ret != INVALID_VALUE)
		return ret;
	if(row == 0)
	{
		return (LONG)(isok(0 , state));
	}
	ret = 0;
	forn(s, 0, (1<<w))
	{
		if(isok(s, state))
			ret += get(row-1, s);
	}
	return f(row, state) = ret;
}

LONG solve()
{
	if ((w&1) && (h&1)) 
		return 0;
	else
	{
		if(w > h)
			swap(w, h);
		return get(h-1, 0);
	}
		
}
int main()
{
	ASSERT(freopen("in.txt", "r", stdin));
	
	memset(f, 0xff, sizeof(f));
	memset(ok, 0xff, sizeof(ok));
	while( cin >> h >> w && h)
		cout << solve() << "\n";
	return 0;
}