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
LL chor[110];
LL n,k;
LL binary(LL mid)
{
    //sum upto mid(x) no of terms
    LL sum = (mid*k + mid*mid*k*k)/2LL;
    return sum;
}
int main()
{
    int t;
    LL x,sum,rem_coins;
    scanf("%d",&t);
    while(t--)
    {
        sum = 0;
        memset(chor,0,sizeof(chor));
        scanf("%lld %lld",&n,&k);
        //cout<<n<<" "<<k<<endl;
        LL mid=0,low = 0,high = sqrt(n);
        LL mid_khogaya = 0;
        while(low <= high)
        {
            mid = (low+high)/2;
            if(binary(mid) == n)
            {
                mid_khogaya = mid;
                break;
            }
            if(binary(mid) < n)
            {
                mid_khogaya = mid;
                low = mid + 1; 
            }
            else
                high = mid - 1;
        }
        x = mid_khogaya;

        //cout<<x<<endl;
        for(int i=1;i<=k;i++)
        {   
            chor[i] = x*(2*i + (x-1)*k)/2.0; 
            sum += chor[i];
            //cout<<chor[i]<<" ";
        }
        //cout<<endl;
        rem_coins = n - sum;
        int i=1;
        
        while(rem_coins>0)
        {
            if(rem_coins - (x*k+i) > 0)
                chor[i] += x*k + i;
            else
                chor[i] += rem_coins;            
            rem_coins -= (x*k +i);
            i++;
        }
        for(int j=1;j<=k;j++)
            printf("%lld ",chor[j]);
        printf("\n");
    }
    return 0;
}

