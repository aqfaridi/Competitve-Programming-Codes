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
int wt[40],cost[40],ans,n;
void knapsack(int i,int k,int total)
{
    if(i==n+1 || k<=0)
    {
        ans = max(ans,total);
        return;
    }
    
    if(k>=cost[i]) 
        knapsack(i+1,k-cost[i],total+wt[i]);
    
    knapsack(i+1,k,total);
}
int main()
{
    ios::sync_with_stdio(false);
    int t,k;
    cin>>t;
    while(t--)
    {
        ans = 0;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>cost[i]>>wt[i];
        knapsack(1,k,0); 
        cout<<ans<<endl;
    }
    return 0;
}
