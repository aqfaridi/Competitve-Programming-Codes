#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <complex>
#include <algorithm>
#define MAX 1010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int f[MAX];
int main()
{
    int a,b,n;

    set<int> myset,test;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        test.insert(a);
        f[a] += 1;
        if(a!=b)
            myset.insert(b);
    }
    int khul = 0;
    while(!myset.empty())
    {
        khul  += f[*myset.begin()];
        myset.erase(myset.begin());
    }

    cout<<n - khul<<endl;
    return 0;
}

