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

#define MAX 1010
#define MOD 1000000007    
int a[MAX],b[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        for(int i=0;i<n;i++)
            cin>>b[i];
        sort(b,b+n);
        reverse(b,b+n);
        int i;
        for(i=0;i<n;i++)
        {
            if(a[i] + b[i] < k)
                break;
        }

        if(i==n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
