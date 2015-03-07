#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define forn(i, n)  for(int i = 0; i < (n) ; i++)
#define INLINE inline
#ifdef _MSC_VER
#define ASSERT(x)	do{if(!(x)) __asm{int 3};}while(0)
#else
#define ASSERT(x)
#endif

template<typename T>
T maxn(T* start, T*end)
{
	ASSERT(start != end);
	T result = *start;
	++start;
	while(start != end)
	{
		if(*start > result)
			result = *start;
		start++;
	}
	return result;
}

template<typename T>
T sumn(T*start, T*end)
{
	T result = T(0);
	while(start != end)
	{
		result += *start;
		start++;
	}
	return result;
}

int N;
char hs[1001][10];
int f[1002];
int f2[1002];
int f3[1002];
bool testcase()
{
	cin >> N;
	memset(hs, 0, sizeof(hs));
	memset(f, 0, sizeof(f));
	memset(f2, 0, sizeof(f2));
	for(int i = 0; i < N; i++)
	{
		cin >> hs[i];
		//remove tailing '0' for string campare
		char *p = hs[i] + strlen(hs[i]) - 1;
		while(p >= hs[i] && *p == '0')
		{
			*p = 0;
			--p;
		}
	}
	f[N-1]=1;
	for(int k = N-2; k>=0; k--)
	{
		int maxf = 0;
		for(int i = k+1; i < N; i++)
		{
			if(strcmp(hs[i], hs[k]) < 0 && f[i] > maxf)
				maxf = f[i];
		}
		f[k] = maxf + 1;
	}
	f2[0] = 1;
	for(int k = 1; k < N; k++)
	{
		int maxf = 0;
		for(int i = 0; i < k; i++)
		{
			ASSERT(f2[i] > 0);
			if(strcmp(hs[i], hs[k]) < 0 && f2[i] > maxf)
				maxf = f2[i];
		}
		f2[k] = maxf + 1;
		ASSERT(f2[k] > 0);
	}
	forn(k, N)
	{
		int maxf = f[k] + f2[k] - 1;
		for(int i = k+1; i < N; i++)
		{
			if(strcmp(hs[i], hs[k]) == 0 && f[k] + f2[i] > maxf)
				maxf = f[k] + f2[i];
		}
		f3[k] = maxf;
	}
	cout << N - maxn(f3, f3+N);
	return true;
}

int main()
{
	
	ASSERT(freopen("in.txt", "r",stdin));
	testcase();
	return 0;
}