#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
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

void print(int n, int d, bool firstNoSpace=true)
{
	while(n--)
	{
		if(firstNoSpace)
			firstNoSpace = false;
		else
			putchar(' ');
		printf("%d", d);
	}
}
bool testcase()
{
	int n;
	cin >> n;
	if(!cin)
		return false;
	int x = n%3;
	if(x == 0)
	{
		print(n/3, 3);
	}
	else if(x == 1)
	{
		print(n/3-1, 3);
		print(1, 4, false);
	}
	else
	{
		print(1, 2);
		print(n/3, 3, false);
	}
	return true;
}

int main()
{
	
//	ASSERT(freopen("in.txt", "r",stdin));
#ifdef LOCAL
	while(testcase())
		cout << "\n";
#else
	testcase();
#endif
	return 0;
}