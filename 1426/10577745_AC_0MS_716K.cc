#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <queue>  
  
using namespace std;  
  
bool visited[200];  
queue<long long>que;  
  
long long bfs(int n)  
{  
    memset(visited, false, sizeof(visited));  
    while(!que.empty())  
        que.pop();  
      
    que.push(1);  
    while(!que.empty()) {  
        long long tmp = que.front();  
        que.pop();  
        //int t = tmp % n;  
        //if(!visited[t]) 
       {  
            //visited[t] = true;  
            for(int i = 0; i < 2; i++) {  
                long long next = tmp * 10 + i; 
                int t = next % n;
                if(t == 0)  
                    return next;
                else if(!visited[t])
                {
                    visited[t] = true;
                    que.push(next);  
                }
            }  
        }  
    }  
}  
  
int main()  
{  
    //freopen("data.in", "rb", stdin);  
    int n;  
    while(scanf("%d", &n) && n) {  
        printf("%lld\n", bfs(n));  
    }  
      
    return 0;  
}  