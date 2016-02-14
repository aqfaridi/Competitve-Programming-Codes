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
int a[MAX];
int b[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t ;
    LL n,x,y,sum;
    while(t--)
    {
        sum = 0;
        cin>>n>>x>>y;
        for(int i = 0 ; i < n ; i++)
            cin >> a[i] >> b[i];
        sort(a,a+n);sort(b,b+n);
        for(int i = 0 ; i < n ; i++)
        {
            if(a[i] > b[i])
                sum += y*(a[i]-b[i]);
            else if(a[i] < b[i])
                sum += x*(b[i]-a[i]);
            //cout << sum << endl ;
        }
        cout << sum << endl ;
    }
    return 0;
}
