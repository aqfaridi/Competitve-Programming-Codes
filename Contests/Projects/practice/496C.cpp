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
#define MAX 1010
#define MOD 1000000007
char a[MAX][MAX];
int mrk[MAX];
vector<int> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++)
            cin>>a[i];
    
    int cnt =0 ;
    for(int j=0;j<m;j++){
        bool b = false;
        v.clear();
        for(int i=0;i<n-1;i++){
            if(mrk[i] == 1)continue;
             if(a[i][j] < a[i+1][j]){
                 mrk[i]=1;
                 v.pb(i);
             }
             if(a[i][j]>a[i+1][j]){
               b = true;
               break;
             }
         }

        if(b){
            int size = v.size();
            for(int i=0;i<size;i++)
                mrk[v[i]] = 0;
            cnt++;
        }

     }
     cout<<cnt<<endl;
    

    return 0; 
}

