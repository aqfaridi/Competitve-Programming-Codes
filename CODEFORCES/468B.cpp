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
#include <bitset> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n) 
#define all(v)                      v.begin(),v.end()    
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define clr(a)                      memset(a,0,sizeof a)
    
#define debug                       if(1)
#define debugoff                    if(0)    

#define print(x)                 cerr << x << " ";    
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define MAX 100010
#define MOD 1000000007
bitset<2200> b1,b2,bit;
vector<pii> z,x;
int main()
{
    ios::sync_with_stdio(false);
    int p,q,l,r,a,b,c,d;
    cin>>p>>q>>l>>r;
    rep(i,p){
        cin>>a>>b;
        for(int i=a;i<=b;i++)
            b1.set(i);
        z.pb(mp(a,b));
    }
    rep(i,q){
        cin>>c>>d;
        c += l ; d += l;
        for(int i=c;i<=d;i++)
            b2.set(i);
        x.pb(mp(c,d));
    }
    
    for(int i=0;i<=2100;i++)
        if(b1.test(i) && b2.test(i))
            bit.set(i);
    
    int cnt = 0;
    if(bit.any()) cnt+=1;
    for(int shift=0;shift<(r-l);shift++)
    {
        for(int i = 0;i<q;i++)
        {
            c = x[i].first; d = x[i].second;
            b2.reset(c+shift);b2.set(d+shift+1);
        }
        bit.reset();
        for(int i=0;i<=2100;i++)
            if(b1.test(i) && b2.test(i))
                bit.set(i);

        if(bit.any())
            cnt++;
    }

    cout<<cnt<<endl;

    return 0; 
}

