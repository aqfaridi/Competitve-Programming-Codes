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
    LL t,n,m,o;
    LL pro,sum;
    t = 1;
    while(t--)
    {
        cin>>m>>n>>o;
        pro = m*n*o;
        sum = m+n+o;
        cout<<pro<<" "<<sum<<endl;
    }
    return 0;
}
