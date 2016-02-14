#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <climits>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define MAX 100020
#define MOD 1000000007    
int arr[MAX],n,k;
LL minvalue = LLONG_MAX;
void find_min(int idx,int street,LL pro)
{
    if(street == arr[n-1])
    {
        minvalue = min(minvalue,pro);
        return;
    }
    LL store = pro;
    for(int i=idx;i<n;i++)
    {
        if((arr[i]-street >=1) && (arr[i]-street <= k))
        {
            pro = (pro*arr[i])%MOD;
            find_min(idx+1,arr[i],pro);
            pro  = store;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    t = 1;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        find_min(1,arr[0],arr[0]);
        cout<<minvalue<<endl;
    }
    return 0;
}
