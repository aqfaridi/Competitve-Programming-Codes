#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
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

LL x1[10],y1[10],x2[10],y2[10];
int main(){
	ios::sync_with_stdio(false);
    int t,n;
    LL minx , maxx , miny , maxy ;
    cin>>t;
    while(t--)
    {
        cin>>n;
        LL area = 0;
        minx = miny = 1000010;
        maxx = maxy = 0;
        rep(i,n){
            cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
            minx = min(minx,min(x1[i],x2[i]));
            maxx = max(maxx,max(x1[i],x2[i]));
            miny = min(miny,min(y1[i],y2[i]));
            maxy = max(maxy,max(y1[i],y2[i]));          
            area += abs(x1[i] - x2[i]) * abs(y1[i] - y2[i]);
        }
        
        LL l = (maxx - minx);
        LL b = (maxy - miny);
        
        if( l == b && area ==  l*b)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
        
    }
    

	return 0;
}