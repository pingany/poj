#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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

struct Edge
{
	int weight;
	int c;
	int adjIndex;
	Edge(){}
	Edge(int _index, int _c, int _w): c(_c), adjIndex(_index),
		weight(_w){}
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
#ifdef LOCAL
#define MAXN (20)
#else
#define MAXN 5010
#endif

Node nodes[MAXN];

int nodeNumber;
int sourceNode, destNode;
const int MAV_EDGE = MAX_INT;
const int MAX_CAP = MAX_INT;

void addWeight(int fromNode, int toNode, int cap, int weight)
{
	Node&node = nodes[fromNode];
	Node::iterator it = find(node.begin(), node.end(), toNode);
	if(it != node.end())
	{
		it->c += cap;
		it->weight += weight;
	}
	else
		node.push_back(Edge(toNode, cap, weight));
}

int getWeight(int fromNode, int toNode)
{
	Node&node = nodes[fromNode];
	Node::iterator it = find(node.begin(), node.end(), toNode);
	ASSERT(it != node.end());
	return it->weight;
}

queue<int> visitedNodes;
bool visited[MAXN];
int father[MAXN],dis[MAXN];

// Return the size of a flow.
int spfa(int startNode)
{
	// int visitedNodesNumber = 0;
	// int destVisitNodeIndex = -1;
	memset(dis, 0xff, sizeof(dis));
	dis[startNode] = 0;
	
	while(!visitedNodes.empty())
		visitedNodes.pop();
	
	memset(visited, 0, sizeof(visited));
	visited[startNode] = 1;
	visitedNodes.push(startNode);

	bool found = false;
	while(!visitedNodes.empty())
	{
		int nodeIndex = visitedNodes.front();
		visitedNodes.pop();
		if(nodeIndex == destNode)
		{
			found = true;
			break;
		}
		Node& node = nodes[nodeIndex];
		for (std::vector<Edge>::iterator it = node.begin();
		 it != node.end(); ++it)
		{
				Edge&e = *it;
				if(dis[e.adjIndex] < (dis[nodeIndex] + e.weight) && e.c > 0)
				{
					dis[e.adjIndex] = dis[nodeIndex] + e.weight;
					father[e.adjIndex] = nodeIndex;
					if(!visited[e.adjIndex])
					{

						visited[e.adjIndex] = 1;
						visitedNodes.push(e.adjIndex);
					}
				}
		}
	}
	if(found)
	{
		int i = destNode;
		const int flowValue = 1; // hack for poj 3422
		while(i != startNode)
		{
			int weight = getWeight(father[i], i);
			addWeight(father[i], i, -flowValue, -weight);
			addWeight(i, father[i], flowValue, -weight);
			i = father[i];
		}
		return dis[destNode];
	}
	return 0;
}

int a[50][50];
bool testcase()
{
	int n, k;
	int in = scanf("%d%d", &n, &k);
	if(in != 2)
		return false;
	forn(i, 0, n)
		forn(j, 0, n)
			scanf("%d", &a[i][j]);

	#define NodeIndex(i ,j) (((i)*n + j)*2)

	sourceNode = n*n*2;
	destNode = NodeIndex(n-1, n-1)+1;
	nodeNumber = n*n*2+1;
	forn(i, 0, nodeNumber)
		nodes[i].clear();

	int nm = 0;
	forn(i, 0, n)
		forn(j, 0, n)
	{
		ASSERT(nm == NodeIndex(i, j));
		nodes[nm].push_back(Edge(nm+1, 1, a[i][j]));
		nodes[nm].push_back(Edge(nm+1, MAX_CAP, 0));
		++nm;
		if(i + 1 < n)
			nodes[nm].push_back(Edge(NodeIndex(i+1, j), MAX_CAP, 0));
		if(j+1 < n)
			nodes[nm].push_back(Edge(NodeIndex(i, j+1), MAX_CAP, 0));
		++nm;
	}
	ASSERT(nm == sourceNode);
	nodes[nm].push_back(Edge(NodeIndex(0, 0), k, 0));
	++nm;
	ASSERT(nodeNumber == nm);

	int ret =0, c;
	while(k-- && (c = spfa(sourceNode)))
		ret += c;
	printf("%d\n", ret);
	return true;
}

int main()
{
	
	ASSERT(freopen("in.txt", "r",stdin));
#ifdef LOCAL
	while(testcase())
		cout << "\n";
#else
	testcase();
#endif
	return 0;
}