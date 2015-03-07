#include <iostream>
using namespace std;

const int N = 10005;

struct EDGE
{
 int i, j, k;
}edge[3*N];
int n, E, V;

void read()
{
 int i, j, k;
 scanf("%d", &k);

 while( k-- )
 {
  scanf("%d%d", &i, &j);
  if(V<j) V = j;
  edge[ E ].i = j+1;
  edge[ E ].j =  i;
  edge[ E ++ ].k = -2;
 }
 V++;
 for( i=1; i<=V; i++)
 {
  edge[ E ].i = i;
  edge[ E ].j = i-1;
  edge[ E ++ ].k = 0;
  edge[ E ].i = i-1;
  edge[ E ].j = i;
  edge[ E ++].k = 1;
 }
}
void bellman_ford()
{
 int i, j, dis[N];
 memset(dis, 0, sizeof(dis));
 bool ok = true;
 for(i=0; ok && i<V; i++)
 {
  ok = false;
  for(j=0; j<E; j++)
   if( dis[ edge[j].j ] > dis[ edge[j].i ] + edge[j].k )
   {
    dis[ edge[j].j ] = dis[ edge[j].i ] + edge[j].k;
    ok = true;
   }
 }
 printf("%d\n", dis[V]);
}
int main()
{
 read();
 bellman_ford();
 return 0;
}