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
set<int> s;
set<int>::iterator it;
int a[1010],b[1010];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,k,p,x,y,cut;
    bool f;
    cin>>t;
    while(t--)
    {
        f = true;
        s.clear();
        cin>>n>>k>>p;
        rep(i,k)
            cin>>a[i]>>b[i];
         
        rep(i,p)
        {
            cin>>x>>y;
            s.insert((x-1)%n);
            s.insert(y%n);
        }
        rep(i,k)
        {
            x = a[i];y = b[i];
            x = (x-1)%n;
            y = y%n;
            it = s.begin();
            for(;it != s.end(); it++)
            {
                cut = (*it);
                if(x<y)
                {
                    if(cut > x && cut < y) { f = false; break; }
                }
                else
                {
                    if(cut > x || cut < y) { f = false; break; }
                }
            }
            if(!f)
                break;
            s.insert(x);s.insert(y);
        }
        if(f)
            cout<<"Yes"<<endl;
        else 
            cout<<"No"<<endl;
        
    }
    return 0; 
}
