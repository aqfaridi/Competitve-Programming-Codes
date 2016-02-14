#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;
typedef unsigned long long LL;
typedef pair<int,int> pii;

#define MAX 100010
#define MOD 1000000007    
int main()
{
    ios::sync_with_stdio(false);
    int t;
    LL ans,n;
    long double N;
    cin>>t;
    while(t--)
    {
        cin>>n;
        N = n;
        if((n&1))
            ans = (LL)roundl((1.0*(N+3)*(N+3))/48.0);
        else
            ans = (LL)roundl((1.0*N*N)/48.0);

        cout<<ans<<endl;    
    }
    return 0;
}
