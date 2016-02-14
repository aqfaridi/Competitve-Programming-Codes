#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL arr[100010];
int main()
{
    ios::sync_with_stdio(false);
    int m,n,var;
    LL rem = 0,sum = 0,ans = 0,gap;
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum += arr[i];
    }
    rem = sum - m;

    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        gap = min(arr[i], rem/(n-i));
        rem -= gap;
        ans += (gap*gap);
    }

    cout<<ans<<endl;
    return 0;
}
