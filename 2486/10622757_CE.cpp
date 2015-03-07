#include <stdio.h>
#include <string.h>
#include <vector>
#define MAX 101
using namespace std;
int apple[MAX], bk[MAX][MAX*2], go[MAX][MAX*2], n, k, temp1[MAX*2], temp2[MA
X*2];
vector<int> nxt[MAX];
int max(int x, int y){return x>y?x:y;}
void dp(int x, int y){
        int i, j;
        memset(temp1,0,sizeof(temp1));
        memset(temp2,0,sizeof(temp2));
        for(i=0;i<=k;i++)for(j=0;j<=i;j++)temp1[i] = max(temp1[i], max(bk[x][j]+go[
y][i-j], bk[y][j]+go[x][i-j]) );
        for(i=0;i<=k;i++)for(j=0;j<=i;j++)temp2[i] = max(temp2[i], bk[x][j]+bk[y][i
-j] );
        for(i=0;i<=k;i++)bk[x][i] = temp2[i], go[x][i] = temp1[i];
        return ;
}
void search(int x, int f){
        int i, j, l;
        for(i=0;i<nxt[x].size();i++)if( (j=nxt[x][i]) != f ){
                search(j,x);
                for(l=k;l>=2;l--)bk[j][l] = bk[j][l-2] + apple[j];
                bk[j][0] = bk[j][1] = go[j][0] = 0;
                for(l=k;l>=1;l--)go[j][l] = go[j][l-1] + apple[j];
                dp(x,j);
        }
        return ;
}
int main(){
//      freopen("Apple.in","r",stdin);
//      freopen("Apple.out","w",stdout);
        int i, a, b;
        while( scanf("%d%d",&n,&k)!=EOF ){
                for(i=0;i<n;i++)nxt[i].clear();
                memset(bk,0,sizeof(bk));
                memset(go,0,sizeof(go));
                for(i=0;i<n;i++)scanf("%d",apple+i);
                for(i=1;i<n;i++){
                        scanf("%d%d",&a,&b);
                        a--,b--;
                        nxt[a].push_back(b);
                        nxt[b].push_back(a);
                }
                search(0,0);
                printf("%d\n",go[0][k] + apple[0]);
        }
        return 0;
}