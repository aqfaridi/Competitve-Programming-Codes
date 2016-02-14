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
typedef pair< int, pii > tri;

typedef vector<int> array;
typedef vector<LL> array_LL;
typedef vector<vector<int> > matrix;
typedef vector<vector<LL> > matrix_LL;


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

#define endl '\n'
#define MAX 100010
#define MOD 1000000007
map<string,string> m;
int mark[1010];
vector< pair<string,string> > v,in;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n;
    string s1,s2;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s1>>s2;
        in.pb(mp(s1,s2));
        m[s1] = s2;
    }
    for(int i=0;i<n;i++){
        if(!mark[i]){
            s1 = in[i].first;
            s2 = in[i].second;
            mark[i] = 1;            
            while(m[s2].length() != 0){
                for(int j=0;j<n;j++)
                    if(!mark[j] && in[j].first == s2){
                        mark[j] = 1;
                        break;
                    }
                s2 = m[s2];                
            }
            v.pb(mp(s1,s2));
        }
    }
    int size = v.size();
    sort(v.begin(),v.end());
    cout<<size<<endl;
    for(int i=0;i<size;i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;
    return 0; 
}

