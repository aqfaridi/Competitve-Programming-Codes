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
int arr[MAX];
int main()
{
    int t,n;
    string str;
    LL sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            cin>>str>>arr[i];
        }
        sort(arr,arr+n);
        sum = 0;
        for(int i=0;i<n;i++)
            sum += abs(arr[i]-(i+1));

        printf("%lld\n",sum);
    }
    return 0;
}

