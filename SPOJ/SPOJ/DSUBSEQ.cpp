#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 100010
#define MOD 1000000007
using namespace std;
int dp[MAX],pos[26];
char str[MAX];
void compute(int l)
{
    dp[0] = 1; //empty set({})
    dp[1] = 2; // two set formed by 1 char ({},{1})
    pos[str[1]-'A'] = 1;
    for(int i=2;i<=l;i++)
    {
        dp[i] = (2*dp[i-1])%MOD;
        if(pos[str[i]-'A'] != 0)
            dp[i] = (dp[i]%MOD- dp[pos[str[i]-'A']-1]%MOD + MOD)%MOD;
        pos[str[i]-'A'] = i;
    }
    /**
    for(int i=0;i<26;i++)
        cout<<pos[i]<<" ";
    cout<<endl;
    for(int i=0;i<26;i++)
        cout<<dp[i]<<" ";
        **/
}
int main()
{
    int t,l;
    scanf("%d",&t);
    while(t--)
    {
        memset(pos,0,sizeof(pos));
        scanf("%s",str+1);
        l = strlen(str+1);
        compute(l);
        cout<<dp[l]<<endl;
    }
    return 0;
}

