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

#define MAX 100010
#define MOD 1000000007  
int arr[1010];
int main()
{
    ios::sync_with_stdio(false);
    int t,n;
    LL P;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>P;
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                int idx = lower_bound(arr,arr+n,P-arr[i]-arr[j])-arr;
                if(idx == n)
                    continue;
                if(idx!=i && idx!=j && i!=j && arr[idx] == (P-arr[i]-arr[j]))
                {
                    cout<<"YES"<<endl;
                    goto end;
                }
            }
        cout<<"NO"<<endl;
end: ;
    }
    return 0;
}
