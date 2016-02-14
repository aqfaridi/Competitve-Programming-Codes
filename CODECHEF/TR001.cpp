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
    unsigned long long ans,t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n > m)
            swap(n,m);
        cout<<m/2<<endl;
    }
    return 0;
}
