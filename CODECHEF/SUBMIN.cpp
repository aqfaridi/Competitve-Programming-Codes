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

#define MAX 1000010
#define MOD 1000000007  
int arr[MAX];
int query(int k,int n)
{
    int minn,cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            minn = INT_MAX;
            for(int x=i;x<=j;x++)
                minn = min(minn,arr[x]);
            if(minn == k)
                cnt++;
        }
    }

    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    int t,n,q,k;
    t = 1;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>q;
        for(int i=0;i<q;i++)
        {
            cin>>k;
            cout<<query(k,n)<<endl;
        }
    }
    return 0;
}
