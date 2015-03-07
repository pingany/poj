#include <iostream>
using namespace std;
long long com(long long a,long long b)
{
	if(!a||!b)
		return 1;
	return com(a-1,b-1)*a/b;
}
int main()
{
	long long n,m;
	while(cin>>m>>n &&(n||m))
		cout<<com(n+m,m<n?m:n)<< "\n";
	return 0;
}
