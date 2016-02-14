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
    int t,n,var;
    bool ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans = true;
        for(int i=0;i<n;i++)
        {
            cin>>var;
            if(var>i)
                ans = false;
        }
        if(ans)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
