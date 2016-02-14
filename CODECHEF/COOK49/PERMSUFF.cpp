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
typedef pair<int,pair<int,int> > tri;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector< pii > vpii;
#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define fore(i,a,b)                 for(int i=a;i<=b;i++)
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

ostream& operator<<(ostream& out,vi& v)
{
    for(int x=0;x<v.size();x++)
        out << v[x];
    out << endl;
    return out;
}
ostream& operator<<(ostream& out,vvi& v)
{
    int n = v.size();
    int m = v[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            out<<v[i][j]<<" ";
        out<<endl;
    }
    return out;
}

void print_arr(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void print_arr2d(int arr2[][20],int n,int m)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<arr2[i][j]<<" ";
        cout<<endl;
    }
}

void print_vi(vi& v,int n)
{
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

void print_vii(vvi& v,int n,int m)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<v[i][j]<<" ";
        cout<<endl; 
    }
}

string end = "============******=============\n";

#define MAX 100020
#define MOD 1000000007
vi inner(MAX,0);
//vvi a(MAX,inner);
//vvi cumm(MAX,inner);
//vvi cummb(MAX,inner);
int P[MAX];
vector< pii > v,q;
int mark[MAX];
LL expo(LL a,LL n)
{
    LL result = 1;
    while(n)
    {
        if((n&1))
            result *= a;
        a *= a;
        n >>= 1;
    }
    return result;
}

LL mod_expo(LL a,LL n,LL m)
{
    LL result = 1;
    while(n)
    {
        if((n&1))
            result = (result*a)%m;
        a = (a*a)%m;
        n >>= 1;
    }
    return result%m;
}
vpii merge_interval(vpii& v)
{
    vpii q;
    sort(all(v));
    int size = v.size();
    int l = v[0].first;
    int r = v[0].second;
    for(int i=1;i<size;i++)
    {
        if(v[i].first <= r)
            r = max(r,v[i].second);
        else
        {
            q.pb(mp(l,r));
            //cout<<l<<" "<<r<<endl;
            l = v[i].first;
            r = v[i].second;
        }            
    }
    
    q.pb(mp(l,r));

    return q;
}
int main()
{
    ios::sync_with_stdio(false);
    int t,n,m,r,l;
    cin>>t;
    while(t--)
    {
        v.clear();q.clear();
        memset(mark,0,sizeof(mark));
        cin>>n>>m;
        fore(i,1,n)    cin>>P[i];
        rep(i,m){
            cin>>l>>r;
            v.pb(mp(l,r));
        }

        q = merge_interval(v);
        
        int size = q.size();
        bool ans = true;
        for(int i=0;i<size;i++)
        {
            l = q[i].first;
            r = q[i].second;
            //trace2(l,r);
            for(int z=l;z<=r;z++)
            {
                if(P[z] < l || P[z] > r)
                    ans = false; 
                mark[z] = 1;
            }
        }


        for(int i=1;i<=n;i++)
            if(!mark[i] && P[i] != i)
                ans = false;


        if(ans)
            cout<<"Possible"<<endl;
        else
            cout<<"Impossible"<<endl;
    }
    
    return 0; 
}


