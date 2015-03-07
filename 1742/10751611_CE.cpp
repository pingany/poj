#include <stdio.h>
int w[101], nu[101], n, m , e[100001], ans ;
char f[100002] ;
main () 
{
    int i, j, t ;
    while (scanf ("%d%d",&n, &m) , n | m){
        ans = 0 ; 
        for (i = 1; i <= n ; i ++ ) 
            scanf ("%d", &w[i]) ;
        for (i = 1; i <= n; i ++ ) 
            scanf ("%d", &nu[i]) ;
        memset (f, 0, 4 * (m + 1)) ;
        f[0] = 1 ; 
        for (i = 1; i <= n ; i ++ ){
            memset (e, 0, 4 * (m + 1)) ; 
            for (j = w[i]; j <= m; j ++ )
                if ( ! f[j] && f[j - w[i]] && e[j - w[i]] < nu[i]){
                    f[j] = 1 ;
                    e[j] = e[j - w[i]] + 1;
                    ans ++ ;}}
        printf ("%d\n", ans) ;}
}