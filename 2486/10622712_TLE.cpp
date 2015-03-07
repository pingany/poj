#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
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

#define MAXN 100
#define MAXK 200
typedef std::vector<int> Node;
int K, N;
Node nodes[MAXN];
int apples[MAXN];
bool visited[MAXN];
int dpRecord[MAXN][MAXN][MAXK][2];
#define INVALID_DP_RECORD  (-1)

int nodeRecord[MAXN][MAXK][2];
#define INVALID_NODE_RECORD (-1)

enum Type
{
	BACK,
	NO_BACK
};

int get1(int startNode, int k, Type type, int&ret);
inline int get(int startNode, int k, Type type)
{
	if(k == 0)
		return apples[startNode];
	int& ret = nodeRecord[startNode][k][type];
	if(ret != INVALID_NODE_RECORD)
		return ret;
	return get1(startNode, k, type, ret);
}

int dp1(int startNode, int nbIndex, int k, Type type, int &ret);
inline int dp(int startNode, int nbIndex, int k, Type type)
{
	if(nbIndex < 0 || k == 0)
		return 0;
	int &ret = dpRecord[startNode][nbIndex][k][type];
	if(ret != INVALID_DP_RECORD)
		return ret;
	return dp1(startNode, nbIndex, k, type, ret);
}

int dp1(int startNode, int nbIndex, int k, Type type, int &ret)
{
	
	ASSERT(k > 0 && k <= K);
	ASSERT(nbIndex >=0 && nbIndex < nodes[startNode].size());

	
	ret = 0;	
	int theNb = nodes[startNode][nbIndex];
	if (visited[theNb])
	{
		ret = max(ret, dp(startNode, nbIndex-1, k, type));
	}
	else
	{
		// x = 0, don't access theNb
		ret = max(ret, 
				+ dp(startNode, nbIndex-1, k, type));
		if (type == BACK)
		{
			// we can't back with odd k
			for(int x = 0; x <=k-2; x+=2)
			{
				ret = max(ret, get(theNb, x, BACK) \
					+ dp(startNode, nbIndex-1, k-2-x, BACK));
			}
		}
		else
		{
			int r, lastValue = -1;
			// We do back on theNb, and do no back on one of left neighbours
			for(int x = 0; x <=k-2; x+=2)
			{
				r = get(theNb, x, BACK);
				if( r == lastValue)
					continue;
				lastValue = r;
				ret = max(ret,  r\
					+ dp(startNode, nbIndex-1, k-2-x, NO_BACK));
			}
			lastValue = -1;
			// We do no back on theNb, and do back on all of left neighbours
			for(int x = 0; x <=k-1; x+=1)
			{
				r = get(theNb, x, NO_BACK);
				if( r == lastValue)
					continue;
				lastValue = r;
				ret = max(ret, r \
					+ dp(startNode, nbIndex-1, k-1-x, BACK));
			}
		}
		
	}
	return ret;
}

int get1(int startNode, int k, Type type, int&ret)
{
	ASSERT(startNode >=0 && startNode < N);
	ASSERT(k >0 && k <= K);
	ASSERT(type == 0 || type == 1);
	visited[startNode] = true;
	Node& node = nodes[startNode];
	ret = 0;
	if(type == BACK)
	{
		ret = /*max(ret,*/ (dp(startNode, node.size()-1, k, BACK));
	}
	else
	{
		// no back, go to any one
		for (Node::iterator it = node.begin(); it != node.end(); ++it)
		{
			if(visited[*it])
				continue;
			ret = max(ret, get(*it, k-1, type));
		}
		// back, only no back on last one
		ret = max(ret, dp(startNode, node.size()-1, k, NO_BACK));
	}
	visited[startNode] = false;
	ret += apples[startNode];
	return ret;
}

bool testcase()
{
	int x, y;
	cin >> N >> K;
	if(!cin)
		return false;
	forn(i, 0, N)
		nodes[i].clear();
	forn(i, 0, N)
		cin >> apples[i];
	forn(i, 0, N-1)
	{
		cin >> x >> y;
		nodes[x-1].push_back(y-1);
		nodes[y-1].push_back(x-1);
	}
	memset(nodeRecord, 0xff, sizeof(nodeRecord));
	memset(dpRecord, 0xff, sizeof(dpRecord));
	cout << get(0, K, NO_BACK);
	return true;
}

int main()
{
	
	ASSERT(freopen("in.txt", "r",stdin));
	while(testcase())
		cout << "\n";
	return 0;
}