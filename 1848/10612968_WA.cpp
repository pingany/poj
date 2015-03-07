#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
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

#ifdef LOCAL
#define MAXN 7
#else
#define MAXN 100
#endif
int N;

typedef std::vector<int> Node;
Node nodes[MAXN];
int f[MAXN][3];
bool visited[MAXN];
#define f(R, state) f[R][state]
#define INVALID_VALUE (-1)
#define IN_COMPUTING (-2)
#define IMPOSSIBLE  (MAX_INT/100)
void crash()
{
	int *x = 0;
		*x = 0;
}

int get(int R, int state)
{
	int ret = f(R, state);
	if(ret == IN_COMPUTING)
	{
		//Detect if we have circle in the beginning 
		crash();
	}
	if(ret != INVALID_VALUE)
		return ret;
	f[R][state] = IN_COMPUTING;
	visited[R] = true;
	ret = 0;
	int sumF0 = 0;
	for (Node::iterator i = nodes[R].begin(); i != nodes[R].end(); ++i)
		{
			if(visited[*i])
				continue;
			sumF0 += get(*i, 0);
		}
	if(state == 1)
	{
		if(nodes[R].size() == 0)
			ret = 0;
		else
			ret = sumF0;
	}
	else if(state == 2)
	{
		if(nodes[R].size() == 0)
			ret = IMPOSSIBLE;
		else
		{
			ret = IMPOSSIBLE;
			for (Node::iterator i = nodes[R].begin(); i != nodes[R].end(); ++i)
			{

				if(visited[*i])
					continue;
				int k = *i;
				ret = min(ret, min(get(k, 1), get(k, 2)) + sumF0 - get(k, 0));
			}
		}
	}
	else
	{
		if(nodes[R].size() == 0)
			ret = IMPOSSIBLE;
		else
		{
			ret = IMPOSSIBLE;
			for (Node::iterator i = nodes[R].begin(); i != nodes[R].end(); ++i)
			{

				if(visited[*i])
					continue;
				int k = *i;
				for (Node::iterator i2 = i + 1; i2 != nodes[R].end(); ++i2)
				{
					if(visited[*i2])
						continue;
					int j = *i2;
					if(j == k)
						continue;
					int minf = min(get(k, 1), get(k, 2)) + min(get(j, 1), get(j, 2)) \
					+ 1 + sumF0 - get(k, 0) - get(j, 0);
					ret = min(ret, minf);
				}
			}	

			for (Node::iterator i = nodes[R].begin(); i != nodes[R].end(); ++i)
			{

				if(visited[*i])
					continue;
				int k = *i;
				int minf = 1+ get(k, 2) + sumF0 - get(k, 0);
				ret = min(ret, minf);
			}
		}
	}
	visited[R] = false;
	ASSERT(ret != IN_COMPUTING);
	return f(R, state) = ret;
}

void solve()
{
	memset(visited, 0, sizeof(visited));

	memset(f, 0xff, sizeof(f));
	int ret = get(0, 0);
	cout << ret;
	forn(i, 0, N)
	{
		if(f(i, 0) == INVALID_VALUE && f(i, 1) == INVALID_VALUE
			&& f(i, 2) == INVALID_VALUE)
			crash();
	}

#ifdef LOCAL
	forn(R, 1, N)
	{
		
		memset(f, 0xff, sizeof(f));
		int r = get(R, 0);
		ASSERT(r == ret);
		forn(i, 0, N)
		{
			if(f(i, 0) == INVALID_VALUE && f(i, 1) == INVALID_VALUE
				&& f(i, 2) == INVALID_VALUE)
				crash();
		}
	}
#endif
}

int main()
{
	int x, y;
	cin >> N;
	int t = N-1;
	while(t--)
	{
		cin >> x >> y;
		nodes[x-1].push_back(y-1);
		nodes[y-1].push_back(x-1);
	}
	solve();
	return 0;
}