#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
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
#define MAXN (4+1)
#else 
#define MAXN 201
#endif
struct Edge
{
	int c;
	int adjIndex;
	Edge(){}
	Edge(int _index, int _c): c(_c), adjIndex(_index){}
	bool operator==(const Edge&e)
	{
		return this->adjIndex == e.adjIndex;
	}
	bool operator==(const int index)
	{
		return this->adjIndex == index;
	}
};

typedef std::vector<Edge> Node;
Node nodes[MAXN];
const int MAV_EDGE = MAX_INT;
int n;
struct VisitNode
{
	int index;
	int weight;
	int parent;
	VisitNode(){}
	VisitNode(int i, int p, int w): index(i), parent(p), weight(w){}
};

bool edgeCmpByIndex(const Edge&e1, const Edge&e2)
{
	return e1.adjIndex < e2.adjIndex;
}

void addWeight(int fromNode, int toNode, int value)
{
	Node&node = nodes[fromNode];
	Node::iterator it = find(node.begin(), node.end(), toNode);
	if(it != node.end())
	{
		it->c += value;
	}
	else
	{
		node.push_back(Edge(toNode, value));
	}
}

VisitNode visitedNodes[MAXN];
bool visited[MAXN];
int bfs(int startNode)
{
	int visitedNodesNumber = 0;
	int destVisitNodeIndex = -1;
	memset(visited, 0, sizeof(visited));
	visited[startNode] = 1;
	visitedNodes[visitedNodesNumber++] = VisitNode(startNode, -1, 0);
	forn(i, 0, visitedNodesNumber)
	{
		int nodeIndex = visitedNodes[i].index;
		if(nodeIndex == n)
		{
			destVisitNodeIndex = i;
			break;
		}
		Node& node = nodes[nodeIndex];
		for (std::vector<Edge>::iterator it = node.begin();
		 it != node.end(); ++it)
		{
				Edge&e = *it;
				if(!visited[e.adjIndex] && e.c > 0)
				{
					visited[e.adjIndex] = 1;
					visitedNodes[visitedNodesNumber++] = VisitNode(e.adjIndex, i, e.c);
				}
		}
	}
	if(destVisitNodeIndex >= 0)
	{
		int i = destVisitNodeIndex;
		int minValue = MAV_EDGE;
		while(i > 0)
		{
			minValue = min(minValue, visitedNodes[i].weight);
			int parent = visitedNodes[i].parent;
			i = parent;
		}
		i = destVisitNodeIndex;
		while(i > 0)
		{
			int toNode = visitedNodes[i].index;
			int parent = visitedNodes[i].parent;
			int fromNode = visitedNodes[parent].index;
			addWeight(fromNode, toNode, -minValue);
			addWeight(toNode, fromNode, minValue);

			i = parent;
		}
		return minValue;
	}
	return 0;
}
bool testcase()
{
	int edges, s, e, c;
	cin >> edges >> n;
	if(!cin)
		return false;
	forn(i, 0, n)
		nodes[i].clear();
	forn(i, 0, edges)
	{
		cin >> s >> e >> c;
		nodes[s].push_back(Edge(e, c));
	}
	int ret = 0;
	while(c = bfs(1))
	{
		ret += c;
	}
	cout << ret;
	return true;
}

int main()
{
	
	ASSERT(freopen("in.txt", "r",stdin));
	while(testcase())
		cout << "\n";
	return 0;
}