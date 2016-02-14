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
int m,s;
int path[1010],path2[1010];
void min_solve(int idx,int sum){    
    if(idx == 0)    return;

    for(int i=0;i<=9;i++){
        if(i + (idx-1)*9 >= sum){
            path[idx] = i;
            min_solve(idx-1,sum-i);
            break;
        }
    }
}

void max_solve(int idx,int sum){    
    if(idx == 0)    return;

    for(int i=9;i>=0;i--){
        if(i <= sum){
            path2[idx] = i;
            max_solve(idx-1,sum-i);
            break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>s;
    if(m == 1 && s== 0){
        cout<<"0 0"<<endl;
        return 0;
    }

    for(int i=1;i<=9;i++){
        if(i + (m-1)*9 >= s){
            path[m] = i;
            min_solve(m-1,s-i);
            break;
        }
    }
    
    int ans = 0;
    for(int i=m;i>=1;i--)
        ans += path[i];
    
    if(ans != s){
        cout<<"-1 -1"<<endl;
        return 0;
    }

    for(int i=m;i>=1;i--)
        cout<<path[i];
    cout<<" ";

    for(int i=9;i>=1;i--){
        if(i <= s){
            path2[m] = i;
            max_solve(m-1,s-i);
            break;
        }
    }

    ans = 0;
    for(int i=m;i>=1;i--)
        ans += path2[i];

    if(ans != s){
        for(int i=m;i>=1;i--)
            cout<<path[i];
        return 0;
    }

    for(int i=m;i>=1;i--)
        cout<<path2[i];

    return 0; 
}

