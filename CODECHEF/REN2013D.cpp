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
int arr[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,cnt,var;
    LL sum = 0;
    cin>>t;
    while(t--)
    {
        sum = 0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>arr[i];

        if(n==1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        sort(arr+1,arr+n+1);
        int i;
        for(i=1;i<=n;i++)
        {
            if((sum+1) >= arr[i])
                sum += arr[i];
            else
                break;
        }
        if(i!=n+1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;

    }
    return 0;
}
