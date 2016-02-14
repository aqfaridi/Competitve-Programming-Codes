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

int main()
{
    ios::sync_with_stdio(false);
    int t;
    LL x;
    double D;
    cin>>t;
    while(t--)
    {
        cin>>x;
        D = sqrt(1+8*(x-1));
        cout<<(int)ceil((D-1.0)/2.0)<<endl;
    }
    return 0;
}
