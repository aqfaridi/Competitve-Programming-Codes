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

#define MAX 100010
#define MOD 1000000007    
int arr[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,idx;
    LL minn,total;
    cin>>t;
    while(t--)
    {
        cin>>n;
        total = idx = 0;
        minn = INT_MAX;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i] < minn)
            {
                minn = arr[i];
                idx = i;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i == idx)
                continue;
            total += (arr[i]*minn);
        }
        cout<<total<<endl;
    }
    return 0;
}
