#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;
typedef unsigned long long LL;
typedef pair<int,int> pii;

#define MAX 100010
#define MOD 1000000007    
int main()
{
    //ios::sync_with_stdio(false);
    LL n,ans;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu",&n);
        if(n%3 == 0)
            ans = (n/3 + 1);
        else
            ans = 1;
        printf("%llu\n",ans-1);
    }
    return 0;
}
