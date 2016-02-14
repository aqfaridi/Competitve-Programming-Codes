#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath> 
#include <climits>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define MAX 1000010
#define MOD 1000000007
int arr[MAX],lt[MAX],rt[MAX];
void sliding_window(int n,int k)
{
    for(int i=0;i<n;i++)
    {
        if(i%k == 0)
            lt[i] = arr[i];
        else
            lt[i] = max(arr[i],lt[i-1]);        
    }
    rt[n] = INT_MIN;
    for(int i=n-1;i>=0;i--)
    {
        if(i%k == k-1)
            rt[i] = arr[i];
        else
            rt[i] = max(arr[i],rt[i+1]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t,n,k,l,r;
    t = 1;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        sliding_window(n,k);
        l = 0;r = k-1;
        while(r<n)
        {
            cout<<max(rt[l],lt[r])<<" ";
            l++;r++;
        }
    }
    return 0;
}
