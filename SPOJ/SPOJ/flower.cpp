#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <complex>
#include <numeric>
#include <functional>
#include <sstream>
#include <algorithm>
#define MAX 1000010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
LL gcd(LL a,LL b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    LL t,r,g,b,flower,flo,rr,gg,bb;
    int GCD;
    //scanf("%d",&t);
    t = 1;
    while(t--)
    {
        //scanf("%d %d %d",&r,&g,&b);
        cin>>r>>g>>b;
        rr = r;
        gg = g;
        bb = b;
        GCD = gcd(gcd(r,g),b);
        flower = GCD;
        r -= GCD;
        g -= GCD;
        b -= GCD;
        flower += (r/3 + g/3 + b/3);
        flower += min(min(r%3 , g%3),b%3);


        flo = (rr/3 + gg/3 + bb/3);
        flo += min(min(rr%3,gg%3),bb%3); 
        //cout<<flo<<endl;
        cout<<max(flo,flower)<<endl;
    }
    return 0;
}

