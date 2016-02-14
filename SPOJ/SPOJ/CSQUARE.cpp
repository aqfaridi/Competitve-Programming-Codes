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
LL expo(LL a,char* b,LL m)
{
    LL result = 1;
    int l = strlen(b);
    for(int i=l-1;i>=0;i--)
    {
        if(b[i]=='1')
            result = (result*a)%m;
        else if(b[i]=='2')
            result = (result*a*a)%m;

        a = (a*a*a)%m;                
    }
    return result;
}
int main()
{
    long long t,a,m;
    char b[1000];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&a);
        scanf("%s",b);
        scanf("%lld",&m);
        a %= m;
        printf("%lld\n",expo(a,b,m));
        
    }
    return 0;
}

