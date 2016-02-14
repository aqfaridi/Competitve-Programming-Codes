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
typedef pair<LL,LL> pii;
long long *tree;
long long MAX;
void update(LL idx,LL val)
{
    while(idx<=MAX)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
LL read(LL idx)
{
    LL sum = 0;
    while(idx>0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

vector< pair<LL,LL> > v;
int main()
{
    ios::sync_with_stdio(false);
    LL t,n,maxx,m,k,a,b,cases=0;
    LL cnt;
    t = 1;
    while(t--)
    {
        cnt = 0;
        cases++;
        v.clear();
        cin>>k;
        for(LL i=0;i<k;i++)
        {
            cin>>a>>b;
            maxx = max(maxx,b);
            v.push_back(make_pair(a,b));
        }

        tree = new long long[maxx+1];
        MAX = maxx;
        memset(tree,0,sizeof(long long)*(maxx+1));
        sort(v.begin(),v.end());
        for(LL i=0;i<v.size();i++)
        {
            //  cout<<v[i].first<<" "<<v[i].second<<endl;
            update(v[i].second,1);
            cnt += read(MAX) - read(v[i].second);
        }
        cout<<cnt<<endl;
        delete[] tree;
    }
    return 0;
}



