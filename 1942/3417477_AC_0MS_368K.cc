#include <iostream>
using namespace std;
__int64 com(__int64 a,__int64 b)
{
	if(!a||!b)
		return 1;
	return com(a-1,b-1)*a/b;
}
int main()
{
	__int64 n,m;
	while(scanf("%I64d%I64d",&n,&m)&&(n||m))
		printf("%I64d\n",com(n+m,m<n?m:n));
	return 0;
}
