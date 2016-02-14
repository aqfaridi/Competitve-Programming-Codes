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
int main()
{
    ios::sync_with_stdio(false);
    LL g,t,n,x,p,q;
    LL z;
    cin>>t;
    while(t--)
    {
        cin>>p>>q;
        g = __gcd(p,q);
        p/=g;q/=g;
        if(p==1)
        {
            while(q%2==0)q>>=1;
            x=log2(q+1);

            if(((1LL)<<x)==(q+1))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
        {
            x = log2(q+1);
            z = (1LL<<x);
            if(p<=z && ((p&(p-1))==0) and ((q&(q+1)) == 0))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }

    }
    return 0;
}
