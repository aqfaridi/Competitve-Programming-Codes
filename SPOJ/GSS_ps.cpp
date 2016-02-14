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
int arr[MAX],best[MAX];
void prefix_sum(int n)
{
    best[1] = arr[1];
    for(int i=2;i<=n;i++)
    {
        best[i] = max(arr[i],arr[i]+best[i-1]); 
        cout<<best[i]<<" ";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t,n,q,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        prefix_sum(n);
        cin>>q;
        for(int i=0;i<q;i++)
        {
            cin>>a>>b;
           // cout<<best[b] - best[a-1]<<endl;
        }
    }
    return 0;
}
