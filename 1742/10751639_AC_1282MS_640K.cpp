#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool can_pay[100005]; 
int use_ai[100005];    
int Ai[105], Ci[105];
int n, m, ans;

int coins();

int main()
{
	int i;
	while(scanf("%d%d", &n, &m), n || m)
	{
		memset(can_pay, false, sizeof(can_pay));
		can_pay[0] = true;
		for(i = 0; i < n; ++i)
			scanf("%d", &Ai[i]);
		for(i = 0; i < n; ++i)
			scanf("%d", &Ci[i]);
        coins();
	}
	return 0;
}

int coins()
{
    int i, j;
    ans = 0;
    for(i = 0; i < n; ++i)
    {
        memset(use_ai, 0, sizeof(use_ai));
        for(j = Ai[i]; j <= m; ++j)
        {
                if(!can_pay[j] && can_pay[j - Ai[i]] && use_ai[j - Ai[i]] < Ci[i])
                {
                    can_pay[j] = true;
                    use_ai[j] = use_ai[j - Ai[i]] + 1;
                    ++ans;
                }
        }
    }
    printf("%d\n", ans);
    return 0;
}