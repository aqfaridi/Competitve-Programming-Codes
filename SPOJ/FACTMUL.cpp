#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
const long long  MOD = 1LL*186583*587117;
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL fact[10000010],res[10000010];
LL mulmod(LL a,LL b)
{
    LL result = 0;
    while(b)
    {
        if((b&1))
            result = (result + a)%MOD;
        a = (2*a)%MOD;
        b>>=1;
    }
    return result % MOD;
}
void calc()
{
    fact[0] = 1;
    res[0] = 1 ;
    for(int i=1;i<=587117;i++)
    {
        fact[i] = (i%MOD * fact[i-1]%MOD)%MOD;
        res[i] = mulmod(res[i-1],fact[i]);
    }
}
int main()
{
    
    LL n;
    cin>>n;
    if(n>=587117)
        cout<<0<<endl;
    else
    {
        
        fact[0] = 1;
        res[0] = 1 ;
        for(int i=1;i<=n;i++)
        {
            fact[i] = (i%MOD * fact[i-1]%MOD)%MOD;
            res[i] = mulmod(res[i-1],fact[i]);
        }
        cout<<res[n]<<endl;
    }
    return 0;
}


