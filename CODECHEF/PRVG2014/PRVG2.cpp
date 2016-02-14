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
typedef pair<int,pii> tri;
#define MAX 1500010
vector<tri> v;
int main()
{
    int t,n,a,b;    
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            diff = (b-a);
            v.push_back(make_pair(diff,make_pair(a,b)));
        }
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--)
        {
            sum += v.first;
        }
    }
    return 0;
}
