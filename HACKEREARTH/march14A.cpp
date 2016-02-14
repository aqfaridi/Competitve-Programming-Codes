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
int main()
{
    ios::sync_with_stdio(false);
    int t;
    LL n,l,b;
    cin>>t;
    while(t--)
    {
        cin>>n;
        l = n/4;
        b = (n - 2*l)/2;
        cout<<l*b<<endl;
    }
    return 0;
}
