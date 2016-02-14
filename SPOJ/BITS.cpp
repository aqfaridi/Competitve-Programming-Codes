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

#define MAX 100010
#define MOD 1000000007    
LL bitsum(LL n)
{
    LL total = 0;
    for(int i = __lg(n);i>=0;i--)
    {
        if(n & (1LL << i))
        {
            total += (i*(1LL<<(i-1)) + (n-(1LL<<i)+1));
            n ^= (1LL<<i);//reset ith bit
        }
    }
    return total;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    LL n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<bitsum(n)<<endl;
    }
    return 0;
}
