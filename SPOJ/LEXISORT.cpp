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
    string str;
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<string> v;
        for(int i=0;i<n;i++)
        {
            cin>>str;
            v.push_back(str);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
            cout<<v[i]<<endl;
    }
    return 0;
}


