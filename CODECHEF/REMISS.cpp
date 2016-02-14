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
    int t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<max(a,b)<<" "<<a+b<<endl;
    }
    return 0;
}
