#include <iostream>
using namespace std;
unsigned int com(unsigned int a,unsigned int b)
{
	if(!a||!b)
		return 1;
	return com(a-1,b-1)*a/b;
}
int main()
{
	unsigned int n,m;
	while(cin>>m>>n &&(n||m))
		cout<<com(n+m,m<n?m:n)<< "\n";
	return 0;
}
