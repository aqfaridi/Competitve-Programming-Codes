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

#define MAX 110
#define MOD 1000000007
int n,m;
set<int> c;
set<int>::iterator it;
vector<int> v[MAX];
vector<int> repeat;
int total[MAX];
int cnt[MAX][MAX];
int arr[MAX][MAX];
LL nCr[MAX][MAX];
void comb()
{
    for(LL n=0;n<64;n++)
    {
        nCr[n][0] = 1;
        for(LL r = 1;r<=n;r++)
            nCr[n][r] = (nCr[n][r-1]*(n-r+1))/r;
    }
}

void build_matrix()
{
    memset(arr,0,sizeof arr);
    repeat.clear();
    int distinct = 0;
    it = c.begin();
    for(int k = 1;it != c.end();it++)
    {
        if(v[(*it)].size() == 1)
            distinct++;
        else 
            repeat.pb((*it));
    }

    int r_sz = repeat.size(),temp,counter;
    LL pro;
    bool f;
    for(int k=0;k<r_sz;k++)
    {
        for(int i=0;i<(1LL<<r_sz);i++)
        {
            f = true;
            counter = 0;
            pro = 1;
            temp = i;
            for(int j=__lg(temp);j>0;j=__lg(temp))
            {
                if(j==k)    
                {
                    f = false;
                    break;
                }
                pro *= (1LL << (v[repeat[j]].size() -1));
                counter++;
                temp ^= (1LL<<j);
            }

            if(f)
                arr[k][counter] += pro;

        }
    }
    int l,r;       
    for(int i=0;i<=n;i++)
    {                     
        for(int j=0;j<n;j++)
        {
            for(l=0,r=i-1;l<=(i-1);l++,r--)
            {
        //        nCr[distinct][r]
               if(distinct >= r)
               {
                   //trace2(i,j);
                   //trace2(l,r);
                   //trace1(v[i][j]);
                   cnt[i][j] += (1LL<< (v[i].size()-1)) * arr[i][l]  * nCr[distinct][r]; 
                   //trace2(arr[i][l],nCr[distinct][r]);
               }
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<cnt[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    comb();
    ios::sync_with_stdio(false);
    int t,ci,pi;
    cin>>t;
    while(t--)
    {
        c.clear();
        cin>>n>>m;
        for(int i=0;i<=n;i++)
            v[i].clear();
        rep(i,n) 
        {
            cin>>ci>>pi;
            c.insert(ci);
            v[ci].pb(pi);
        }
        build_matrix();
    }
    return 0; 
}
