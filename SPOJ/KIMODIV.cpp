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
    int t;
    LL n,sqr;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sqr = (int)sqrt(n);
        if(sqr*sqr == n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
