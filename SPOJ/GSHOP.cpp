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
int arr[110];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,k;
    LL sum;
    cin>>t;
    while(t--)
    {
        sum = 0;
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        for(int i=0;i<k;i++)
        {
            sort(arr,arr+n);
            arr[0] = -arr[0];
        }

        for(int i=0;i<n;i++)
            sum += arr[i];
        
        cout<<sum<<endl;
    }
    return 0;
}
