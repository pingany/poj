#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define INLINE inline
#ifdef LOCAL
#define ASSERT(x)	{if(!(x)) __asm{int 3};}
#else
#define ASSERT(x)
#endif

#define MAX_INT 0x7fffffffL
#define forn(i, a, b) for(int i = (a); i < (b); i++)
#define forn2(i, a, b) for(int i = (a); i > (b); i--)
typedef unsigned long long LONG;
#define uint unsigned int
set<int> peoplesIn;
map<int, set<int>> candidateNames;

#define MAXN 20
map<string, int> userIndexs, nameIndexs;
string names[MAXN+1], userNames[MAXN+1];

int result[MAXN+1];
bool nameMatched[MAXN+1];
int n;

#define INVALID_VALUE (-1)

void interect(set<int>&a, const set<int>&b)
{
	for (std::set<int>::iterator i = a.begin(); i != a.end();)
	{
		if(b.find(*i) == b.end())
			i = a.erase(i);
		else 
			++i;
	}
}

void addResult(int uid, int nameid)
{
	result[uid] = nameid;
	nameMatched[nameid] = true;
	peoplesIn.erase(nameid);
}

struct Output
{
	string name;
	string other;
	Output(){}
	Output(const string&n, const string&o): name(n), other(o){}
	bool operator<(const Output&another)
	{
		return name < another.name;
	}
};
bool testcase()
{
	cin >> n;
	if(!cin)
		return false;
	peoplesIn.clear();
	candidateNames.clear();
	userIndexs.clear();
	nameIndexs.clear();
	string userIdString, name;
	forn(i, 1, n+1)
	{
		cin >> userIdString;
		userIndexs[userIdString] = i;
		userNames[i] = userIdString;
	}
	int uniqNameId = 1;
	memset(result, 0xff, sizeof(result));
	memset(nameMatched, 0,sizeof(nameMatched));
	char action;
	while(cin >> action, action != 'Q')
	{
		if(action == 'M')
		{
			cin >> userIdString;
			int uid = userIndexs[userIdString];
			if(result[uid] != INVALID_VALUE)
				continue;
			set<int>&candidates = candidateNames[uid];
			if(candidates.empty())
			{
				candidates = peoplesIn;
			}
			else
			{
				interect(candidates, peoplesIn);
			}
			if(candidates.size() == 1)
			{
				int nameid =  *candidates.begin();
				ASSERT(result[uid] == INVALID_VALUE);
				addResult(uid, nameid);
				candidateNames.erase(candidateNames.find(uid));
				queue<int> removeNames;
				removeNames.push(nameid);
				while(!removeNames.empty())
				{
					int nameid = removeNames.front();
					removeNames.pop();
					for (std::map<int, set<int>>::iterator i = candidateNames.begin();
					 i != candidateNames.end();)
					{
						i->second.erase(nameid);
						if(i->second.size() == 1)
						{
							int nameid = *(i->second.begin());
							ASSERT(result[i->first] == INVALID_VALUE);
							addResult(i->first, nameid);
							removeNames.push(nameid);
							i = candidateNames.erase(i);
						}
						else 
							++i;
					}
				}
			}
		}
		else
		{
			cin >> name;
			int& nameid = nameIndexs[name];
			if(!nameid)
			{
				nameid = uniqNameId++;
				names[nameid] = name;
			}
			if(nameMatched[nameid])
				continue;
			if(action == 'E')
				peoplesIn.insert(nameid);
			else
				peoplesIn.erase(nameid);
		}
	}
	std::vector<Output> outputs;
	forn(i, 1, n+1)
	{
		if(result[i] != INVALID_VALUE)
		{
			outputs.push_back(Output(names[result[i]], userNames[i]));
		}
	}
	forn(i, 1, n+1)
	{
		if(!nameMatched[i])
		{
			outputs.push_back(Output(names[i], "???"));
		}
	}
	sort(outputs.begin(), outputs.end());
	for (std::vector<Output>::iterator i = outputs.begin(); i != outputs.end(); ++i)
	{
		cout << i->name << ":" << i->other << "\n";
	}
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