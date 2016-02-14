#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define MAX 100010
#define MOD 1000000007    
set<int> hr,v;
int main()
{
    ios::sync_with_stdio(false);
    int t,n,x,y;
    t = 1;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            hr.insert(x);
            v.insert(y);
        }
        cout<<min(hr.size(),v.size())<<endl;
    }
    return 0;
}
