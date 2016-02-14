#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#define MAX 1000010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int main()
{
    long long a,b;
    long long sum;
   // while(scanf("%lld %lld",&a,&b)!=EOF)
    //{
        for(long long x = 1;x<=128;x++)
        {
            sum = 0;
            printf("%lld ",(x & -x));

            for(long long i=1;i<=x;i++)
                sum += (i & -i);
            
            printf("%lld\n",sum);
        }
    //}
    return 0;
}

