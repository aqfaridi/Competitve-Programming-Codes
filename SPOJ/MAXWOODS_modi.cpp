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
int dp[210][210];
int main()
{
    int t,n,m,maxx;
    scanf("%d",&t);
    while(t--)
    {
        maxx = 0;
        memset(dp,0,sizeof dp);
        scanf("%d %d",&m,&n);
        for(int i=0;i<m;i++)
            scanf("%s",(str[i]+1));

        if((m&1))
        {
            dp[m-1][n] = ((str[m-1][n]=='T')?1:0);
            for(int j=n-1;j>=1;j--)
            {
                if(str[m-1][j]!='#')            
                    dp[m-1][j] = dp[m-1][j+1] + ((str[m-1][j]=='T')?1:0);
            }    

            for(int i=m-2;i>=0;i--)
            {
                if((i&1))
                {
                    for(int j=1;j<=n;j++)
                    {                    
                        if(str[i][j] != '#')
                            dp[i][j] = max(dp[i][j-1],dp[i+1][j]) + ((str[i][j]=='T')?1:0);
                    }
                }
                else
                {
                    for(int j=n;j>=1;j--)
                    {                
                        if(str[i][j] != '#')
                            dp[i][j] = max(dp[i+1][j],dp[i][j+1]) + ((str[i][j]=='T')?1:0);
                    }
                }
            }
        }
        else
        {
            
            dp[m-1][1] = ((str[m-1][1]=='T')?1:0);
            for(int j=2;j<=n;j++)
            {
                if(str[m-1][j]!='#')            
                    dp[m-1][j] = dp[m-1][j-1] + ((str[m-1][j]=='T')?1:0);
            }    

            for(int i=m-2;i>=0;i--)
            {
                
                if((i&1))
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(str[i][j] != '#')
                            dp[i][j] = max(dp[i][j-1],dp[i+1][j]) + ((str[i][j]=='T')?1:0);
                    }
                }
                else
                {
                    for(int j=n;j>=1;j--)
                    {
                        if(str[i][j] != '#')
                            dp[i][j] = max(dp[i+1][j],dp[i][j+1]) + ((str[i][j]=='T')?1:0);
                    }
                }
            }
        
        }
/*
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<=n;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
*/        
        printf("%d\n",dp[0][1]);
    }
    return 0;
}



