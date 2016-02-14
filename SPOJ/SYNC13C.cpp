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
    int t,n,c1,c2;
    cin>>t;
    while(t--)
    {
        cin>>c1>>c2;   
        if((c1&1) && (c2&1))
            cout<<"Ramesh"<<endl;
        else
            cout<<"Suresh"<<endl;

    }
    return 0;
}
