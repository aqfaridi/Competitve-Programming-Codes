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
    double s,v,area_reqd,total,ans;
    cin>>t;
    while(t--)
    {
        cin>>s;
        total = s*s;
        v = s/2.0;
        //area_reqd = (18.0*v*v - v*sqrt(v)*4.0)/3;
        //ans = area_reqd / total;
        ans = 1.0 - 1.0/(3.0*sqrt(v));
        printf("%.6lf\n",ans);
    }
    return 0;
}
