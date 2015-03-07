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

#define forn(i, a, b) for(int i = (a); i < (b); i++)
#define uint unsigned int

#define MAXM 10
#define MAXN 100

typedef struct 
{
	char ps[MAXM+1];
} LineState;

struct State
{
	unsigned short x;
	unsigned short y;
};

char ground[MAXN+1][MAXM+1];
int M, N;
State EMPTY_STATE;

int f[101][101][101];

State makeState(int i, int j)
{
	State s = {i, j};
	return s;
}
#define STATE1(i)  makeState(i, M)
#define STATE2(i, j) makeState(i, j)

LineState states(State s)
{
	LineState ls = {0};
	if(s.x != M)
		ls.ps[s.x] = 1;
	if (s.y != M)
		ls.ps[s.y] = 1;
	return ls;
}
#define canput(h, i, st1, st2) (!(ground[h][i] == 'H' || st1.ps[i] || st2.ps[i]))
#define INVALID_RECORD (-1)

#define getInt(state)  (state.x * M + state.y)
#define f(h, s1, s2)  f[h][getInt(s1)][getInt(s2)]

int solve(int h, State s1, State s2)
{
	if( h == N)
		return 0;
	int r = f(h, s1, s2);
	if(r != INVALID_RECORD)
		return r;
	LineState st1 = states(s1);
	LineState st2 = states(s2);
	// Put nothing
	r = solve(h+1, EMPTY_STATE, s1);
	forn(i, 0, M)
	{
		if(!canput(h, i, st1, st2))
			continue;
		//Put one 
		{
			r = max(r, 1 + solve(h+1, STATE1(i), s1));
		}
		forn(j, i+3, M)
		{
			if(!canput(h, j, st1, st2))
				continue;
			// Put two
			r = max(r, 2 + solve(h+1, STATE2(i, j), s1));
		}
	}
	return f(h, s1, s2) = r;
}

bool testcase()
{
	cin >> N >> M;
	forn(i, 0, N)
		cin >> ground[i];
	memset(f, 0xff, sizeof(f));
	EMPTY_STATE = makeState(M, M);
	cout << solve(0, EMPTY_STATE, EMPTY_STATE);
	return false;
}

int main()
{
	
	ASSERT(freopen("in.txt", "r",stdin));
	while(testcase());
	return 0;
}