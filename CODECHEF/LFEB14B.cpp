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

#define MAX 100020
#define MOD 1000000007    
LL expo(LL a,LL n)
{
    LL result = 1;
    while(n)
    {
        if(n&1)
            result = (result*a)%MOD;
        a = (a*a)%MOD;
        n >>= 1;
    }
    return (result % MOD);
}
int arr[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,maxx,cnt;
    cin>>t;
    while(t--)
    {
        cin>>n;
        maxx = -1;
        cnt = 0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i] > maxx)
                maxx = arr[i];
        }
        for(int i=0;i<n;i++)
            if(arr[i] == maxx)
                cnt++;
        
        cout<<(expo(2,cnt) -1 + MOD)%MOD<<endl;
    }
    return 0;
}
