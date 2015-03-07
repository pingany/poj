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
#define forn(i, a, b) for(int i = (a); i < (b); i++)
#define forn2(i, a, b) for(int i = (a); i > (b); i--)
typedef unsigned long long LONG;
#define uint unsigned int
char cube[20][20][20];
char inputs[3][20][21];
int n;
bool solve()
{
	memset(cube, 1, sizeof(cube));
	forn(m, 0, 3)
		forn(i, 0, n)
			forn(j, 0, n)
			{
				if(inputs[m][i][j] == '-')
				{
					forn(k, 0, n)
					{
						if(m==0)
							cube[i][j][k] = 0;
						else if(m==1)
							cube[i][k][j] = 0;
						else
							cube[k][i][j] = 0;
					}
				}
			}
	forn(m, 0, 3)
		forn(i, 0, n)
			forn(j, 0, n)
			{
				if(inputs[m][i][j] == 'X')
				{
					// forn(k, 0, n)
					{
						if(m==0)
						{
							int ret = 0;
							forn(k, 0, n) 
								ret |= cube[i][j][k];
							if(ret == 0)
								return false;
						}
						else if(m==1)
						{
							int ret = 0;
							forn(k, 0, n) 
								ret |= cube[i][k][j];
							if(ret == 0)
								return false;
						}
						else
						{
							int ret = 0;
							forn(k, 0, n) 
								ret |= cube[k][i][j];
							if(ret == 0)
								return false;
						}
					}
				}
			}	
	return true;		

}
int caseIndex = 1;
bool testcase()
{
	cin >> n;
	if(!n)
		return false;
	forn(i, 0, 3)
		forn(j, 0, n)
			cin >> inputs[i][j];

	cout << "Data set " << (caseIndex++) << ": ";
	cout << (solve() ? "Valid set of patterns\n" : "Impossible combination\n");
	return true;
}

int main()
{
	
	ASSERT(freopen("in.txt", "r",stdin));
	while(testcase());
	return 0;
}