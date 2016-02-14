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
vector< pii > v;
LL area(int x1,int y1,int x2,int y2,int x3,int y3)
{
    return (x1*(y2-y3) + y1*(x3-x2) + (x2*y3 -x3*y2));
}
int main()
{
    ios::sync_with_stdio(false);
    int t,x,y,n,x1,y2,x2,y1,y3,x3;
    bool flag;
    cin>>t;
    while(t--)
    {
        v.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            if(x==0 && y==0)
                continue;
            v.push_back(make_pair(x,y));
        }
        if(v.size() == 0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        sort(v.begin(),v.end());
        flag = false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int idx = lower_bound(v.begin(),v.end(),make_pair(v[i].first+v[j].first,v[i].second+v[j].second)) - v.begin();
                if(idx != n && i != j && idx != i && idx != j && v[idx].first == v[i].first+v[j].first && v[idx].second == v[i].second +v[j].second)
                {
                    x1 = v[i].first;y1 = v[i].second;
                    x2 = v[j].first;y2 = v[j].second;
                    x3 = v[idx].first;y3 = v[idx].second;
                    if(area(x1,y1,x2,y2,x3,y3) > 0)
                    {
                        flag = true;
                        break;
                    }
                }
            }
            if(flag)
                break;
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
