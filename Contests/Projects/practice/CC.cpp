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
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define pb push_back
#define fr first
#define sc second
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

vector<piii> vv;
vector<piii> vh;
int main()
{
    ios::sync_with_stdio(false);
    int t,n;
    ll ll,uu,d,xx,yy,x,y;
    char ch;
    cin>>n;
    x=0; y = 0;
    rep(i,n){
        cin>>ch>>d;
        if(ch == 'R'){
            yy = y;
            ll = x+1;
            uu = x+d;
            vh.pb(mp(yy,mp(ll,uu)));
        }
        else if(ch == 'L'){
            yy = y;
            uu = x-1;
            ll = x-d;
            vh.pb(mp(yy,mp(ll,uu)));
        }
        else if(ch == 'U'){
            xx = x;
            ll = y+1;
            uu = y+d;
            vv.pb(mp(xx,mp(ll,uu)));
        }
        else{
            xx = x;
            ll = y-d;
            uu = y-1;
            vv.pb(mp(xx,mp(ll,uu)));
        }
    }
        rep(i,vv.sz){
            cout <<vv[i].sc.fr<< " " <<vv[i].sc.sc<<endl;
        }
        cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
        rep(i,vh.sz){
            cout<<vh[i].sc.fr<< " " <<vh[i].sc.sc<<endl;
        }

    return 0; 
}

