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
vector< pii > v;
vector<int> idx;
int stat[MAX];
bool mark[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,m,ci,pi,total,cnt,temp,size;
    cin>>t;
    while(t--)
    {
        total = 0;
        memset(stat,0,sizeof(stat));
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>ci>>pi;
            v.pb(make_pair(ci,pi));
        }
        for(int i=1;i<(1LL<<n);i++)
        {
            cnt = 0;
            idx.clear();
            memset(mark,0,sizeof(mark));
            temp = i;
            //trace1(i);
            for(int j = __lg(temp);temp>0;j=__lg(temp))
            {
                //trace1(j);
                if(mark[v[j].first] == 0)
                {
                    cnt++;                
                    mark[v[j].first] = 1;
                }
                idx.pb(j);
                temp ^= (1LL << j);
            }
            
            if(cnt == m)
            {
                size = idx.size();
                //trace1(size);
                for(int k=0;k<size;k++)
                {
                    //trace2(k,idx[k]);
                    stat[idx[k]]++;
                    cout<<v[idx[k]].first<<" "<<v[idx[k]].second<<" | ";
                }
                cout<<"hell"<<endl;
                total++;
            }
        }
        for(int i=0;i<n;i++)
            cout<<stat[i]<<" ";
        cout<<endl;                

        trace1(total);
    }
    return 0; 
}
