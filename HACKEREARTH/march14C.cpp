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
int x[MAX] , y[MAX];
int fun(int i , int n)
{
    int v1 = abs(n-x[i]) + abs(n-y[i]); 
    int v2 = abs(1-x[i]) + abs(1-y[i]);
    int v3 = abs(1-x[i]) + abs(n-y[i]);
    int v4 = abs(n-x[i]) + abs(1-y[i]);
    return min(min(v1,v2),min(v3,v4));
}
int main()
{
    ios::sync_with_stdio(false);
    int t,n,k;
    t = 1;
    while(t--)
    {
        cin>>n>>k;
        LL ans = 0 ;
        for(int i = 0; i<k ; i++)
            cin >> x[i];
       for(int i = 0 ; i<k ;i++)
            cin >> y[i];
       for(int i = 0 ; i < k ;i++)
       {
           ans += fun(i,n)*1LL;
       }
        cout << ans << endl ;
    }
    return 0;
}
