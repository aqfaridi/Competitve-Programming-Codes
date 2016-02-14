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
        memset(dp,-1,sizeof dp);
        scanf("%d %d",&m,&n);
        for(int i=0;i<m;i++)
            scanf("%s",str[i]);
        
        if(str[0][0]=='T')
        {
            dp[0][0] = 1;
            maxx = 1;
        }
        else if(str[0][0]=='0')
            dp[0][0] = 0;

        for(int i=1;i<n;i++)
        {
            if(str[0][i]=='T')
                dp[0][i] = dp[0][i-1] + 1;
            else if(str[0][i]=='0')
                dp[0][i] = dp[0][i-1];
            else 
                break;

            if(dp[0][i]>maxx)
                maxx = dp[0][i];
        }
        
        for(int i=1;i<m;i++)
        {
            if((i&1))
            {
                for(int j=n-1;j>=0;j--)
                {         
                    if(dp[i-1][j] == -1 && dp[i][j+1] == -1)
                        dp[i][j] = -1;

                    else if(str[i][j]=='T')
                        dp[i][j] = max(dp[i-1][j],dp[i][j+1])+1;
                    else if(str[i][j]=='0')
                        dp[i][j] = max(dp[i-1][j],dp[i][j+1]);
         


                    if(dp[i][j] > maxx)
                        maxx = dp[i][j];
                }
            }
            else
            {
                for(int j=0;j<n;j++)
                {
                    
                    if((j-1)>=0 && dp[i-1][j] == -1 && dp[i][j-1] == -1)
                        dp[i][j] = -1;

                    else if(str[i][j]=='T')
                        dp[i][j] = (j-1>=0)?(max(dp[i-1][j],dp[i][j-1])+1) : (dp[i-1][j]+1);
                    else if(str[i][j]=='0')
                        dp[i][j] = (j-1>=0)?(max(dp[i-1][j],dp[i][j-1])): (dp[i-1][j]);
                
              
                    if(dp[i][j] > maxx)
                        maxx = dp[i][j];
                }
            }
            
        }
        /*
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        */
        cout<<maxx<<endl;
    }
    return 0;
}


