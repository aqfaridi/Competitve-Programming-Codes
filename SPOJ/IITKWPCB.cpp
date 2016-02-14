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
LL gcd(LL a,LL b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    LL n,N;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        N = n;
        n = n/2;
        while(n)
        {
            if(gcd(n,N)==1)
            {
                cout<<n<<endl;
                break;
            }
            n--;
        }
    }
    return 0;
}


