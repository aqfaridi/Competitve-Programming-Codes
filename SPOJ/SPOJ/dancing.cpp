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
int main()
{
    int t,n,m,k;
    //scanf("%d",&t);
    t = 1;
    while(t--)
    {
        scanf("%d %d",&n,&m);
        k = m + (n-1);
        cout<<k<<endl;
        for(int i=1;i<=m;i++)
            cout<<1<<" "<<i<<endl;
        if(n<=m)
        {
            for(int i=2;i<=n;i++)
                cout<<i<<" "<<i<<endl;
        }
        else
        {
            for(int i=2;i<=n;i++)
                cout<<i<<" "<<1<<endl;
        }

    }
    return 0;
}

