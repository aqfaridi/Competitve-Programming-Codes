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
    int t,n,s,c,rem;
    cin>>t;
    while(t--)
    {
        rem = 0;
        cin>>s>>n>>c;
        rem = s-n;
        if(rem<=0)
        {
            cout<<"YES 0"<<endl;
            continue;
        }
        if(!(rem&1))
        {
            if(2*c >= rem)
                cout<<"YES "<<rem/2<<endl;
            else
                cout<<"NO"<<endl;
        }
        //else
        //if(n+c >= s)
          //  cout<<"YES "<<(s-n+1)/2<<endl;
        else
        {
            if(2*c >= rem)
                cout<<"YES "<<(rem+1)/2<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
