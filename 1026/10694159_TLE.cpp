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
typedef char Message[201];
int n;
int keys[201];
void encode(char *message)
{
	Message a;
	memcpy(a, message, n+1);
	forn(i, 0, n)
		a[keys[i]] = message[i];
	memcpy(message, a, n+1);
}

bool testcase()
{
	cin >> n;
	if(!n)
		return false;
	forn(i, 0, n)
	{
		cin >> keys[i];
		--keys[i];
	}
	int k;
	char space;
	Message message;
	while(cin >> k, k)
	{
		getchar();
		gets(message);
		int len = strlen(message);
		forn(i, len, n)
			message[i] = ' ';
		message[n] = 0;
		while(k--)
			encode(message);
		cout << message << "\n";
	}
	
	return true;
}

int main()
{
	
	ASSERT(freopen("in.txt", "r",stdin));
	while(testcase())
		cout << "\n";
	return 0;
}