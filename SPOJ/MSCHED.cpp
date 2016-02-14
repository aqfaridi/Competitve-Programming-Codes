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
template<class T>
class simpleBIT
{
    T *tree;
    int maxVal;
    public:
    simpleBIT(int N)
    {
        tree = new T[N+1];
        memset(tree,0,sizeof(T)*(N+1));
        maxVal = N;
    }
    void update(int idx,T val)
    {
        while(idx <= maxVal)
        {
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }
    
    T query(int idx)
    {
        T sum = 0;
        while(idx > 0)
        {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    
    T readSingle(int idx)
    {
        T sum = tree[idx];
        if(idx > 0)
        {
            int z = idx - (idx & -idx);
            idx--;
            while(idx != z)
            {
                sum -= tree[idx];
                idx -= (idx & -idx);
            }
        }
        return sum;
    }
};
vector< pii > v;
int main()
{
    ios::sync_with_stdio(false);
    int n,milk,deadline;
    int maxx = -1;
    cin>>n;
    rep(i,n)
    {
        cin>>milk>>deadline;
        maxx = max(maxx,deadline);
        v.pb(mp(milk,deadline));
    }
    simpleBIT<LL> B(maxx);
    sort(all(v),greater<pii>());
    LL ans = 0;
    rep(i,n)
    {
       //v[i].first  && v[i].second
       cout<<v[i].first<<"kk"<<endl;
       trace2(B.query(v[i].second),v[i].second);
       if(B.query(v[i].second) < v[i].second)
       {
            B.update(v[i].second,1);
            ans += v[i].first;
       }
    }
    cout<<ans<<endl;


    return 0; 
}
