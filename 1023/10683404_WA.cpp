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


#define MAXK 64
int k;
char s[MAXK+1];
long long N;

unsigned long long getRepr(int index, bool positive)
{
	char* sp = s+index, *spEnd = s+k;
	char pChar, nChar;
	if(positive)
	{
		pChar = 'p'; nChar = 'n';
	}
	else
	{
		pChar = 'n'; nChar = 'p';
	}
	if(*sp == pChar)
		return (1ULL << index);
	unsigned long long ret = 0;
	while(sp < spEnd && *sp == nChar)
	{
			ret += (1ULL << index);
			++index;
			++sp;
	}
	if(sp == spEnd)
		return 0; // failed;
	ASSERT(*sp == pChar);
	ret += (1ULL << index);
	return ret;
}

void reverse(char*s, int len)
{
	char *p = s+len-1;
	while(s < p)
	{
		swap(*s, *p);
		++s;
		--p;
	}
}
bool solve()
{
	bool positive = N >= 0;
	N = positive ? N : -N;
	int index = 0;
	unsigned long long ret = 0;
	unsigned long long limit = (~0ULL) >> (64-k);
	reverse(s, k);
	while(N)
	{
		if(N&1)
		{
			unsigned long long x = getRepr(index, positive);
			if(!x)
				return false;
			if(ret + x < ret || ret + x < x || ret + x > limit)
				return false;
			ret += x;
		}
		++index;
		N >>= 1;
	}
	char result[MAXK+1] = {0};
	int i =0 ;
	while(ret)
	{
		if(ret & 1)
			result[i++] = '1';
		else 
			result[i++] = '0';
		ret >>= 1;
	}
	result[i] = 0;
	reverse(result, i);
	if(!*result)
		*result = '0';
	cout << result;
	return true;
}

int main()
{
	
	ASSERT(freopen("in.txt", "r",stdin));
	int T;
	cin >> T;
	while(T--)
	{
		cin >> k  >> s >> N;
		if(!solve())
			cout << "Impossible";
		cout << "\n";
	}
	return 0;
}