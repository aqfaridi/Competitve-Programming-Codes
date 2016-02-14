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
int candy[50010],n;
LL binary(LL mid)
{
    LL sum = 0LL;
    for(int i=0;i<n;i++)
        sum += (LL)floor(candy[i]/mid);
    //cout<<mid<<" "<<sum<<endl; 
    return sum ;
}
int main()
{
    int t,f;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&f);
        for(int i=0;i<n;i++)
            scanf("%d",&candy[i]);
        //assuming no of candy per frnd by "mid"
        LL mid,low = 0,high = 1000000000;
        LL noc = 0;
        while(low <= high)
        {
            mid = (low + high)/2;
            if(mid == 0)
                break;
            if(binary(mid) >= f)
            {
                //condition satisfied : goto right
                //cout<<mid<<endl;
                noc = max(noc,mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        LL ssum = 0LL;
        if(noc == 0)
        {
            for(int i=0;i<n;i++)
                ssum += (candy[i]);
            if(ssum >= f)
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
        else
            cout << noc << endl;
        
    }
   
    return 0;
}

