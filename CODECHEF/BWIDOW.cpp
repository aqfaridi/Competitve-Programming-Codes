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
    int t,n,r,R;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int maxxr = -1,maxxR=-1,idx;
        vector< pii > v;
        for(int i=0;i<n;i++)
        {
            cin>>r>>R;
            if(r>maxxr)
            {
                maxxr = r;
                maxxR = R;
                idx = i;
            }
            v.push_back(make_pair(r,R));
        }
        bool flag = false;
        for(int i=0;i<n;i++)
        {
            if(i==idx)  continue;
            if(v[i].second > maxxr) {flag = true; break;}
        }
    
        if(!flag)
            cout<<idx+1<<endl;
        else
            cout<<-1<<endl;

    }
    return 0;
}
