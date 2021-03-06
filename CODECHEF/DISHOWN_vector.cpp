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

#define MAX 10010
#define MOD 1000000007
int S[MAX],own[MAX];
vector<int> dish[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,q,x,y,c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>S[i];
            own[i] = i;
            dish[i].clear();
            dish[i].pb(i);
        }
        cin>>q;
        rep(i,q)
        {
            cin>>c;
            if(c == 0)
            {
                cin>>x>>y;
                int ownx = own[x];
                int owny = own[y];
                if(ownx == owny)
                {
                    cout<<"Invalid query!"<<endl;
                    continue;
                }
                if(S[ownx] > S[owny])
                {
                    //y loose
                    int size = dish[owny].size(),child;
                    for(int i=0;i<size;i++)
                    {
                        child = dish[owny][i];
                        own[child] = ownx;
                        dish[ownx].pb(child);
                    }
                    dish[owny].clear();                    
                }

                else if(S[ownx] < S[owny])
                {
                    //x loose
                    int size = dish[ownx].size(),child;
                    for(int i=0;i<size;i++)
                    {
                        child = dish[ownx][i];
                        own[child] = owny;
                        dish[owny].pb(child);
                    }
                    dish[ownx].clear();     
                }
            }
            else
            {
                cin>>x;
                cout<<own[x]<<endl;
            }
        }
    }
    return 0; 
}
