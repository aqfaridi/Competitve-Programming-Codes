#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <queue> 
#include <climits>
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;

#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n) 
    
vector< pii > v;
int main()
{
    ios::sync_with_stdio(false);
    LL t,n,q,x,y,maxx,size;
    bool f;
    cin>>t;
    while(t--)
    {
        v.clear();
        cin>>n>>q;
        maxx = 0;
        rep(i,n){
            cin>>x>>y;
            maxx = max(y,maxx);
            v.pb(mp(x,y));
        }
        
        sort(v.begin(),v.end());
        rep(i,q){
            cin>>x;
            f = true;
            rep(j,n){
                if(v[j].first <= x && x <= v[j].second)
                {    f = false;break;} 
            }
            
            if(f || x > maxx)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0; 
}
