#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define INLINE inline
#ifdef LOCAL
#define ASSERT(x)	{if(!(x)) __asm{int 3};}
#else
#define ASSERT(x)
#endif

#define MAX_INT 0x7fffffffL
#define MIN_INT (-2147483648)
#define forn(i, a, b) for(int i = (a); i < (b); i++)
#define forn2(i, a, b) for(int i = (a); i > (b); i--)
typedef unsigned long long LONG;
#define uint unsigned int
struct Value
{
	int value;
	int pos;
};

int n,k;
#define MAXN 1000000
int a[MAXN];
Value vs[MAXN];
template <typename _Compare>
void solve(_Compare cmp, int minValue)
{
	int front,back;
	int minPos;
	if(n <= 0)
		return;
	minValue = a[0];
	minPos = 0;
	forn(i, 1, k)
	{
		if(cmp(a[i], minValue))
		{
			minValue = a[i];
			minPos = i;
		}
	}
	front = 0;
	vs[0].value = minValue;
	vs[0].pos = minPos;
	back = 0;
	forn(i, minPos+1, k)
	{
		if(!cmp(a[i], minValue))
		{
			++back;
			vs[back].value = a[i];
			vs[back].pos = i;
		}
	}
	printf("%d", minValue);
	forn(i, k, n)
	{
		bool found = false;
		ASSERT(back >= front);
		if(i - vs[front].pos >= k)
			front++;
		for(int x = back; x >=front; --x)
		{
			if(!cmp(a[i], vs[x].value))
			{
				found = true;
				back = x+1;
				vs[back].value = a[i];
				vs[back].pos = i;
				break;
			}
		}
		if(!found)
		{
			back = front;

			vs[back].value = a[i];
			vs[back].pos = i;
		}
		printf(" %d", vs[front].value);
	}
	printf("\n");
}

bool testcase()
{
	if(2 != scanf("%d%d", &n, &k))
		return false;
	forn(i, 0, n)
		scanf("%d", a+i);
	solve(less<int>(), MAX_INT);
	solve(greater<int>(), MIN_INT);
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