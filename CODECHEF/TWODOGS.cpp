#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <climits>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define MAX 1000010
#define MOD 1000000007  
vector< pii > v;
bool cmp(pii a,pii b)
{
    return (a.first < b.first);
}
int maxx,minn;
void check(int idx1,int idx2,int n)
{
    if(idx1 <= n/2 && idx2 > n/2)
    {
        maxx = max(idx1 , n+1-idx2);
        minn = min(minn,maxx);
    }
    else if(idx1 <= n/2 && idx2 <= n/2)
    {            
        maxx = max(idx1 , idx2);
        minn = min(minn,maxx);          
    }
    else if(idx1 >= n/2 && idx2 >= n/2)
    {            
        maxx = max(n+1-idx1 ,n+1-idx2);
        minn = min(minn,maxx);            
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t,n,k,var,idx,idx1,idx2;
    t = 1;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>var;
            v.push_back(make_pair(var,i));
        }    
        sort(v.begin(),v.end());
        minn = INT_MAX;
        for(int i=0;i<n;i++)
        {
            idx = lower_bound(v.begin()+i,v.end(),make_pair(k-(v[i].first),0),cmp) - v.begin();
            if(idx==n || v[idx].second == v[i].second || (k-v[i].first != v[idx].first))
                continue;
           
            //cout<<"1:"<<v[i].first<<" "<<v[idx].first<<endl;
            idx1 = v[i].second + 1;
            idx2 = v[idx].second + 1;
            if(idx1 > idx2)
                swap(idx1,idx2);
            check(idx1,idx2,n);
            idx = upper_bound(v.begin()+i,v.end(),make_pair(k-(v[i].first),0),cmp) - v.begin();
            idx -= 1;
            if(v[idx].second == v[i].second || (k-v[i].first != v[idx].first))
                continue;

            //cout<<"2:"<<v[i].first<<" "<<v[idx].first<<endl;
            idx1 = v[i].second + 1;
            idx2 = v[idx].second + 1;

            if(idx2 > idx1)
                swap(idx1,idx2);
            check(idx1,idx2,n);
        }
        if(minn != INT_MAX)
            cout<<minn<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
