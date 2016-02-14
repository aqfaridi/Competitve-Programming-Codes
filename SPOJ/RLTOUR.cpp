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
int arr[520],q[520],visited[520],ans[520];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,cnt;
    cin>>t;
    while(t--)
    {
        memset(visited,0,sizeof(visited));
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
            cin>>q[i];

        for(int i=n-1;i>=0;i--)
        {
            cnt = 0;
            for(int j=n-1;j>=0;j--)
            {
               if(visited[j])
                   continue;
               if(cnt == q[i])
               {
                    ans[i] = arr[j];
                    visited[j] = 1;
                    break;
               }
               if(!visited[j])
                   cnt++;
            }
        }
        cout<<ans[0]; 
        for(int i=1;i<n;i++)
            cout<<" "<<ans[i];
        cout<<endl;

    }
    return 0;
}
