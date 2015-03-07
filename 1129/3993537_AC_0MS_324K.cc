#include<stdio.h>
#include<stdlib.h>
#include<string>
#define MAX 50
bool found; 
int map[MAX][MAX],n,m,col[MAX]; 

bool check(int d, int color) 
{ 
int i;

  for(i=1; i<=n; i++) 
    if(map[i][d]==1  &&  color==col[i] && i!=d)   //与涂有颜色i的有边相连 
      return false; 
  return true; 
}

bool DFS(int d) 
{
int i;  

  if(d>n) 
    return true;           //直接return给主函数可输出结果 
  for(i=1; i<=n; i++) 
  {  
    if(check(d,i))         //能用i颜色涂结点d 
    { 
      col[d]=i;          
      if(DFS(d+1))         //像下进行 
        return true; 
    }
  }   
  return false;           //如果10种颜色都涂还不够就return false
}


int main()
{
	//freopen("c:/acm/pku_1129.txt","r",stdin);
int i,j,k,l,max=0;
char a[100];
                           //N为图拥有的结点数    M为染色数  
  
  scanf("%d",&n);
    
  while(n!=0)
  {
    max=0;
    memset(a,'0',sizeof(a));
    for(i=1;i<=MAX-1;i++)
      for(j=1;j<=MAX-1;j++)
        map[i][j]=0;    
            
    for(i=1;i<=n;i++)
    {
      scanf("%s",a);
      j=2;
      while(a[j]!='\0') 
      {
        map[i][a[j]-'A'+1]=1;
        j++;
      }
    }
    
    for(i=1;i<=MAX-1;i++)
      col[i]=0;
     
    if(DFS(1))
    {
      for(i = 1; i <= n; i++)
      {
        if(col[i]>max) max=col[i];
      } 

    }
   
        
    if(max==1)
      printf("1 channel needed.\n");
    else
      printf("%d channels needed.\n",max); 
      
  
                 
      
  scanf("%d",&n);           
  } 

return 0;        
      
}

