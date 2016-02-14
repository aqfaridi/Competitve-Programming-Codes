#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

char str[210][210];
int dp[210][210],m,n;
//flag = 1:right and 0:left
int path(int i,int j,int flag)
{
    if(dp[i][j])    return dp[i][j];
    else if( (str[i][j]=='#') || (i<0 || i>(m-1)) || (j<0 || j>(n-1))  )  return 0;
    
    if(flag)
        return dp[i][j] = max(path(i+1,j,0),path(i,j+1,1)) + ((str[i][j]=='T')?1:0);   
    else
        return dp[i][j] = max(path(i+1,j,1),path(i,j-1,0)) + ((str[i][j]=='T')?1:0);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof dp);
        scanf("%d %d",&m,&n);
        for(int i=0;i<m;i++)
            scanf("%s",str[i]);        
                
        printf("%d\n",path(0,0,1));
    }
    return 0;
}



