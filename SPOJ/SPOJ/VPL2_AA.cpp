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
    int t;
    double N0,N1,t1,N2;
    double t2;
    int cases=0;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        scanf("%lf %lf %lf %lf",&N0,&N1,&t1,&N2);
        t2 = (1.0 * t1 * log(N2/N0)) / (1.0 * log(N1/N0));
        printf("Scenario #%d: %.2lf\n",cases,t2);
    }
    return 0;
}

