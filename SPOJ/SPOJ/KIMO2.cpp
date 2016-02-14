#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MOD 1000000007
using namespace std;
long long expo(long long a,long long n)
{
    long long result = 1;
    while(n>0)
    {
        if((n&1))
            result = (result * a)%MOD;
        a = (a*a) %MOD;
        n >>= 1;
    }
    return result %MOD;
}
int main()
{
    int t,n;
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<(n*expo(2,n-1))%MOD<<endl;
    }
    return 0;
}

