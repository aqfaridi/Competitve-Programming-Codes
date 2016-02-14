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
set< pii > dish[MAX];
set< pii >::iterator it1,it2;
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
            dish[i].insert(mp(S[i],i));
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
                it1 = dish[ownx].end();it1--;
                it2 = dish[owny].end();it2--;
                if((*it1).first > (*it2).first)
                {
                    set< pii >::iterator it = dish[owny].begin();
                    for(; it != dish[owny].end() ; it++)
                    {
                        own[(*it).second] = ownx;
                        dish[ownx].insert(mp((*it).first,(*it).second));
                    }
                    dish[owny].clear();                    
                }

                else if((*it1).first < (*it2).first)
                {
                    set< pii >::iterator it = dish[ownx].begin();
                    for(; it != dish[ownx].end() ; it++)
                    {
                        own[(*it).second] = owny;
                        dish[owny].insert(mp((*it).first,(*it).second));
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
