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
    long long n,k;
    cin>>n>>k;
    long long last,even,odd;
    even = n/2;
    odd = n - even; // position
    //last odd number
    last = (2*odd - 1);
    if(k <= odd)
        cout<<2*k - 1<<endl;
    else
    {
        cout<<2*(k-odd)<<endl;
    }
    return 0;
}

